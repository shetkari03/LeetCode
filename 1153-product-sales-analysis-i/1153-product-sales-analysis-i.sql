# Write your MySQL query statement below
select product_name,year,price from Sales as S inner join Product as P on S.product_id=P.product_id;