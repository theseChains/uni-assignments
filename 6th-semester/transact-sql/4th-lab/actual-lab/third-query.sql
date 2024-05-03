SELECT person.FirstName, person.MiddleName, person.LastName
FROM Person.Person person
LEFT JOIN Person.Password passwd ON passwd.BusinessEntityID = person.BusinessEntityID
WHERE person.MiddleName IS NOT NULL;


-- создание некластеризованного индекса в таблице Person.Person для столбца MiddleName
CREATE NONCLUSTERED INDEX IX_Person_MiddleName_FirstName_LastName ON Person.Person (MiddleName)
INCLUDE (FirstName, LastName);

-- если этот индекс существует, то удаляем его
IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('Person.Person') 
    AND name = 'IX_Person_MiddleName_FirstName_LastName'
)
BEGIN
    DROP INDEX IX_Person_MiddleName_FirstName_LastName ON Person.Person;
END

EXEC sp_helpindex [Person.Person];