CREATE UNIQUE NONCLUSTERED INDEX IX_Galaxies_Name_Diameter ON galaxies (name)
INCLUDE (diameter);

CREATE NONCLUSTERED INDEX IX_Galaxies_Type_RowLocks ON galaxies (type)
WITH (ALLOW_ROW_LOCKS = ON);

CREATE UNIQUE NONCLUSTERED INDEX IX_Stars_Name ON stars (name)
WITH (FILLFACTOR = 80, PAD_INDEX = ON);

CREATE NONCLUSTERED INDEX IX_Stars_Constellation_ID ON stars (constellation_id);

CREATE NONCLUSTERED INDEX IX_Stars_Galaxy_ID ON stars (galaxy_id);

CREATE UNIQUE NONCLUSTERED INDEX IX_Constellations_Name ON constellations (name);

EXEC sp_helpindex stars;
EXEC sp_helpindex galaxies;
EXEC sp_helpindex constellations;
EXEC sp_helpindex spectral_classes;
