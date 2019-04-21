/*1
SELECT	stud_num,
		university
FROM Students
WHERE faculty='IAM' and
		Stud_Num in (
						SELECT Stud_Num
						FROM Exams
						WHERE mark<8		
					)
*/
/*2
SELECT 
		students.Stud_Num,
		name,
		surname,
		mark
FROM students
INNER JOIN Exams ON students.stud_num=exams.stud_num
WHERE faculty='IAM' AND mark<8
*/
/*3
SELECT	name,
		surname,
		bdate,
		course,
		faculty
FROM Students
WHERE course=3 and faculty='IAM' and bdate='1999-09-28' and name like 'd%'
*/
/*4
SELECT	subject,
		count(stud_num)
FROM Exams
WHERE mark<8
GROUP BY subject
*/