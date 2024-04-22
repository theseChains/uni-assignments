DECLARE @xmlData AS XML;
SET @xmlData = (
	SELECT galaxiesXml.query('.')
	FROM galaxies
	FOR XML PATH(''), ROOT('GalaxyXmlData')
);

SELECT @xmlData AS galaxyXmlData;

SELECT @xmlData.query('
	<Galaxies>
	{
		for $i in /GalaxyXmlData
		return <GalaxyName>{$i/name}</GalaxyName>
	}
	</Galaxies>'
) AS ExtractedGalaxyNames;

SELECT @xmlData.value('(/GalaxyXmlData/Galaxy/name)[2]','nvarchar(200)') AS GalaxyNameData;

SELECT @xmlData.exist('/GalaxyXmlData/Galaxy[diameter=70000.00]') AS GalaxyExistsData;
SELECT @xmlData.exist('/GalaxyXmlData/Galaxy[diameter=72]') AS GalaxyExistsData;