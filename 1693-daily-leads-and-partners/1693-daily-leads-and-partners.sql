# Write your MySQL query statement below

select date_id, make_name, count(distinct lead_id)
as unique_leads, count(distinct partner_id) as 
unique_partners from dailysales d
group by date_id, make_name;

# select distinct lead_id from dailysales
# where date_id = "2020-12-8" and make_name = "toyota"
