# Write your MySQL query statement below

select d.name as 'Department',e.name as 'Employee' ,e.salary as 'Salary' from employee e left join department d on e.departmentID = d.id
where e.salary = (select max(salary) from employee where d.id=employee.departmentId group by departmentId)
