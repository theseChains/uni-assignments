-- SELECT * FROM stars;
-- SELECT * FROM galaxies;
-- SELECT * FROM constellations;
-- SELECT * FROM spectral_classes;


SELECT
	stars.name AS star_name,
	galaxies.name AS galaxy_name,
	spectral_classes.name AS spectral_class
FROM stars
JOIN galaxies ON galaxies.id = stars.galaxy_id
JOIN spectral_classes ON spectral_classes.id = stars.spectral_class_id
WHERE stars.spectral_class_id != (SELECT id FROM spectral_classes WHERE name = 'M')
ORDER BY star_name, galaxy_name;


SELECT
	stars.name AS star_name,
	constellations.name AS constellation_name,
	constellations.abbreviation AS constellation_abbreviation,
	galaxies.type AS galaxy_type
FROM stars
JOIN constellations ON constellations.id = stars.constellation_id
JOIN galaxies ON galaxies.id = stars.galaxy_id
WHERE stars.luminosity > 0.0 AND galaxies.type IN ('Spiral', 'Elliptical')
ORDER BY star_name, constellation_name, constellation_abbreviation;


SELECT
	diameter AS diameter_of_group,
	AVG(distance_from_earth) AS average_distance_from_earth,
	SUM(mass) AS total_mass,
	SUM(number_of_stars) AS total_number_of_stars
FROM galaxies
GROUP BY galaxies.diameter
ORDER BY diameter_of_group, average_distance_from_earth, total_mass;


SELECT
	stars.color AS star_color,
	COUNT(*) AS number_of_stars,
	AVG(stars.distance_from_earth) AS average_distance_from_earth,
	AVG(stars.temperature) AS average_star_temperature,
	AVG(stars.age) AS average_star_age,
	AVG(constellations.area) AS average_constellation_area,
	spectral_classes.typical_size AS typical_size
FROM stars
JOIN spectral_classes ON spectral_classes.id = stars.spectral_class_id
JOIN constellations ON constellations.id = stars.constellation_id
WHERE constellations.area > 500.0
GROUP BY stars.color, spectral_classes.typical_size
HAVING AVG(stars.age) >= 5000000.0
ORDER BY star_color, number_of_stars DESC;


SELECT
	stars.name AS star_name,
	spectral_classes.name AS spectral_class_name,
	spectral_classes.luminosity_class AS luminosity_class,
	large_galaxies.name AS galaxy_name,
	large_galaxies.diameter AS galaxy_diameter,
	constellations.name AS constellation_name,
	constellations.area AS constellation_area
FROM stars
JOIN spectral_classes ON spectral_classes.id = stars.spectral_class_id
JOIN (SELECT id, name, diameter FROM galaxies WHERE diameter >= 50000.0) AS large_galaxies
	ON large_galaxies.id = stars.galaxy_id
JOIN constellations ON constellations.id = stars.constellation_id
WHERE spectral_classes.luminosity_class IN ('III', 'IV', 'V') AND
	  spectral_classes.name IN ('M', 'A') AND
	  LEN(constellations.name) BETWEEN 3 AND 8
ORDER BY star_name, spectral_class_name, galaxy_name, galaxy_diameter, constellation_name;