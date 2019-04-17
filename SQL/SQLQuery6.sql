/*1
SELECT	Stud_num,
		university
FROM Students
WHERE (university='YSU' or university='AUA') and
		Stud_num in (
						SELECT Stud_Num
						FROM Exams
						WHERE edate between '2003-12-03' and '2003-12-09'
						GROUP BY Stud_Num
						HAVING min(mark)=20		
					)
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
WHERE edate between '2003-12-02' and '2003-12-09' and mark>=8
GROUP BY subject
*/