/*1
SELECT	stud_num,
		name,
		surname,
		bdate,
		university
FROM Students
WHERE university='AUA' and month(bdate)=9
*/
/*3
SELECT	subject,
		count(stud_num)
FROM Exams
WHERE mark>=8
GROUP BY subject
*/
/*4
SELECT	name,
		surname,
		bdate,
		course,
		faculty
FROM Students
WHERE course=3 and faculty='IAM' and year(bdate)='1999' and name like '%v%'
*/

