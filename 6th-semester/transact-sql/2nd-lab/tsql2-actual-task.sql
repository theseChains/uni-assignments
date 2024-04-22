SELECT * FROM galaxies;

ALTER TABLE galaxies DROP COLUMN galaxiesXml;

ALTER TABLE galaxies ADD galaxiesXml XML;

UPDATE galaxies
SET galaxies.galaxiesXml = (
	SELECT * FROM galaxies FOR XML RAW('Galaxy'), ROOT('Galaxies')
);

DECLARE @xmlData AS XML;
DECLARE @hdoc AS INT;

SELECT @xmlData = galaxies.galaxiesXml FROM galaxies;
EXEC sp_xml_preparedocument @hdoc OUTPUT, @xmlData;

SELECT * FROM OPENXML(@hdoc, '/Galaxies/Galaxy', 1)
WITH (
	id INT '@id',
    name NVARCHAR(255) '@name',
    type NVARCHAR(50) '@type',
    distance_from_earth DECIMAL(15, 2) '@distance_from_earth',
    diameter DECIMAL(15, 2) '@diameter',
    mass DECIMAL(15, 2) '@mass',
    number_of_stars BIGINT '@number_of_stars',
    luminosity FLOAT '@luminosity',
    image_url NVARCHAR(255) '@image_url',
    description TEXT '@description'
);

EXEC sp_xml_removedocument @hdoc;