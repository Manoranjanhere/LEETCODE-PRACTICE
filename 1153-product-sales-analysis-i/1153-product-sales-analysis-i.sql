# Write your MySQL query statement below
select product_name,year,price from Product p right join Sales s on p.product_id = s.product_id;