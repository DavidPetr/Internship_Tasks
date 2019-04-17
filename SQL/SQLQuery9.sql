/*1
SELECT	name,
		surname,
		university,
		bdate,
		address
FROM Students
WHERE course=3 and faculty='IAM' and (University='YSU' or University='AUA') and bdate ='1999-09-28' and address like '%Yerevan%'
*/
/*3
SELECT	stud_num,
		name,
		surname,
		bdate
FROM Students
WHERE bdate between '1999-01-01' and '2000-06-01' and name like 'A%'
*/
/*4
SELECT	stud_num,
		name,
		surname
FROM Students	
WHERE stud_num in (
					SELECT Stud_Num
					FROM Exams
					GROUP BY stud_num
					HAVING min(mark)>=8
					)
*/