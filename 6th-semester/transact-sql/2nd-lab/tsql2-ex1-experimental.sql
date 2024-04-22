DECLARE @idoc int;
DECLARE @xmlDoc XML;

SELECT @xmlDoc = BulkColumn
FROM OPENROWSET(BULK 'ex-1-lab-2.xml', SINGLE_BLOB) AS x;

EXEC sp_xml_preparedocument @idoc OUTPUT, @xmlDoc;

SELECT *
FROM OPENXML (@idoc, '/Customer/Order/OrderDetail')
WITH (ProductID int, Quantity int)

EXEC sp_xml_removedocument @idoc;
