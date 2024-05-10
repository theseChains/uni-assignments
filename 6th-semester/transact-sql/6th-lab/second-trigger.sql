CREATE TRIGGER trg_EnforceUniqueConstellationName
ON constellations
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM inserted i
        INNER JOIN constellations c ON i.name = c.name
        WHERE i.id <> c.id
    )
    BEGIN
        RAISERROR('Constellation name must be unique.', 16, 1);
        ROLLBACK TRANSACTION;
    END;
END;

DROP TRIGGER trg_EnforceUniqueConstellationName;

SELECT * FROM constellations;

INSERT INTO constellations (name, abbreviation, area, brightest_star, number_of_stars, description, image_url, short_description)
VALUES ('Ursa Major', 'UMa', 1280, 'Dubhe', 7, 'long description', 'image_url.jpg', 'short_description');