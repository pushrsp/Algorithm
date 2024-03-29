SELECT a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, SUM(b.PRICE * s.SALES) AS TOTAL_SALES
FROM AUTHOR a
JOIN BOOK b ON a.AUTHOR_ID = b.AUTHOR_ID
JOIN BOOK_SALES s ON b.BOOK_ID = s.BOOK_ID
WHERE s.SALES_DATE BETWEEN '2022-01-01' AND '2022-01-31'
GROUP BY a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY
ORDER BY a.AUTHOR_ID ASC, b.CATEGORY DESC;