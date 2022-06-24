# Write your MySQL query statement below


select firstname, lastname, city, state from person
LEFT JOIN address
ON person.personid = address.personid;