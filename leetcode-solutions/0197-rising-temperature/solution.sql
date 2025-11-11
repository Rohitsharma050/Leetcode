# Write your MySQL query statement below
Select t2.id from Weather t1 join Weather t2
on DateDiff(t2.recordDate,t1.recordDate) = 1
where t2.temperature>t1.temperature
