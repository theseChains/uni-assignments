SELECT * FROM stars;

DROP VIEW NonYellowStarsView;

CREATE VIEW NonYellowStarsView
AS
SELECT 
    id AS StarID,
    name AS StarName,
    temperature AS StarTemperature,
	color AS StarColor
FROM stars
WHERE color != 'Yellow';

SELECT * FROM NonYellowStarsView;

SELECT MIN(StarTemperature) AS MinimumTemperature
FROM NonYellowStarsView;

SELECT * FROM NonYellowStarsView
ORDER BY StarTemperature ASC;

INSERT INTO NonYellowStarsView (StarName, StarTemperature, StarColor)
VALUES ('Wolf 359', 5500, 'Red');

INSERT INTO NonYellowStarsView (StarName, StarTemperature, StarColor)
VALUES ('Sun', 4500, 'Yellow');

DELETE FROM NonYellowStarsView WHERE StarID = 8;

UPDATE NonYellowStarsView SET StarTemperature = 3500 WHERE StarID = 6;
UPDATE NonYellowStarsView SET StarColor = 'Yellow' WHERE StarID = 6;


SELECT * FROM sys.views;
EXEC sp_helptext 'NonYellowStarsView'


ALTER VIEW NonYellowStarsView
AS
SELECT 
    id AS StarID,
    name AS StarName,
    temperature AS StarTemperature,
	color AS StarColor
FROM stars
WHERE color != 'Yellow'
WITH CHECK OPTION;

