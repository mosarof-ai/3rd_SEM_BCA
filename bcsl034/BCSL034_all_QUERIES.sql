CREATE DATABASE student_records_mosarof;
USE student_records_mosarof;

#creating table
CREATE TABLE Students (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    date_of_birth DATE,
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(15)
);
CREATE TABLE Courses (
    course_id INT PRIMARY KEY AUTO_INCREMENT,
    course_name VARCHAR(100) NOT NULL,
    credits INT,
    semester VARCHAR(20)
);
CREATE TABLE Enrollment (
    enrollment_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id INT,
    course_id INT,
    enrollment_date DATE,
    grade VARCHAR(2),
    FOREIGN KEY (student_id) REFERENCES Students(student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES Courses(course_id) ON DELETE CASCADE
);

-- CRUD 1 INSERTING TO ALL TABLES
-- insert all datas
-- in students
-- Insert 12 students
INSERT INTO Students (first_name, last_name, date_of_birth, email, phone) VALUES
('Mosarof', 'Hossain', '1999-05-15', 'worldofai.founder@email.com', '9332404013'),
('Elon', 'Musk', '2000-08-22', 'tesla.owner@email.com', '9876543211'),
('Bill', 'Gates', '1998-12-10', 'ms365.ownerkumar@email.com', '9876543212'),
('Jeff', 'Bezos', '2001-03-18', 'amazon.founder@email.com', '9876543213'),
('Vikram', 'Patel', '1999-07-25', 'vikram.patel@email.com', '9876543214'),
('HC', 'Verma', '2000-11-30', 'physics.professor@email.com', '9876543215'),
('Arjun', 'Gupta', '1997-02-14', 'arjun.gupta@email.com', '9876543216'),
('Kavya', 'Nair', '2001-06-08', 'kavya.nair@email.com', '9876543217'),
('Rohan', 'Mehta', '1999-09-20', 'rohan.mehta@email.com', '9876543218'),
('Divya', 'Iyer', '2000-04-12', 'divya.iyer@email.com', '9876543219'),
('Karan', 'Joshi', '1998-01-28', 'karan.joshi@email.com', '9876543220'),
('Pooja', 'Desai', '2001-10-05', 'pooja.desai@email.com', '9876543221');


-- Insert 8 courses
INSERT INTO Courses (course_name, credits, semester) VALUES
('Data Structures', 4, 'Semester-3'),
('Database Management Systems', 4, 'Semester-3'),
('Quantum Computer', 3, 'Semester-4'),
('Operating Systems', 4, 'Semester-4'),
('Computer Networks', 3, 'Semester-5'),
('physics For AI ', 4, 'Semester-5'),
('AI and ML', 4, 'Semester-3'),
('Discrete Mathematics', 3, 'Semester-3');

-- Insert 25 enrollment records with strategic course assignments
INSERT INTO Enrollment (student_id, course_id, enrollment_date, grade) VALUES

-- Student 1: Mosarof Hossain (Me - AI/ML enthusiast) - 4 courses
(1, 7, '2025-01-15', 'A'),  -- AI and ML - Perfect A!
(1, 6, '2025-01-15', 'A'),  -- Physics For AI - Perfect A!
(1, 1, '2025-01-15', 'A'),  -- Data Structures - Perfect A!
(1, 2, '2025-01-15', 'A'),  -- Database Management - Perfect A!

-- Student 2: Elon Musk (Tech genius) - 3 courses
(2, 7, '2025-01-16', 'A'),  -- AI and ML
(2, 6, '2025-01-16', 'A'),  -- Physics For AI
(2, 3, '2025-01-16', 'A'),  -- Quantum Computer

-- Student 3: Bill Gates (Software legend) - 3 courses
(3, 1, '2025-01-17', 'A'),  -- Data Structures
(3, 2, '2025-01-17', 'A'),  -- Database Management Systems
(3, 4, '2025-01-17', 'A'),  -- Operating Systems

-- Student 4: Jeff Bezos (Business + Tech) - 3 courses
(4, 2, '2025-01-18', 'B'),  -- Database Management Systems
(4, 5, '2025-01-18', 'A'),  -- Computer Networks (for AWS!)
(4, 7, '2025-01-18', 'B'),  -- AI and ML

-- Student 5: Vikram Patel - 2 courses
(5, 3, '2025-01-19', 'B'),  -- Quantum Computer
(5, 5, '2025-01-19', 'A'),  -- Computer Networks

-- Student 6: HC Verma (Physics Master!) - 3 courses
(6, 6, '2025-01-20', 'A'),  -- Physics For AI - Obviously A+!
(6, 3, '2025-01-20', 'A'),  -- Quantum Computer
(6, 8, '2025-01-20', 'A'),  -- Discrete Mathematics

-- Student 7: Arjun Gupta - 2 courses
(7, 4, '2025-01-21', 'B'),  -- Operating Systems
(7, 5, '2025-01-21', 'C'),  -- Computer Networks

-- Student 8: Kavya Nair - 1 course
(8, 1, '2025-01-22', 'A'),  -- Data Structures

-- Student 9: Rohan Mehta - 2 courses
(9, 7, '2025-01-23', 'B'),  -- AI and ML
(9, 4, '2025-01-23', 'C'),  -- Operating Systems

-- Student 10: Divya Iyer - 2 courses
(10, 2, '2025-01-24', 'A'),  -- Database Management Systems
(10, 5, '2025-01-24', 'B'),  -- Computer Networks

-- Student 11: Karan Joshi - 1 course (Failed student for testing)
(11, 1, '2025-01-25', 'F'); -- Data Structures - Failed

-- Student 12: Pooja Desai - NO enrollments (for Query 6 testing)
-- This student has no courses enrolled

-- TO DELETE ALL RECORDS AND RESET
-- Step 1: Disable foreign key checks
SET FOREIGN_KEY_CHECKS = 0;

-- Step 2: Truncate all tables (this resets AUTO_INCREMENT automatically)
TRUNCATE TABLE Enrollment;
TRUNCATE TABLE Students;
TRUNCATE TABLE Courses;

-- Step 3: Re-enable foreign key checks
SET FOREIGN_KEY_CHECKS = 1;

-- CRUD 2 DISPLAY/ READ RECORDS FROM EACH TABLE
-- 1.DISPLAY ALL RECORDS
SELECT * FROM student_records_mosarof.students;
SELECT * FROM student_records_mosarof.courses;
SELECT * FROM student_records_mosarof.enrollment;

-- 2. READS OR SEE ANY SPECIFIC RECORD
select * from students where first_name = "Mosarof";
-- enrolments with details
SELECT 
    e.enrollment_id,
    s.first_name,
    s.last_name,
    c.course_name,
    e.grade
FROM Enrollment e
JOIN Students s ON e.student_id = s.student_id
JOIN Courses c ON e.course_id = c.course_id;

-- update existing details
UPDATE Students 
SET phone = '9999999999' 
WHERE student_id = 2;

UPDATE Students 
SET email = 'mosarof.new@email.com' 
WHERE student_id = 1;

UPDATE Enrollment 
SET grade = 'A' 
WHERE enrollment_id = 6;

UPDATE Students 
SET phone = '8888888888', email = 'elon.updated@email.com' 
WHERE student_id = 2;
     -- to check weather entrie updated or not
SELECT * FROM Students WHERE student_id IN (1, 2);
SELECT * FROM Enrollment WHERE enrollment_id = 6;

-- delete a perticular entrie
DELETE FROM Enrollment WHERE enrollment_id = 25;
DELETE FROM Students WHERE student_id = 12;
DELETE FROM Courses WHERE course_id = 8;

-- verify
SELECT * FROM Enrollment WHERE enrollment_id = 25;
SELECT * FROM Students WHERE student_id = 12;
SELECT * FROM Courses WHERE course_id = 8;  

        
-- ==========================================
-- 15 SQL QUERIES FOR STUDENT RECORDS SYSTEM
-- ==========================================

USE student_records;

-- ==========================================
-- QUERY 1: List all students with their enrollment details
-- ==========================================
SELECT 
    s.student_id,
    s.first_name,
    s.last_name,
    c.course_name,
    e.enrollment_date,
    e.grade
FROM Students s
JOIN Enrollment e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id
ORDER BY s.student_id;

-- ==========================================
-- QUERY 2: Retrieve all courses in which a specific student is enrolled
-- ==========================================
SELECT 
    c.course_id,
    c.course_name,
    c.credits,
    c.semester,
    e.grade
FROM Courses c
JOIN Enrollment e ON c.course_id = e.course_id
WHERE e.student_id = 1;

-- ==========================================
-- QUERY 3: Calculate the number of students enrolled in each course
-- ==========================================
SELECT 
    c.course_name,
    COUNT(e.student_id) AS student_count
FROM Courses c
LEFT JOIN Enrollment e ON c.course_id = e.course_id
GROUP BY c.course_id, c.course_name
ORDER BY student_count DESC;

-- ==========================================
-- QUERY 4: Find students who have secured grade 'A' in any course
-- ==========================================
SELECT DISTINCT
    s.student_id,
    s.first_name,
    s.last_name,
    s.email
FROM Students s
JOIN Enrollment e ON s.student_id = e.student_id
WHERE e.grade = 'A'
ORDER BY s.first_name;

-- ==========================================
-- QUERY 5: Retrieve the average grade per course
-- ==========================================
SELECT 
    c.course_name,
    AVG(CASE 
        WHEN e.grade = 'A' THEN 4
        WHEN e.grade = 'B' THEN 3
        WHEN e.grade = 'C' THEN 2
        WHEN e.grade = 'D' THEN 1
        WHEN e.grade = 'F' THEN 0
    END) AS average_grade,
    COUNT(e.enrollment_id) AS total_students
FROM Courses c
JOIN Enrollment e ON c.course_id = e.course_id
GROUP BY c.course_id, c.course_name
ORDER BY average_grade DESC;

-- ==========================================
-- QUERY 6: List all students who have not enrolled in any course
-- ==========================================
SELECT 
    s.student_id,
    s.first_name,
    s.last_name,
    s.email
FROM Students s
LEFT JOIN Enrollment e ON s.student_id = e.student_id
WHERE e.enrollment_id IS NULL;

-- ==========================================
-- QUERY 7: Find courses that have the highest number of enrollments
-- ==========================================
SELECT 
    c.course_name,
    COUNT(e.student_id) AS enrollment_count
FROM Courses c
JOIN Enrollment e ON c.course_id = e.course_id
GROUP BY c.course_id, c.course_name
HAVING COUNT(e.student_id) = (
    SELECT MAX(enrollment_count) 
    FROM (
        SELECT COUNT(student_id) AS enrollment_count
        FROM Enrollment
        GROUP BY course_id
    ) AS counts
)
ORDER BY c.course_name;

-- ==========================================
-- QUERY 8: Retrieve student details sorted by last name
-- ==========================================
SELECT 
    student_id,
    first_name,
    last_name,
    date_of_birth,
    email,
    phone
FROM Students
ORDER BY last_name ASC, first_name ASC;

-- ==========================================
-- QUERY 9: Find all courses offered in a specific semester
-- ==========================================
SELECT 
    course_id,
    course_name,
    credits,
    semester
FROM Courses
WHERE semester = 'Semester-3';

-- ==========================================
-- QUERY 10: Retrieve total number of courses each student has enrolled in
-- ==========================================
SELECT 
    s.student_id,
    s.first_name,
    s.last_name,
    COUNT(e.course_id) AS total_courses
FROM Students s
LEFT JOIN Enrollment e ON s.student_id = e.student_id
GROUP BY s.student_id, s.first_name, s.last_name
ORDER BY total_courses DESC, s.first_name;

-- ==========================================
-- QUERY 11: Display enrollment count per semester
-- ==========================================
SELECT 
    c.semester,
    COUNT(e.enrollment_id) AS enrollment_count
FROM Courses c
JOIN Enrollment e ON c.course_id = e.course_id
GROUP BY c.semester
ORDER BY c.semester;

-- ==========================================
-- QUERY 12: List students along with the number of courses they failed
-- ==========================================
SELECT 
    s.student_id,
    s.first_name,
    s.last_name,
    COUNT(CASE WHEN e.grade = 'F' THEN 1 END) AS failed_courses
FROM Students s
LEFT JOIN Enrollment e ON s.student_id = e.student_id
GROUP BY s.student_id, s.first_name, s.last_name
HAVING COUNT(CASE WHEN e.grade = 'F' THEN 1 END) > 0
ORDER BY failed_courses DESC;

-- ==========================================
-- QUERY 13: Find the student who has scored the most A grades
-- ==========================================
SELECT 
    s.student_id,
    s.first_name,
    s.last_name,
    COUNT(CASE WHEN e.grade = 'A' THEN 1 END) AS a_grade_count
FROM Students s
JOIN Enrollment e ON s.student_id = e.student_id
WHERE e.grade = 'A'
GROUP BY s.student_id, s.first_name, s.last_name
ORDER BY a_grade_count DESC
LIMIT 1;

-- ==========================================
-- QUERY 14: Display all students born before the year 2000
-- ==========================================
SELECT 
    student_id,
    first_name,
    last_name,
    date_of_birth,
    YEAR(date_of_birth) AS birth_year
FROM Students
WHERE YEAR(date_of_birth) < 2000
ORDER BY date_of_birth;

-- ==========================================
-- QUERY 15: Retrieve course-wise average grade for all enrolled students
-- ==========================================
SELECT 
    c.course_name,
    c.semester,
    ROUND(AVG(CASE 
        WHEN e.grade = 'A' THEN 4
        WHEN e.grade = 'B' THEN 3
        WHEN e.grade = 'C' THEN 2
        WHEN e.grade = 'D' THEN 1
        WHEN e.grade = 'F' THEN 0
    END), 2) AS average_grade,
    COUNT(e.enrollment_id) AS total_students
FROM Courses c
JOIN Enrollment e ON c.course_id = e.course_id
GROUP BY c.course_id, c.course_name, c.semester
ORDER BY average_grade DESC;

-- ==========================================
-- END OF QUERIES
-- ==========================================

