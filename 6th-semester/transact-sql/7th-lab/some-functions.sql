CREATE FUNCTION GetAverageStarsPerGalaxy()
RETURNS FLOAT
AS
BEGIN
    DECLARE @Average FLOAT;
    SELECT @Average = AVG(number_of_stars) FROM galaxies;
    RETURN @Average;
END;

SELECT dbo.GetAverageStarsPerGalaxy() AS AverageStarsPerGalaxy;


CREATE FUNCTION StarsInConstellation
(
    @ConstellationId INT
)
RETURNS TABLE
AS
RETURN
(
    SELECT name
    FROM stars
    WHERE constellation_id = @ConstellationId
);

SELECT * FROM dbo.StarsInConstellation(2);

CREATE FUNCTION dbo.StarsInGalaxy
(
    @GalaxyName NVARCHAR(100)
)
RETURNS @Result TABLE
(
    Name NVARCHAR(100),
    SpectralClass NVARCHAR(50)
)
AS
BEGIN
    INSERT INTO @Result (Name, SpectralClass)
    SELECT s.name, sc.name
    FROM stars s
    INNER JOIN galaxies g ON s.galaxy_id = g.id
    INNER JOIN spectral_classes sc ON s.spectral_class_id = sc.id
    WHERE g.name = @GalaxyName;

    RETURN;
END;

SELECT * FROM dbo.StarsInGalaxy('Whirlpool Galaxy');


DROP FUNCTION GetAverageStarsPerGalaxy;
DROP FUNCTION StarsInConstellation;
DROP FUNCTION StarsInGalaxy;