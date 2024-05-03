SELECT ProductID, UnitPrice
FROM Sales.SalesOrderDetail
WHERE ProductID < 770
ORDER BY ProductID;

-- �������� ������������������� ������� � ������� Sales.SalesOrderDetail ��� ������� ProductID
CREATE NONCLUSTERED INDEX IX_SalesOrderDetail_ProductID ON Sales.SalesOrderDetail (ProductID)
INCLUDE (UnitPrice);

-- ���� ������ IX_SalesOrderDetail_ProductID ����������, �� ��� �������
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