# Write your MySQL query statement below
select id,movie,description,rating from Cinema as C where C.id%2=1 and C.description not in ('boring') order by C.rating DeSC;