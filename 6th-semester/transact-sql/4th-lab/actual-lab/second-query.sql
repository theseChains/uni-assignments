SELECT ProductID, UnitPrice
FROM Sales.SalesOrderDetail
WHERE ProductID < 770
ORDER BY ProductID;

-- создание некластеризованного индекса в таблице Sales.SalesOrderDetail для столбца ProductID
CREATE NONCLUSTERED INDEX IX_SalesOrderDetail_ProductID ON Sales.SalesOrderDetail (ProductID)
INCLUDE (UnitPrice);

-- если индекс IX_SalesOrderDetail_ProductID существует, то его удаляем
IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('Sales.SalesOrderDetail') 
    AND name = 'IX_SalesOrderDetail_ProductID'
)
BEGIN
    DROP INDEX IX_SalesOrderDetail_ProductID ON Sales.SalesOrderDetail;
END

EXEC sp_helpindex [Sales.SalesOrderDetail];