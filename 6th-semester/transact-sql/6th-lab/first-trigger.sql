SELECT * FROM stars;
SELECT * FROM galaxies;
SELECT * FROM constellations;
SELECT * FROM spectral_classes;

CREATE TRIGGER trg_PreventGalaxyDeletion
ON galaxies
INSTEAD OF DELETE
AS
BEGIN
    IF EXISTS (SELECT * FROM stars WHERE galaxy_id IN (SELECT id FROM deleted))
    BEGIN
        RAISERROR('Cannot delete galaxies with associated stars', 16, 1);
        ROLLBACK TRANSACTION;
    END
    ELSE
    BEGIN
        DELETE FROM galaxies WHERE id IN (SELECT id FROM deleted);
    END
END;

DROP TRIGGER trg_PreventGalaxyDeletion;

DELETE FROM galaxies WHERE id = 2;
