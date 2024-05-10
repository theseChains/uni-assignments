CREATE VIEW StarRadiusView
AS
SELECT 
    s.id AS StarID,
    s.name AS StarName,
	s.radius AS StarRadius,
    g.name AS GalaxyName,
    sc.name AS SpectralClassName,
    c.name AS ConstellationName
FROM stars s
JOIN galaxies g ON s.galaxy_id = g.id
JOIN spectral_classes sc ON s.spectral_class_id = sc.id
JOIN constellations c ON s.constellation_id = c.id
WHERE s.radius > 1.0;

SELECT * FROM StarSummaryView;

DROP VIEW StarSummaryView;


CREATE VIEW GalaxyAndStarMassView
AS
SELECT 
    g.id AS GalaxyID,
    g.name AS GalaxyName,
    g.mass AS TotalGalaxyMass,
	s.name AS StarName,
    s.mass AS StarMass,
    s.mass / g.mass AS StarToGalaxyMassRatio
FROM galaxies g
JOIN stars s ON g.id = s.galaxy_id;

SELECT * FROM GalaxyAndStarMassView;

DROP VIEW GalaxyAndStarMassView;


CREATE VIEW SpectralClassSummary AS
SELECT
    id AS SpectralClassID,
    name AS SpectralClassName,
	typical_size AS TypicalStarSize
FROM spectral_classes;

SELECT * FROM SpectralClassSummary;

DROP VIEW SpectralClassSummary;


CREATE VIEW StarWithSpectralClass AS
SELECT
    s.id AS StarID,
    s.name AS StarName,
    scs.SpectralClassName AS SpectralClassName
FROM stars s
JOIN SpectralClassSummary scs ON s.spectral_class_id = scs.SpectralClassID;

SELECT * FROM StarWithSpectralClass;

DROP VIEW StarWithSpectralClass;


SELECT * FROM sys.views;
EXEC sp_helptext 'StarWithSpectralClass'


SELECT
    OBJECT_NAME(object_id) AS DependentView
	FROM sys.sql_dependencies
WHERE referenced_major_id = OBJECT_ID(N'stars');

SELECT
    OBJECT_NAME(object_id) AS DependentView
	FROM sys.sql_dependencies
WHERE referenced_major_id = OBJECT_ID(N'galaxies');


SELECT * FROM stars;
SELECT * FROM galaxies;
SELECT * FROM spectral_classes;