DECLARE @xmlDoc XML;

SET @xmlDoc = '
<InvoiceList xmlns="http://schemas.adventure-works.com/InvoiceList">
    <Invoice InvoiceNo="1" Amount="100.00" Customer="Customer A" />
    <Invoice InvoiceNo="2" Amount="200.00" Customer="Customer B" />
</InvoiceList>';

SELECT @xmlDoc AS XMLData;

SET @xmlDoc.modify('declare default element namespace "http://schemas.adventure-works.com/InvoiceList";
    insert element salesperson {"Alice"} as first into (/InvoiceList/Invoice)[1]');

SELECT @xmlDoc AS UpdatedXMLData;