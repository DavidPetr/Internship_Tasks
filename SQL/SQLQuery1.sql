  select [subject],count([Stud_Num])
  from exams
  where  mark>=8 and (edate between '2003-12-01' and '2003-12-31')
  group by [subject]
  