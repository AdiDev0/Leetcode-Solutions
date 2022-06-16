# Write your MySQL query statement below

select player_id, 
(select min(event_date) from activity i
    where i.player_id = j.player_id
) as first_login from activity j
group by player_id
