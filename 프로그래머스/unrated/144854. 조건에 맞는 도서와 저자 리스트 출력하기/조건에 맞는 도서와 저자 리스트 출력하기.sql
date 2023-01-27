-- 코드를 입력하세요
select b.book_id as BOOK_ID, a.author_name as AUTHOR_NAME, DATE_FORMAT(b.PUBLISHED_DATE, '%Y-%m-%d') as PUBLISHED_DATE
from BOOK b
join AUTHOR a
on b.author_id = a.author_id
where b.category = '경제'
order by PUBLISHED_DATE;