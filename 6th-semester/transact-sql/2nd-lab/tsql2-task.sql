DECLARE @xmlData XML = '
<Galaxy>
    <name>Andromeda Galaxy</name>
    <type>Spiral</type>
    <distance_from_earth>2540000</distance_from_earth>
    <diameter>220000</diameter>
    <mass>13200000000</mass>
    <number_of_stars>1230000000000</number_of_stars>
    <luminosity>3.4e38</luminosity>
    <image_url>andromeda_galaxy.jpg</image_url>
    <description>The Andromeda Galaxy is the nearest spiral galaxy to the Milky Way.</description>
</Galaxy>';

DECLARE @idoc int;

EXEC sp_xml_preparedocument @idoc OUTPUT, @xmlData;

INSERT INTO galaxies (name, type, distance_from_earth, diameter, mass, number_of_stars, luminosity, image_url, description)
SELECT name, type, distance_from_earth, diameter, mass, number_of_stars, luminosity, image_url, description
FROM OPENXML (@idoc, '/Galaxy')
WITH (
    name NVARCHAR(255) 'name',
    type NVARCHAR(50) 'type',
    distance_from_earth DECIMAL(15, 2) 'distance_from_earth',
    diameter DECIMAL(15, 2) 'diameter',
    mass DECIMAL(15, 2) 'mass',
    number_of_stars BIGINT 'number_of_stars',
    luminosity FLOAT 'luminosity',
    image_url NVARCHAR(255) 'image_url',
    description TEXT 'description'
);

EXEC sp_xml_removedocument @idoc;

SELECT * FROM galaxies;
