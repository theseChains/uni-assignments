IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('galaxies') 
    AND name = 'IX_Galaxies_Name_Diameter'
)
BEGIN
    DROP INDEX IX_Galaxies_Name_Diameter ON galaxies;
END

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('galaxies') 
    AND name = 'IX_Galaxies_Type_RowLocks'
)
BEGIN
    DROP INDEX IX_Galaxies_Type_RowLocks ON galaxies;
END

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('stars') 
    AND name = 'IX_Stars_Name'
)
BEGIN
    DROP INDEX IX_Stars_Name ON stars;
END

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('stars') 
    AND name = 'IX_Stars_Constellation_ID'
)
BEGIN
    DROP INDEX IX_Stars_Constellation_ID ON stars;
END

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('stars') 
    AND name = 'IX_Stars_Galaxy_ID'
)
BEGIN
    DROP INDEX IX_Stars_Galaxy_ID ON stars;
END

IF EXISTS (
    SELECT 1 
    FROM sys.indexes 
    WHERE object_id = OBJECT_ID('constellations') 
    AND name = 'IX_Constellations_Name'
)
BEGIN
    DROP INDEX IX_Constellations_Name ON constellations;
END
