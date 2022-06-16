# Write your MySQL query statement below

select name, if(count(distance)=0,0, sum(distance)) as travelled_distance from users
left join rides
on users.id = rides.user_id
group by users.id
order by sum(distance) desc, name asc


    