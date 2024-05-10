CREATE TRIGGER [delCustomer] ON [Sales].[Customer]
AFTER DELETE AS
BEGIN
	SET NOCOUNT ON;
	EXEC master.xp_sendmail
	@recipients=N'SalesManagers@Adventure-Works.com',
	@message = N'Customers have been deleted!!';
END;