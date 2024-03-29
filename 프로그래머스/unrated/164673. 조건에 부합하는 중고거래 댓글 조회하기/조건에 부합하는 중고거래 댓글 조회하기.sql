SELECT ugb.TITLE AS TITLE, 
        ugb.BOARD_ID as BOARD_ID,
        ugr.REPLY_ID as REPLY_ID,
        ugr.WRITER_ID as WRITER_ID,
        ugr.CONTENTS as CONTENTS,
        DATE_FORMAT(ugr.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
FROM USED_GOODS_BOARD ugb
JOIN USED_GOODS_REPLY ugr
ON ugb.BOARD_ID = ugr.BOARD_ID
WHERE ugb.CREATED_DATE BETWEEN '2022-10-01' AND '2022-10-31'
ORDER BY ugr.CREATED_DATE ASC, ugb.TITLE ASC;