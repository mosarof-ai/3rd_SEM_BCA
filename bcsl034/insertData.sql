-- Use the database
USE student_records_mosarof;

-- Insert all students
INSERT INTO Students (first_name, last_name, date_of_birth, email, phone) VALUES
('Rahul', 'Sharma', '1999-05-15', 'rahul.sharma@email.com', '9876543210'),
('Priya', 'Verma', '2000-08-22', 'priya.verma@email.com', '9876543211'),
('Amit', 'Kumar', '1998-12-10', 'amit.kumar@email.com', '9876543212'),
('Sneha', 'Singh', '2001-03-18', 'sneha.singh@email.com', '9876543213'),
('Vikram', 'Patel', '1999-07-25', 'vikram.patel@email.com', '9876543214'),
('Anjali', 'Reddy', '2000-11-30', 'anjali.reddy@email.com', '9876543215'),
('Arjun', 'Gupta', '1997-02-14', 'arjun.gupta@email.com', '9876543216'),
('Kavya', 'Nair', '2001-06-08', 'kavya.nair@email.com', '9876543217'),
('Rohan', 'Mehta', '1999-09-20', 'rohan.mehta@email.com', '9876543218'),
('Divya', 'Iyer', '2000-04-12', 'divya.iyer@email.com', '9876543219'),
('Karan', 'Joshi', '1998-01-28', 'karan.joshi@email.com', '9876543220'),
('Pooja', 'Desai', '2001-10-05', 'pooja.desai@email.com', '9876543221'),
('Aditya', 'Rao', '1999-12-18', 'aditya.rao@email.com', '9876543222'),
('Neha', 'Kapoor', '2000-07-22', 'neha.kapoor@email.com', '9876543223'),
('Siddharth', 'Bansal', '1998-08-16', 'siddharth.bansal@email.com', '9876543224');

-- Insert all courses
INSERT INTO Courses (course_name, credits, semester) VALUES
('Data Structures', 4, 'Semester-3'),
('Database Management Systems', 4, 'Semester-3'),
('Web Development', 3, 'Semester-4'),
('Operating Systems', 4, 'Semester-4'),
('Computer Networks', 3, 'Semester-5'),
('Software Engineering', 4, 'Semester-5'),
('Object Oriented Programming', 4, 'Semester-3'),
('Discrete Mathematics', 3, 'Semester-3'),
('Computer Organization', 4, 'Semester-4'),
('Artificial Intelligence', 4, 'Semester-6'),
('Machine Learning', 3, 'Semester-6'),
('Cloud Computing', 3, 'Semester-5');

-- Insert all enrollments
INSERT INTO Enrollment (student_id, course_id, enrollment_date, grade) VALUES
(1, 1, '2025-01-15', 'A'),(1, 2, '2025-01-15', 'B'),(1, 7, '2025-01-15', 'A'),(1, 8, '2025-01-15', 'B'),
(2, 1, '2025-01-16', 'A'),(2, 3, '2025-01-16', 'A'),(2, 7, '2025-01-16', 'A'),(2, 2, '2025-01-16', 'B'),(2, 8, '2025-01-16', 'C'),
(3, 2, '2025-01-17', 'C'),(3, 4, '2025-01-17', 'B'),(3, 9, '2025-01-17', 'B'),(3, 3, '2025-01-17', 'F'),
(4, 1, '2025-01-18', 'A'),(4, 2, '2025-01-18', 'F'),(4, 7, '2025-01-18', 'B'),(4, 8, '2025-01-18', 'C'),(4, 3, '2025-01-18', 'B'),
(5, 3, '2025-01-19', 'B'),(5, 5, '2025-01-19', 'A'),(5, 12, '2025-01-19', 'A'),
(6, 1, '2025-01-20', 'A'),(6, 2, '2025-01-20', 'A'),(6, 7, '2025-01-20', 'A'),(6, 8, '2025-01-20', 'A'),
(7, 4, '2025-01-21', 'B'),(7, 5, '2025-01-21', 'C'),(7, 6, '2025-01-21', 'B'),
(8, 1, '2025-01-22', 'A'),(8, 2, '2025-01-22', 'B'),(8, 7, '2025-01-22', 'A'),(8, 8, '2025-01-22', 'B'),(8, 3, '2025-01-22', 'C'),
(9, 4, '2025-01-23', 'A'),(9, 5, '2025-01-23', 'B'),(9, 9, '2025-01-23', 'A'),(9, 6, '2025-01-23', 'C'),
(10, 10, '2025-01-24', 'A'),(10, 11, '2025-01-24', 'A'),(10, 5, '2025-01-24', 'B'),
(11, 1, '2025-01-25', 'F'),(11, 2, '2025-01-25', 'D'),(11, 7, '2025-01-25', 'C'),(11, 8, '2025-01-25', 'B'),
(12, 3, '2025-01-26', 'A'),(12, 4, '2025-01-26', 'A'),(12, 9, '2025-01-26', 'B'),(12, 5, '2025-01-26', 'A'),(12, 12, '2025-01-26', 'A'),
(13, 1, '2025-01-27', 'B'),(13, 2, '2025-01-27', 'B'),(13, 7, '2025-01-27', 'A'),(13, 8, '2025-01-27', 'B'),
(15, 10, '2025-01-28', 'A'),(15, 11, '2025-01-28', 'B'),(15, 6, '2025-01-28', 'A');

-- Verify counts
SELECT 'Students' AS TableName, COUNT(*) AS RecordCount FROM Students
UNION ALL
SELECT 'Courses', COUNT(*) FROM Courses
UNION ALL
SELECT 'Enrollment', COUNT(*) FROM Enrollment;