/*2
  SELECT 
		students.Stud_Num,
		name,
		surname,
		subject,
		mark
FROM students
INNER JOIN Exams ON students.stud_num=exams.stud_num
WHERE (subject='OS' OR subject='Compiling') AND mark>=8

 */
 /*4
  select [subject],count([Stud_Num])
  from exams
  where  mark>=8 and (edate between '2003-12-01' and '2003-12-31')
  group by [subject]
*/