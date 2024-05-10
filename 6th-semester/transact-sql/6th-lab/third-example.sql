CREATE TRIGGER [updtProductReview] ON [Production].[ProductReview]
AFTER UPDATE NOT FOR REPLICATION AS
BEGIN
	SET NOCOUNT ON;
	UPDATE [Production].[ProductReview]
	SET [Production].[ProductReview].[ModifiedDate] = GETDATE()
	FROM inserted
	WHERE inserted.[ProductReviewID] = [Production].[ProductReview].[ProductReviewID];
END;

SELECT * FROM Production.ProductReview;

UPDATE Production.ProductReview SET ProductID = 777 WHERE ProductReviewID = 1;

SELECT * FROM Production.ProductReview;