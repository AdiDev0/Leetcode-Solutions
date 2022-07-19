# Write your MySQL query statement below

# select user_id, CONCAT(upper(left(name, 1)), lower(right(name, length(name)-1))) as 'name' from users
# order by user_id;

# or

select user_id, concat(upper(substr(name,1,1)), lower(substr(name, 2, length(name)))) as 'name' from users
order by user_id;