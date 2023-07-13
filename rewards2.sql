CREATE TABLE Student(
	rewardsNo	VARCHAR(6) NOT NULL,
	name				VARCHAR (40),
	points			INTEGER NOT NULL DEFAULT 150,
	email				VARCHAR(20),
	PRIMARY KEY (rewardsNo));

	
INSERT INTO Student (rewardsNo, name, points, email)VALUES ('S001', 'Ashely Rodrigez', 150,'aroad@gmail.com');
INSERT INTO Student (rewardsNo, name, points, email)VALUES  ('S002','Joseph Jefferies', 175,' jjeff@yahoo.com');
INSERT INTO Student (rewardsNo, name, points, email)VALUES  ('S003', 'Hanna Raju',  275,  'hanraj@gmail.com');
INSERT INTO Student (rewardsNo, name, points, email)VALUES  ( 'S004','Sarai Athers', 200,'athersara@aol.com');

--SELECT * FROM Student;

--DROP TABLE Student;



