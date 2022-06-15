# Write your MySQL query statement below

#using if 

# select employee_id,
# if (employee_id mod 2 <> 0 and name not like 'M%', salary, 0)
# as bonus from employees
# order by employee_id

#using case 

select employee_id,
 case 
    when employee_id mod 2 <> 0 and name not like 'M%' then salary
    else 0
 end as bonus from employees
order by employee_id;