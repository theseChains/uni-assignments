CREATE DATABASE Astronomy

USE Astronomy

CREATE TABLE galaxies (
    id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(255) NOT NULL,
    type NVARCHAR(50),
    distance_from_earth DECIMAL(15, 2),
    diameter DECIMAL(15, 2),
    mass DECIMAL(15, 2),
    number_of_stars BIGINT,
    luminosity FLOAT,
    image_url NVARCHAR(255),
    description TEXT
);

CREATE TABLE constellations (
    id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(255) NOT NULL,
    abbreviation NVARCHAR(10),
    area DECIMAL(10, 2),
    brightest_star NVARCHAR(255),
    number_of_stars INT,
    description TEXT,
    image_url NVARCHAR(255),
    short_description TEXT
);

CREATE TABLE spectral_classes (
    id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(50) NOT NULL,
    temperature_range NVARCHAR(50),
    color NVARCHAR(50),
    luminosity_class NVARCHAR(10),
    typical_size NVARCHAR(50),
    description TEXT
);

CREATE TABLE stars (
    id INT PRIMARY KEY IDENTITY(1,1),
    name NVARCHAR(255) NOT NULL,
    constellation_id INT FOREIGN KEY REFERENCES constellations(id),
    galaxy_id INT FOREIGN KEY REFERENCES galaxies(id),
    spectral_class_id INT FOREIGN KEY REFERENCES spectral_classes(id),
    distance_from_earth DECIMAL(10, 2),
    temperature INT,
    luminosity DECIMAL(10, 2),
    mass DECIMAL(10, 2),
    radius DECIMAL(10, 2),
    age INT,
    color NVARCHAR(50),
    image_url NVARCHAR(255),
    description TEXT
);

INSERT INTO constellations (name, abbreviation, area, brightest_star, number_of_stars, description, image_url, short_description)
VALUES
    ('Ursa Major', 'UMa', 1279.66, 'Dubhe', 7, 'Ursa Major is a prominent northern constellation.', 'ursa_major.jpg', 'The Great Bear'),
    ('Cassiopeia', 'Cas', 598.71, 'Gamma Cassiopeiae', 5, 'Cassiopeia is a prominent constellation in the northern sky.', 'cassiopeia.jpg', 'The Queen'),
    ('Leo', 'Leo', 947.35, 'Regulus', 6, 'Leo is one of the zodiacal constellations.', 'leo.jpg', 'The Lion');

INSERT INTO galaxies (name, type, distance_from_earth, diameter, mass, number_of_stars, luminosity, image_url, description)
VALUES
    ('Whirlpool Galaxy', 'Spiral', 31e6, 70e3, 2.4e11, 1e11, 2.5e38, 'whirlpool_galaxy.jpg', 'The Whirlpool Galaxy is an interacting grand-design spiral galaxy.'),
    ('Triangulum Galaxy', 'Spiral', 3e6, 50e3, 1.5e11, 5e10, 1.8e38, 'triangulum_galaxy.jpg', 'The Triangulum Galaxy is the third-largest galaxy in the Local Group.'),
    ('Sombrero Galaxy', 'Spiral', 29e6, 50e3, 8.2e10, 1e10, 1e38, 'sombrero_galaxy.jpg', 'The Sombrero Galaxy is known for its bright nucleus and large central bulge.');

INSERT INTO spectral_classes (name, temperature_range, color, luminosity_class, typical_size, description)
VALUES
    ('M', '2,400 - 3,800 K', 'Red', 'III', 'Medium', 'M-type stars are cooler and often red in color.'),
    ('B', '10,000 - 30,000 K', 'Blue-White', 'V', 'Medium', 'B-type stars are hot and emit blue-white light.'),
    ('A', '7,500 - 10,000 K', 'White', 'IV', 'Medium', 'A-type stars are typically white and luminous.');

INSERT INTO stars (name, constellation_id, galaxy_id, spectral_class_id, distance_from_earth, temperature, luminosity, mass, radius, age, color, image_url, description)
VALUES
    ('Betelgeuse', 2, 2, 3, 427, 3500, 100000, 15, 600, 8e6, 'Red', 'betelgeuse.jpg', 'Betelgeuse is a red supergiant and one of the largest known stars.'),
    ('Alpha Centauri A', 3, 3, 1, 4.37, 5790, 1.52, 1.1, 1.22, 6e6, 'Yellow', 'alpha_centauri_A.jpg', 'Alpha Centauri A is a Sun-like star.'),
    ('Proxima Centauri', 3, 3, 2, 4.24, 3042, 0.00005, 0.12, 0.141, 5e6, 'Red', 'proxima_centauri.jpg', 'Proxima Centauri is the closest known star to the Sun.');

SELECT * FROM stars
SELECT * FROM constellations
SELECT * FROM galaxies
SELECT * FROM spectral_classes

-- RAW
SELECT
    Stars.id AS StarID,
    Stars.name AS StarName,
    Constellations.name AS ConstellationName,
    Constellations.abbreviation AS ConstellationAbbreviation,
    SpectralClasses.name AS SpectralClassName,
    SpectralClasses.temperature_range AS SpectralClassTemperatureRange
FROM
    stars AS Stars
JOIN
    constellations AS Constellations ON Stars.constellation_id = Constellations.id
JOIN
    spectral_classes AS SpectralClasses ON Stars.spectral_class_id = SpectralClasses.id
ORDER BY
    Stars.id
FOR XML RAW('StarData'),ELEMENTS, ROOT('SpaceData');

-- PATH
SELECT
    Stars.id AS '@StarID',
    Stars.name AS '@StarName',
    Constellations.name AS 'Constellation/ConstellationName',
    Constellations.abbreviation AS 'Constellation/ConstellationAbbreviation',
    SpectralClasses.name AS 'SpectralClass/@SpectralClassName',
    SpectralClasses.temperature_range AS 'SpectralClass/@SpectralClassTemperatureRange'
FROM
    stars AS Stars
JOIN
    constellations AS Constellations ON Stars.constellation_id = Constellations.id
JOIN
    spectral_classes AS SpectralClasses ON Stars.spectral_class_id = SpectralClasses.id
ORDER BY
    Stars.id
FOR XML PATH('StarData'), ROOT('SpaceData');

-- AUTO
SELECT
    Stars.id,
    Stars.name,
    Constellations.name AS ConstellationName,
    Constellations.abbreviation AS ConstellationAbbreviation,
    SpectralClasses.name AS SpectralClassName,
    SpectralClasses.temperature_range AS SpectralClassTemperatureRange
FROM
    stars AS Stars
JOIN
    constellations AS Constellations ON Stars.constellation_id = Constellations.id
JOIN
    spectral_classes AS SpectralClasses ON Stars.spectral_class_id = SpectralClasses.id
ORDER BY
    Stars.id
FOR XML AUTO, ELEMENTS, ROOT('SpaceData');

-- EXPLICIT
SELECT
    1 AS Tag,
    NULL AS Parent,
    Stars.id AS [SpaceData!1!StarID],
    Stars.name AS [SpaceData!1!StarName],
    NULL AS [Constellations!2!ConstellationName],
    NULL AS [Constellations!2!ConstellationAbbreviation]
FROM
    stars AS Stars
UNION ALL
SELECT
    2 AS Tag,
    1 AS Parent,
    Stars.id AS [SpaceData!1!StarID],
    NULL,
    Constellations.name AS [Constellations!2!ConstellationName],
    Constellations.abbreviation AS [Constellations!2!ConstellationAbbreviation]
FROM
    constellations AS Constellations
INNER JOIN
    stars AS Stars ON Stars.constellation_id = Constellations.id
ORDER BY
    [SpaceData!1!StarID],
    [Constellations!2!ConstellationName]
FOR XML EXPLICIT, ROOT('SpaceData');
