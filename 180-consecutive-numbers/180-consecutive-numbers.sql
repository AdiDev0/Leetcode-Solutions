# Write your MySQL query statement below

select distinct num as ConsecutiveNums from logs l1
where l1.id+1 in (select id from logs l2 where l2.num=l1.num)
and l1.id+2 in (select id from logs l3 where l3.num=l1.num);