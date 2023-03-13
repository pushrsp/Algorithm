select gs.USER_ID as USER_ID, gs.NICKNAME as NICKNAME, sum(gb.PRICE) as TOTAL_SALES
from USED_GOODS_USER gs
left join USED_GOODS_BOARD gb
on gs.USER_ID = gb.WRITER_ID
where gb.STATUS = 'DONE'
group by gs.USER_ID
having sum(gb.PRICE) >= 700000
order by TOTAL_SALES;