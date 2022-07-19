# Write your MySQL query statement below

select user_id as'buyer_id', join_date, IFNULL((select count(order_date) from orders 
where order_date like '2019%' and buyer_id = user_id
group by buyer_id), 0) as 'orders_in_2019' from users;