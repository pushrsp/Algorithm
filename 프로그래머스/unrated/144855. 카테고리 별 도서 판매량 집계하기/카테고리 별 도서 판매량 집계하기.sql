select b.CATEGORY as CATEGORY, sum(bs.SALES) as TOTAL_SALES
from BOOK b
join BOOK_SALES bs
on b.BOOK_ID = bs.BOOK_ID
where bs.SALES_DATE like '2022-01%'
group by b.CATEGORY
order by b.CATEGORY asc;