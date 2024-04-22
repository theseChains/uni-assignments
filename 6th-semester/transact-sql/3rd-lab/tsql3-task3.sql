DECLARE @xmlData AS XML;

SELECT @xmlData = (
    SELECT galaxiesXml.query('.')
    FROM galaxies
    FOR XML PATH(''), ROOT('GalaxyXmlData')
);

SELECT @xmlData AS galaxyXmlData;
SELECT nCol.value('(name/text())[1]', 'nvarchar(200)') GalaxyName,
        nCol.value('(type/text())[1]', 'nvarchar(200)') GalaxyType
FROM @xmlData.nodes('/GalaxyXmlData/Galaxy') AS nTable(nCol);
