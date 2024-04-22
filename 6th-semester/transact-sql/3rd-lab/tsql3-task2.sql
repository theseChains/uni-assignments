DECLARE @xmlData AS XML;

SELECT @xmlData = (
    SELECT galaxiesXml.query('.')
    FROM galaxies
    FOR XML PATH(''), ROOT('GalaxyXmlData')
);

SELECT @xmlData AS galaxyXmlData;

SET @xmlData.modify('insert <Galaxy>some galaxy</Galaxy>
					as last into (/GalaxyXmlData)[1]');

SELECT @xmlData AS DataAfterInsert;

SET @xmlData.modify('replace value of (/GalaxyXmlData/Galaxy/name/text())[1]
					with "other name"');

SELECT @xmlData AS DataAfterReplace;

SET @xmlData.modify('delete (/GalaxyXmlData/Galaxy)[4]');

SELECT @xmlData AS DataAfterDelete;
