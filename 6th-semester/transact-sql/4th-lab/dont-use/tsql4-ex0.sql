IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('HumanResources.Employee') 
    AND name = 'AK_Employee_LoginID'
)
BEGIN
    DROP INDEX AK_Employee_LoginID ON HumanResources.Employee;
END

CREATE NONCLUSTERED INDEX AK_Employee_LoginID
ON HumanResources.Employee (LoginID ASC);
