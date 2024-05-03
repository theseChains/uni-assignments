SELECT
	SalesOrderID,
	SUM(UnitPrice) AS SumOfUnitPrices
FROM Sales.SalesOrderDetail
WHERE UnitPriceDiscount = 0.0
GROUP BY SalesOrderID, UnitPriceDiscount;

-- создание некластеризованного индекса 
CREATE NONCLUSTERED INDEX IX_SalesOrderDetail_UnitPriceDiscount ON Sales.SalesOrderDetail (UnitPriceDiscount)
INCLUDE (UnitPrice);

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('Sales.SalesOrderDetail') 
    AND name = 'IX_SalesOrderDetail_UnitPriceDiscount'
)
BEGIN
    DROP INDEX IX_SalesOrderDetail_UnitPriceDiscount ON Sales.SalesOrderDetail;
END

EXEC sp_helpindex [Sales.SalesOrderDetail];