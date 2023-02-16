select MCDP_CD as '진료과코드', count(APNT_NO) as '5월예약건수'
from APPOINTMENT
where APNT_YMD between '2022-05-01 00:00:00' and '2022-05-31 23:59:59'
group by MCDP_CD
order by count(APNT_NO) asc, MCDP_CD asc;