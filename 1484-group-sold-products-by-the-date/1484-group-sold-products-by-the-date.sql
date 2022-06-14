# Write your MySQL query statement below
select sell_date, count(distinct product) as num_sold, 
    (select group_concat(distinct product ) from activities i
         where i.sell_date = j.sell_date
         order by product
    ) as products 
from activities j
group by sell_date;