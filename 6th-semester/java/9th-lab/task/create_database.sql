CONNECT 'jdbc:derby://localhost:1527/databases/HomeLibrary;user=db_user;password=db_user;create=true';
CONNECT 'jdbc:derby://localhost:1527/databases/HomeLibrary;user=db_user;password=db_user';

CREATE TABLE BookLocation(id INT PRIMARY KEY, floor INT, shelf INT, rack INT);

CREATE TABLE BookInfo(id INT PRIMARY KEY, author_full_name VARCHAR(255), publication_title VARCHAR(255), publisher VARCHAR(255), year_of_publication INT, number_of_pages INT, year_of_writing INT, weight_in_grams INT);
