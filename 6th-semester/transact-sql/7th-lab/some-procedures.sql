CREATE PROCEDURE GetTotalStarCount
AS
BEGIN
    SELECT COUNT(*) AS TotalStarCount FROM stars;
END;

EXEC GetTotalStarCount;


CREATE PROCEDURE GetStarsInConstellation
    @ConstellationId INT
AS
BEGIN
    SELECT name FROM stars WHERE constellation_id = @ConstellationId;
END;

EXEC GetStarsInConstellation @ConstellationId = 2;
EXEC GetStarsInConstellation 3;


CREATE PROCEDURE InsertStar
    @Name NVARCHAR(100),
    @GalaxyId INT,
    @ConstellationId INT,
    @SpectralClassId INT
AS
BEGIN
    BEGIN TRY
        INSERT INTO stars (name, galaxy_id, constellation_id, spectral_class_id)
        VALUES (@Name, @GalaxyId, @ConstellationId, @SpectralClassId);
        SELECT 'Star inserted successfully.' AS Message;
    END TRY
    BEGIN CATCH
        SELECT ERROR_MESSAGE() AS ErrorMessage;
    END CATCH;
END;

SELECT * FROM stars;
EXEC InsertStar @Name = 'Star1', @GalaxyId = 2, @ConstellationId = 2, @SpectralClassId = 1;
SELECT * FROM stars;

EXEC InsertStar @Name = 'Star1', @GalaxyId = 999, @ConstellationId = 888, @SpectralClassId = 1;


CREATE PROCEDURE AddGalaxy
    @Name NVARCHAR(50),
    @Type NVARCHAR(50),
    @GalaxyID INT OUTPUT
AS
BEGIN
    INSERT INTO galaxies (name, type)
    VALUES (@Name, @Type);
    SET @GalaxyID = SCOPE_IDENTITY();
END;

DECLARE @NewGalaxyID INT;
EXEC AddGalaxy @Name = 'New Galaxy', @Type = 'Spiral', @GalaxyID = @NewGalaxyID OUTPUT;
SELECT @NewGalaxyID AS NewGalaxyID;


DROP PROCEDURE GetTotalStarCount;
DROP PROCEDURE GetStarsInConstellation;
DROP PROCEDURE InsertStar;
DROP PROCEDURE AddGalaxy;