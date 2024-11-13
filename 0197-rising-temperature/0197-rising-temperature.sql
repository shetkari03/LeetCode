# Write your MySQL query statement below
SELECT table2.id from Weather as table1
cross join Weather as table2
where  DATEDIFF(table2.recordDate, table1.recordDate) = 1 and table2.temperature > table1.temperature