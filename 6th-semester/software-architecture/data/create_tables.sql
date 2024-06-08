-- psql:polyclinic-conn

CREATE TABLE login_data
(
    login_data_id SERIAL PRIMARY KEY,
    login VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL
);

CREATE TABLE doctors
(
    doctor_id SERIAL PRIMARY KEY,
    login_data_id INTEGER NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    middle_name VARCHAR(50),
    phone_number VARCHAR(20) NOT NULL
        CHECK (phone_number ~ '^[0-9]{10,15}$'),
    specialization VARCHAR(20) NOT NULL,
    cabinet_number INTEGER,

    FOREIGN KEY (login_data_id) REFERENCES login_data(login_data_id)
);

CREATE TABLE administrators
(
    administrator_id SERIAL PRIMARY KEY,
    login_data_id INTEGER NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    middle_name VARCHAR(50),
    phone_number VARCHAR(20) NOT NULL
        CHECK (phone_number ~ '^[0-9]{10,15}$'),

    FOREIGN KEY (login_data_id) REFERENCES login_data(login_data_id)
);

CREATE TABLE registrators
(
    registrator_id SERIAL PRIMARY KEY,
    login_data_id INTEGER NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    middle_name VARCHAR(50),
    phone_number VARCHAR(20) NOT NULL
        CHECK (phone_number ~ '^[0-9]{10,15}$'),

    FOREIGN KEY (login_data_id) REFERENCES login_data(login_data_id)
);

CREATE TABLE patients
(
    patient_id SERIAL PRIMARY KEY,
    last_name VARCHAR(50) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    middle_name VARCHAR(50),
    date_of_birth DATE NOT NULL,
    gender VARCHAR(7) NOT NULL
        CHECK (gender IN ('Мужской', 'Женский')),
    document_type VARCHAR(20),
    document_number VARCHAR(6) NOT NULL
        CHECK (document_number ~ '^[0-9]{6}$'),
    document_series VARCHAR(4) NOT NULL
        CHECK (document_series ~ '^[0-9]{4}$'),
    medical_insurance_number VARCHAR(16) NOT NULL
        CHECK (medical_insurance_number ~ '^[0-9]{16}$'),
    individual_insurance_number VARCHAR(14) NOT NULL
        CHECK (individual_insurance_number ~ '^[0-9]{3}-[0-9]{3}-[0-9]{3} [0-9]{2}$'),
    phone_number VARCHAR(20) NOT NULL
        CHECK (phone_number ~ '^[0-9]{10,15}$'),
    city VARCHAR(50),
    street VARCHAR(50),
    house_number INTEGER,
    apartment_number INTEGER
);

CREATE TABLE outpatient_cards
(
    outpatient_card_id SERIAL PRIMARY KEY,
    patient_id INTEGER NOT NULL,
    date_of_creation DATE NOT NULL,

    FOREIGN KEY (patient_id) REFERENCES patients(patient_id)
);

CREATE TABLE medical_history_records
(
    record_id SERIAL PRIMARY KEY,
    outpatient_card_id INTEGER NOT NULL,
    date_of_entry DATE NOT NULL,
    patient_complaints VARCHAR(255),
    diagnosis VARCHAR(255),
    treatment VARCHAR(255),
    medical_tests VARCHAR(255),
    doctors_notes VARCHAR(255),
    recipe VARCHAR(255),

    FOREIGN KEY (outpatient_card_id) REFERENCES outpatient_cards(outpatient_card_id)
);

CREATE TABLE doctor_slots
(
    doctor_slot_id SERIAL PRIMARY KEY,
    doctor_id INTEGER NOT NULL,
    date DATE NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL,
    status VARCHAR(8) NOT NULL CHECK (status IN ('Свободен', 'Занят')),

    FOREIGN KEY (doctor_id) REFERENCES doctors(doctor_id)
);

CREATE TABLE appointments
(
    appointment_id SERIAL PRIMARY KEY,
    slot_id INTEGER NOT NULL,
    outpatient_card_id INTEGER NOT NULL,
    patient_id INTEGER NOT NULL,
    doctor_id INTEGER NOT NULL,
    registrator_id INTEGER,

    FOREIGN KEY (slot_id) REFERENCES doctor_slots(doctor_slot_id),
    FOREIGN KEY (outpatient_card_id) REFERENCES outpatient_cards(outpatient_card_id),
    FOREIGN KEY (patient_id) REFERENCES patients(patient_id),
    FOREIGN KEY (doctor_id) REFERENCES doctors(doctor_id),
    FOREIGN KEY (registrator_id) REFERENCES registrators(registrator_id)
);

CREATE OR REPLACE FUNCTION check_unique_login_data_id() RETURNS TRIGGER AS $$
BEGIN
    IF EXISTS (
        SELECT 1 FROM doctors WHERE login_data_id = NEW.login_data_id
        UNION ALL
        SELECT 1 FROM administrators WHERE login_data_id = NEW.login_data_id
        UNION ALL
        SELECT 1 FROM registrators WHERE login_data_id = NEW.login_data_id
    ) THEN
        RAISE EXCEPTION 'login_data_id already exists for another user';
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER doctors_check_unique_login_data_id
BEFORE INSERT OR UPDATE ON doctors
FOR EACH ROW EXECUTE FUNCTION check_unique_login_data_id();

CREATE TRIGGER administrators_check_unique_login_data_id
BEFORE INSERT OR UPDATE ON administrators
FOR EACH ROW EXECUTE FUNCTION check_unique_login_data_id();

CREATE TRIGGER registrators_check_unique_login_data_id
BEFORE INSERT OR UPDATE ON registrators
FOR EACH ROW EXECUTE FUNCTION check_unique_login_data_id();
