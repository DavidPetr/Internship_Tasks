SELECT	subject,
		avg(mark),
		count(stud_num)
FROM Exams
WHERE edate between '2003-12-01' and '2003-12-09'
GROUP BY subject