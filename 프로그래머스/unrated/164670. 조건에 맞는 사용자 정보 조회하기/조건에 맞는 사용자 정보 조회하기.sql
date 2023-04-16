select B.USER_ID as USER_ID, B.NICKNAME as NICKNAME, concat(B.CITY, ' ', B.STREET_ADDRESS1, ' ', B.STREET_ADDRESS2) as '전체주소', concat(left(B.TLNO, 3), '-', mid(B.TLNO, 4, 4), '-', right(B.TLNO, 4)) as '전화번호'
from (
    select A.USER_ID as USER_ID, count(*) as COUNT
    from USED_GOODS_USER A
    join USED_GOODS_BOARD B
    on A.USER_ID = B.WRITER_ID
    group by A.USER_ID
    having count(*) >= 3
) as A
join USED_GOODS_USER B
on A.USER_ID = B.USER_ID
order by B.USER_ID desc;