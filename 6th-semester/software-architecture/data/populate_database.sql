-- psql:polyclinic-conn

INSERT INTO login_data (login, password)
VALUES
    ('admin', 'password'),
    ('registrator', 'reg'),
    ('doctor', 'doc');

SELECT * FROM login_data;

INSERT INTO administrators (login_data_id, last_name, first_name, middle_name, phone_number)
VALUES
    (1, 'Ivanov', 'Ivan', 'Ivanovich', '89374391099');

INSERT INTO registrators (login_data_id, last_name, first_name, middle_name, phone_number)
VALUES
    (2, 'Alekseev', 'Aleksey', 'Alekseevich', '89375648877');

INSERT INTO doctors (login_data_id, last_name, first_name, middle_name, phone_number, specialization, cabinet_number)
VALUES
    (3, 'Andreev', 'Andrey', 'Andreevich', '83435678998', 'терапевт', 12);

INSERT INTO registrators (login_data_id, last_name, first_name, middle_name, phone_number)
VALUES
    (1, 'Alekseev', 'Aleksey', 'Alekseevich', '89375648877');

SELECT * FROM doctors;
SELECT * FROM administrators;
SELECT * FROM registrators;
