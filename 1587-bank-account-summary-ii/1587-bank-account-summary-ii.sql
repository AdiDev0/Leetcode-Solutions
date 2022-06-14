# Write your MySQL query statement below

select name, sum(amount) as balance from users left join transactions
on users.account = Transactions.account
group by users.name
having sum(amount)>10000

