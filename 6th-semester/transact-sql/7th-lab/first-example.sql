CREATE PROC Production.LongLeadProducts
AS
	SELECT Name, ProductNumber
	FROM Production.Product
	WHERE DaysToManufacture >= 1
GO

EXEC Production.LongLeadProducts

ALTER PROC Production.LongLeadProducts
AS
	SELECT Name, ProductNumber, DaysToManufacture
	FROM Production.Product
	WHERE DaysToManufacture >= 1
	ORDER BY DaysToManufacture DESC, Name
GO

EXEC Production.LongLeadProducts

DROP PROC Production.LongLeadProducts