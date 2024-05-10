CREATE TRIGGER [delEmployee] ON [HumanResources].[Employee]
INSTEAD OF DELETE NOT FOR REPLICATION AS
BEGIN
	SET NOCOUNT ON;
	DECLARE @DeleteCount int;
	SELECT @DeleteCount = COUNT(*) FROM deleted;
	IF @DeleteCount > 0
	BEGIN
		RAISERROR
		(N'Employees cannot be deleted. They can only be marked as not current.', -- Message
		10, -- Severity.
		1); -- State.
		-- Roll back any active or uncommittable transactions
		IF @@TRANCOUNT > 0
		BEGIN
			ROLLBACK TRANSACTION;
		END
	END;
END;

SELECT * FROM HumanResources.Employee;

DELETE FROM HumanResources.Employee WHERE BusinessEntityID = 5;