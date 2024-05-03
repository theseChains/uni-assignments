SELECT CustomerID, PersonID, StoreID, TerritoryID, AccountNumber
FROM Sales.Customer
WHERE TerritoryID IN (1, 2, 3, 4, 5, 6);

-- создание некластеризованного индекса
CREATE NONCLUSTERED INDEX IX_SalesCustomerID ON Sales.Customer (TerritoryID)
INCLUDE (PersonID, StoreID, AccountNumber);

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('Sales.Customer') 
    AND name = 'IX_SalesCustomerID'
)
BEGIN
    DROP INDEX IX_SalesCustomerID ON Sales.Customer;
END

EXEC sp_helpindex [Sales.Customer];