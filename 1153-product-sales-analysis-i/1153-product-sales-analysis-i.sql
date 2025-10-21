# Write your MySQL query statement below
select product_name,year,price from sales p left join product s on p.product_id = s.product_id;