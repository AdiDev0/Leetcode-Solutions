# Write your MySQL query statement below

# select name from customer 
# where ifnull(referee_id,0) <> 2

# or

select name from customer 
where referee_id is null or referee_id <> 2 