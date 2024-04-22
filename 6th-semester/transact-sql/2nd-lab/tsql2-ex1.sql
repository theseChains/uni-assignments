DECLARE @idoc int;
DECLARE @xmlDoc XML;

SET @xmlDoc = '
<Customer CustomerID="1" CustomerType="S">
    <Order SalesOrderID="43860" Status="5" OrderDate="2001-08-01T00:00:00">
        <OrderDetail ProductID="761" Quantity="2"/>
        <OrderDetail ProductID="770" Quantity="1"/>
    </Order>
</Customer>';

EXEC sp_xml_preparedocument @idoc OUTPUT, @xmlDoc;

SELECT *
FROM OPENXML (@idoc, '/Customer/Order/OrderDetail')
WITH (ProductID int, Quantity int)

EXEC sp_xml_removedocument @idoc;
