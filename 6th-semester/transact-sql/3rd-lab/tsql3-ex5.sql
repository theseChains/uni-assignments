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
                    delete (/InvoiceList/Invoice/SalesPerson)[1]');

SELECT @xmlDoc AS UpdatedXMLData;
