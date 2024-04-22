DECLARE @idoc int;
DECLARE @xmlDoc NVARCHAR(MAX);

SET @xmlDoc = '
<Customer xmlns="urn:AW_NS" xmlns:o="urn:AW_OrderNS"
	CustomerID="1" CustomerType="S">
		<o:Order SalesOrderID="43860" Status="5"
			OrderDate="2001-08-01T00:00:00">
				<o:OrderDetail ProductID="761" Quantity="2"/>
				<o:OrderDetail ProductID="770" Quantity="1"/>
		</o:Order>
</Customer>';

EXEC sp_xml_preparedocument @idoc OUTPUT, @xmlDoc,
'<ROOT xmlns:rootNS="urn:AW_NS" xmlns:orderNS="urn:AW_OrderNS" />'

SELECT *
FROM OPENXML (@idoc,
'/rootNS:Customer/orderNS:Order/orderNS:OrderDetail')
WITH (OrderID int '../@SalesOrderID',
CustomerID int '../../@CustomerID',
OrderDate datetime '../@OrderDate',
ProdID int '@ProductID',
Quantity int)
