CREATE TRIGGER [insrtWorkOrder] ON [Production].[WorkOrder]
AFTER INSERT AS
BEGIN
	SET NOCOUNT ON;
	INSERT INTO [Production].[TransactionHistory]
	(
	[ProductID], [ReferenceOrderID], [TransactionType], [TransactionDate], [Quantity], [ActualCost]
	)
	SELECT inserted.[ProductID], inserted.[WorkOrderID], 'W', GETDATE(), inserted.[OrderQty], 0
	FROM inserted;
END;

SELECT * FROM Production.WorkOrder;

INSERT INTO Production.WorkOrder (ProductID, OrderQty, ScrappedQty, StartDate, EndDate, DueDate, ScrapReasonID, ModifiedDate)
VALUES (777, 3, 0, GETDATE(), GETDATE(), GETDATE(), 10, GETDATE());

SELECT * FROM Production.TransactionHistory ORDER BY TransactionDate DESC;