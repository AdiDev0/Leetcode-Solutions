# Write your MySQL query statement below


# select product_id , product_name from product p
# where (select max(sale_date) from sales s
# where s.product_id = p.product_id
# group by product_id) between '2019-01-01' and '2019-03-31'
# order by product_name;


select p.product_id, p.product_name
FROM Product p JOIN Sales s ON p.product_id=s.product_id
group by product_id
having min(sale_date)>='2019-01-01' and max(sale_date) <= '2019-03-31';

