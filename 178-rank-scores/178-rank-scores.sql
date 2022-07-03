# Write your MySQL query statement below

select score, 
(select count(distinct score) from scores s2 where s1.score<=s2.score) as 'rank' from scores s1
order by score desc;