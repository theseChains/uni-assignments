CREATE FUNCTION Sales.SumSold(@ProductID int) RETURNS int
AS
BEGIN
	DECLARE @ret int
	SELECT @ret = SUM(OrderQty)
	FROM Sales.SalesOrderDetail WHERE ProductID = @ProductID
	IF (@ret IS NULL)
		SET @ret = 0
	RETURN @ret
ENDSELECT ProductID, Name, Sales.SumSold(ProductID) AS SumSold
FROM Production.Product