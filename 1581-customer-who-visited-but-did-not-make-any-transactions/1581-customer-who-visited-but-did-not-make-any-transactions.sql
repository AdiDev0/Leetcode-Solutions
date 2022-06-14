# Write your MySQL query statement below


# select customer_id, count(customer_id) as count_no_trans
# from visits v
# where v.visit_id not in(select visit_id from transactions t)
# group by customer_id;


select customer_id, count(customer_id) as count_no_trans
FROM Visits LEFT JOIN Transactions
ON  Visits.visit_id = Transactions.visit_id
WHERE Transactions.visit_id IS NULL
GROUP BY Visits.customer_id;