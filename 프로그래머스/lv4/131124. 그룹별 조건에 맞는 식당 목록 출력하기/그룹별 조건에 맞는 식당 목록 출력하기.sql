select mp.MEMBER_NAME, rr.REVIEW_TEXT, DATE_FORMAT(rr.REVIEW_DATE, "%Y-%m-%d") as REVIEW_DATE
from MEMBER_PROFILE mp
left join REST_REVIEW rr
on mp.MEMBER_ID = rr.MEMBER_ID
where mp.MEMBER_ID in (
    select MEMBER_ID
    from REST_REVIEW
    group by MEMBER_ID
    having count(MEMBER_ID) = (
        select count(REVIEW_TEXT) as T
        from REST_REVIEW
        group by MEMBER_ID
        order by T desc
        limit 1
    )
)
order by rr.REVIEW_DATE, rr.REVIEW_TEXT;