CREATE TABLE InvoicesXMLData (
    id INT PRIMARY KEY,
    xmlData XML
);

INSERT INTO InvoicesXMLData (id, xmlData)
VALUES
    (1, '<InvoiceList>
            <Invoice InvoiceNo="1001" Amount="500.00" Customer="Customer A" />
            <Invoice InvoiceNo="1002" Amount="750.00" Customer="Customer B" />
            <Invoice InvoiceNo="1003" Amount="300.00" Customer="Customer C" />
         </InvoiceList>');

SELECT xmlData.query('
    <InvoiceNumbers>
    {
        for $i in /InvoiceList/Invoice
        return <InvoiceNo>{number($i/@InvoiceNo)}</InvoiceNo>
    }
    </InvoiceNumbers>'
) AS ExtractedInvoiceNumbers
FROM InvoicesXMLData;

SELECT xmlData.value('(/InvoiceList/Invoice/@InvoiceNo)[3]', 'int') AS ExtractedInvoiceNumber
FROM InvoicesXMLData;

SELECT xmlData.exist('/InvoiceList/Invoice[@InvoiceNo=1000]') AS InvoiceNumberExists
FROM InvoicesXMLData;

SELECT xmlData.exist('/InvoiceList/Invoice[@InvoiceNo=1002]') AS InvoiceNumberExists
FROM InvoicesXMLData;

DROP TABLE InvoicesXMLData;
