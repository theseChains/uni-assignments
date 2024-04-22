DECLARE @xmlOrder xml

SET @xmlOrder = '<?xml version="1.0" ?>
	<Order OrderID="1000" OrderDate="2005-06-04">
		<LineItem ProductID="1" Price="2.99" Quantity="3" />
		<LineItem ProductID="2" Price="3.99" Quantity="1" />
	</Order>'

SELECT nCol.value('@ProductID', 'integer') ProductID,
		nCol.value('@Quantity', 'integer') Quantity
FROM @xmlOrder.nodes('/Order/LineItem') AS nTable(nCol)