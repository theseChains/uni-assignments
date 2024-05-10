ALTER PROC Production.LongLeadProducts
 @MinimumLength int = 1
AS
	IF (@MinimumLength < 0)
	BEGIN
		RAISERROR('Invalid lead time.', 14, 1)
		RETURN
	END
	
	SELECT Name, ProductNumber, DaysToManufacture
	FROM Production.Product
	WHERE DaysToManufacture >= 1
	ORDER BY DaysToManufacture DESC, Name
GO

EXEC Production.LongLeadProducts @MinimumLength=4EXEC Production.LongLeadProducts 4