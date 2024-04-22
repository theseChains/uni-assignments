DECLARE @xmlDoc XML;

SET @xmlDoc = '<InvoiceList xmlns="http://schemas.adventure-works.com/InvoiceList">
                    <Invoice>
                        <InvoiceNo>1001</InvoiceNo>
                        <Amount>500.00</Amount>
                        <Customer>Customer A</Customer>
                        <SalesPerson>Holly</SalesPerson>
                    </Invoice>
                </InvoiceList>';

SELECT @xmlDoc AS XMLData;

SET @xmlDoc.modify('declare default element namespace "http://schemas.adventure-works.com/InvoiceList";
                    replace value of (/InvoiceList/Invoice/SalesPerson/text())[1] with "Alice"');

SELECT @xmlDoc AS UpdatedXMLData;
