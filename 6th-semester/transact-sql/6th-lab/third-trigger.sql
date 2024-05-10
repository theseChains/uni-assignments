SELECT * FROM galaxies;
SELECT * FROM stars;

CREATE TRIGGER trg_UpdateTotalStarsInGalaxy
ON stars
AFTER INSERT, DELETE
AS
BEGIN
    -- update total_stars in galaxies table for inserted stars
    UPDATE g
    SET g.number_of_stars = g.number_of_stars + 1
    FROM galaxies g
    JOIN inserted i ON g.id = i.galaxy_id;

    -- update total_stars in galaxies table for deleted stars
    UPDATE g
    SET g.number_of_stars = g.number_of_stars - 1
    FROM galaxies g
    JOIN deleted d ON g.id = d.galaxy_id;
END;

DROP TRIGGER trg_UpdateTotalStarsInGalaxy;

SELECT * FROM galaxies;

INSERT INTO stars (name, constellation_id, galaxy_id, spectral_class_id, distance_from_earth, temperature, luminosity, mass, radius, age, color, image_url, description)
VALUES ('new star', 2, 3, 3, 234, 234, 23432, 12, 234, 23535, 'red', 'some_url', 'descccrr');

SELECT * FROM galaxies;

DELETE FROM stars WHERE id = (SELECT MAX(id) FROM stars);

SELECT * FROM galaxies;