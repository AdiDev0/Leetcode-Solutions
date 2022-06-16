# Write your MySQL query statement below

# select author_id as id from views v
# where v.author_id in 
# (select author_id from views vv
#  where vv.author_id = v.author_id and vv.author_id = vv.viewer_id and                    (v.article_id<>vv.article_id or v.view_date<>vv.view_date)
# )

select distinct author_id as id from views v
where v.author_id = v.viewer_id
order by v.author_id;
