CREATE TABLE InvoicesXMLData (
    InvoiceID INT PRIMARY KEY,
    StoreID INT,
    xmlData XML
);

INSERT INTO InvoicesXMLData (InvoiceID, StoreID, xmlData)
VALUES
    (1, 292, '<InvoiceList>
                <Invoice InvoiceNo="1001" Amount="500.00" Customer="Customer A" />
                <Invoice InvoiceNo="1002" Amount="750.00" Customer="Customer B" />
                <Invoice InvoiceNo="1003" Amount="300.00" Customer="Customer C" />
            </InvoiceList>'),
    (2, 294, '<InvoiceList>
                <Invoice InvoiceNo="2001" Amount="600.00" Customer="Customer D" />
                <Invoice InvoiceNo="2002" Amount="900.00" Customer="Customer E" />
                <Invoice InvoiceNo="2003" Amount="400.00" Customer="Customer F" />
            </InvoiceList>');

SELECT s.Name AS StoreName,
       x.xmlData.query('
           <Invoices>
               <Store>{sql:column("s.Name")}</Store>
               {
                   for $i in /InvoiceList/Invoice
                   return $i
               }
           </Invoices>'
       ) AS InvoicesWithStoreName
FROM Sales.Store s
JOIN InvoicesXMLData x ON s.BusinessEntityID = x.StoreID;

DROP TABLE InvoicesXMLData;