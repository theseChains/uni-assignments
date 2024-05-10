CREATE TABLE dbo.TableWithKey (ColA int PRIMARY KEY, ColB int)
GO

CREATE PROCEDURE dbo.AddData @a int, @b int
AS
BEGIN TRY
	INSERT INTO TableWithKey VALUES (@a, @b)
END TRY
BEGIN CATCH
	SELECT ERROR_NUMBER() ErrorNumber, ERROR_MESSAGE() [Message]
END CATCH
GOEXEC dbo.AddData 1, 1
EXEC dbo.AddData 2, 2
EXEC dbo.AddData 1, 3

DROP TABLE dbo.TableWithKey;