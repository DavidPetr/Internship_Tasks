/*1
SELECT	Stud_Num,
		university
FROM Students
WHERE stud_num in (
					SELECT Stud_Num
					FROM Exams
					WHERE (subject='OS' or subject='Compiling') and mark>=8
					)
*/
/*3
SELECT Stud_Num
FROM Exams
WHERE (subject='OS' or subject='Compiling') and mark=20 and
		edate between '2003-12-03' and '2003-12-10' 
*/

SELECT	stud_num,
		name,
		surname
FROM Students	
WHERE stud_num in (
					SELECT Stud_Num
					FROM Exams
					GROUP BY stud_num
					HAVING min(mark)<8 and max(mark)>=8
					)
