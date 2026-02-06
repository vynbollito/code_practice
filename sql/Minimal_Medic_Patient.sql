-- Minimal Patient System -- 
-- This is my OracleDDL version for the Minimal Medic Patient System of the object-relational diagram.

-- DROP TYPES AND TABLES --
DROP TYPE location_t FORCE;
/
DROP TYPE duration_t FORCE;
/
DROP TYPE medicament_t FORCE;
/
DROP TYPE medicamentList_t FORCE;
/
DROP TYPE person_t FORCE;
/
DROP TYPE patient_t FORCE;
/
DROP TYPE doctor_t FORCE;
/
DROP TYPE doctorList_t FORCE;
/
DROP TYPE treatment_t FORCE;
/
DROP TYPE treatmentList_t FORCE;
/
DROP TYPE area_t FORCE;
/

DROP TABLE Treatment;
/
DROP TABLE Area;
/
DROP TABLE Person;
/
DROP TABLE Patient;
/
DROP TABLE Doctor;
/

 ------ TYPES ------
-- Create duration type. This definition tries to be a little more precise--
CREATE OR REPLACE TYPE duration_t AS OBJECT(
    dYears  INT,
    dMonth  INT,
    dWeeks  INT,
    dDays   INT
);
/

-- Create a medicament type --
CREATE OR REPLACE TYPE medicament_t AS OBJECT(
    mid          INT,         -- identifier of the medicine
    mName        VARCHAR(10), -- alias
    mVia         VARCHAR(10), -- tablet, syrup, inyection
    mCuantity    INT,         -- how much quantity
    mUnitMeasure VARCHAR(2)   -- ml or gr
);
/

-- Create an array of medicaments
CREATE OR REPLACE TYPE medicamentList_t AS VARRAY(10) OF medicament_t;
/

-- Create the location type --
CREATE OR REPLACE TYPE location_t AS OBJECT(
    tState      VARCHAR(15),
    tCity       VARCHAR(10),
    tStreet     VARCHAR(15),
    tNumber     INT,
    tZipCode    INT
);
/

-- Create the person type --
CREATE OR REPLACE TYPE person_t AS OBJECT(
    pid         INT,
    pFirstName  VARCHAR(15),
    pLastName   VARCHAR(15),
    pDob        DATE,
    pGender     CHAR
)NOT FINAL;
/

 -- Create person table --
CREATE TABLE Person OF person_t(
    pid         PRIMARY KEY,
    pFirstName  NOT NULL,
    pLastName   NOT NULL,
    pDob        NOT NULL,
    pGender     NOT NULL
);
/

-- Create the patient type and inherit from person_t --
CREATE OR REPLACE TYPE patient_t UNDER person_t(
    pInsurancePlan    VARCHAR(15)
    -- MEMBER FUNCTION getInsurancePlan RETURN ()
    -- pragma restrict_references(default, wnds, wnps))
);
/

-- Create the doctor type and also inherit from person_t --
CREATE OR REPLACE TYPE doctor_t UNDER person_t(
    dSpeciality         VARCHAR(10),
    dYearsExperience    INT,
    dSalary             INT -- not explicit on diagram but need for rule condition
    --
    -- pragma restrict_references(default, wnds, wnps))
);
/

-- Create an array of doctors
CREATE OR REPLACE TYPE doctorList_t AS VARRAY(50) OF doctor_t;
/   

-- Create the treatment type --
CREATE OR REPLACE TYPE treatment_t AS OBJECT(
  	-- tDate			DATE, -- for composite PK
    tDuration       duration_t,
    tMedicaments    medicamentList_t,
    tDescription    VARCHAR(30),
    prescribe       REF doctor_t,
    receives        REF patient_t
);
/

-- Create an array of treatments --
CREATE OR REPLACE TYPE treatmentList_t AS VARRAY(50) OF REF treatment_t;
/

 -- Create area type --
CREATE OR REPLACE TYPE area_t;
/

 -- Create area list  --
CREATE OR REPLACE TYPE areaList_t AS VARRAY(9) OF REF area_t;
/

 -- Create area type --
CREATE OR REPLACE TYPE area_t AS OBJECT(
    aid         INT,
    aName       VARCHAR(15),
    aLocation   location_t,
    aLeads      REF doctor_t,
    aWorks      doctorList_t,
    MEMBER FUNCTION getDoctors return doctorList_t -- returns the doctors that are assigned to the asked area
    -- PRAGMA restrict_references(default, wnds, wnps));
    -- checar qué se tiene que hacer en el caso de que se elimine un doctor y cómo afecta al área que lidereaba
);
/
-- DROP TABLE Patient;
-- DROP TABLE Doctor;
-- DROP TABLE Treatment;
-- DROP TABLE Area;

CREATE TABLE Area OF area_t(
    aid PRIMARY KEY,
    aName NOT NULL,
    CONSTRAINT doctor_leads FOREIGN KEY (aLeads) REFERENCES Person ON DELETE SET NULL, -- checar qué debería pasar cuándo se borra el doctor asignado
    CONSTRAINT area_speciality CHECK (aName IN ('General Medicine', 'Traumatology',
                'Allergology', 'Radiology', 'Cardiology', 'Gerontology', 'Obstetrics', 'Pedriatrics'))
);
/

--CREATE OR REPLACE FUNCTION getAreaSpecialities 
    --RETURN VARCHAR IS areaNames VARCHAR(15);
--BEGIN
    --SELECT aName INTO areaNames FROM Area;
    --RETURN (areaNames);
--END getAreaSpecialities;
--/

-- Tells if the area given as argument exists on the Area table -- 
CREATE OR REPLACE FUNCTION getAreaSpecialities(area IN VARCHAR) 
    RETURN BOOLEAN 
IS
    found NUMBER;
BEGIN
    SELECT COUNT(*) INTO found FROM Area WHERE aName = area;
    IF(found = 0) THEN 
        RETURN FALSE;
    ELSE 
        RETURN TRUE;
    END IF;
END getAreaSpecialities;
/


-- Create patient table, inherit from person --
CREATE TABLE Patient OF patient_t(
    PRIMARY KEY(pid),
    -- This are the only possible values for the insurance type
    CONSTRAINT insurance_type CHECK (pInsurancePlan IN ('Unlimited', 'Premium', 'Basic'))
);
/
-- CHANGE THE AREAS
CREATE TABLE Doctor OF doctor_t(
    PRIMARY KEY(pid)
);
/

-- This trigger is used to change the salary of doctor -- 
--CREATE OR REPLACE TRIGGER constraint_doctor_area
--    BEFORE INSERT OR UPDATE
--    ON Doctor
--    DECLARE valid
--    BEGIN
--        IF getBalance(:NEW.dSalary) < :OLD.dSalary THEN
--            RAISE_APPLICATION_ERROR()
--        NULL;
--    END;
--/

 -- Create treatment table --
CREATE TABLE Treatment OF treatment_t(
    CONSTRAINT treatment_prescribe FOREIGN KEY(prescribe) REFERENCES Person ON DELETE SET NULL,
    CONSTRAINT treatment_receives FOREIGN KEY(receives) REFERENCES Person ON DELETE SET NULL
    --CONSTRAINT patient_doctor_pk PRIMARY KEY( prescribe, receives, tDate)
);
/