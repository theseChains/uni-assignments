SELECT
	ProductID,
	AVG(UnitPrice) AS AverageUnitPrice,
	AVG(LineTotal) AS AverageLineTotal
FROM Purchasing.PurchaseOrderDetail
WHERE ProductID BETWEEN 1 AND 700
GROUP BY ProductID
HAVING AVG(UnitPrice) > 5.0;

-- создание некластеризованного индекса в таблице Purchasing.PurchaseOrderDetail для столбца ProductID
CREATE NONCLUSTERED INDEX IX_Purchasing_ProductID_UnitPrice_LineTotal ON Purchasing.PurchaseOrderDetail (ProductID)
INCLUDE (UnitPrice, LineTotal)
WITH (FILLFACTOR = 90, PAD_INDEX = ON);

-- если существует, удаляем
IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('Purchasing.PurchaseOrderDetail') 
    AND name = 'IX_Purchasing_ProductID_UnitPrice_LineTotal'
)
BEGIN
    DROP INDEX IX_Purchasing_ProductID_UnitPrice_LineTotal ON Purchasing.PurchaseOrderDetail;
END

DROP INDEX IX_PurchaseOrderDetail_ProductID ON Purchasing.PurchaseOrderDetail;

EXEC sp_helpindex [Purchasing.PurchaseOrderDetail];