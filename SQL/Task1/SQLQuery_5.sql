/*1
SELECT *
FROM [University].[dbo].[Students]
WHERE bdate between '1999-01-01' and '2001-01-01' and  name like 'A%'
*/
/*2
SELECT 
		students.Stud_Num,
		name,
		surname,
		subject,
		mark
FROM students
INNER JOIN exams ON students.stud_num=exams.stud_num
WHERE mark<8
*/
/*3
SELECT	Stud_num,
		university
FROM [University].[dbo].[Students]
WHERE (university='YSU' or university='AUA') and
		Stud_num in (
						SELECT Stud_Num
						FROM [University].[dbo].[Exams]
						WHERE mark<8
						GROUP BY Stud_Num	
					)
*/
/*4
SELECT	stud_num,
		avg(mark)
FROM [University].[dbo].[Exams]
WHERE year(edate)=2003
GROUP BY Stud_Num
HAVING avg(mark)>=15
*/
