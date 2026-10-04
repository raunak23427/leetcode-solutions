-- Problem: Exchange Seats
-- Problem ID: 626
-- Difficulty: Medium
-- Language: MySQL
-- Runtime: 335 ms
-- Memory: 0B
-- Synced From: LeetCode
-- Date: 2026-10-04

SELECT
    CASE
        WHEN id % 2 = 1 AND id < (SELECT MAX(id) FROM Seat)
            THEN id + 1
        WHEN id % 2 = 0
            THEN id - 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;