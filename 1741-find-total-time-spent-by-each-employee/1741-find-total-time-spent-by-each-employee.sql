# Write your MySQL query statement below

# select event_day as day,emp_id,(select sum(out_time-in_time) from employees e1
# where e1.emp_id=e.emp_id and e1.event_day=e.event_day) as total_time from employees e
# group by event_day,emp_id;


select event_day as day,emp_id, sum(out_time-in_time) as total_time from employees
group by event_day,emp_id;