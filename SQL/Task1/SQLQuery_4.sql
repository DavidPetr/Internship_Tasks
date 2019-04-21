/*1
SELECT	Stud_num,
		university
FROM Students
WHERE faculty='IAM' and university='YSU' and
		Stud_num in (
						SELECT Stud_Num
						FROM Exams
						GROUP BY Stud_Num
						HAVING max(mark)<8		
					)
*/
/*2
SELECT 
		students.Stud_Num,
		name,
		surname,
		subject,
		mark,
		edate
FROM exams
INNER JOIN students ON students.stud_num=exams.stud_num
WHERE subject='Compiling' AND course=3 AND faculty='IAM' 
*/
/*3
SELECT	Stud_Num
FROM Students
WHERE name like 'A%' and [Group]>=600
*/
/*4
SELECT	subject,
		count(stud_num)
FROM Exams
WHERE mark>=8
GROUP BY subject
*/