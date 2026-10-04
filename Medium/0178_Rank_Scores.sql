-- Problem: Rank Scores
-- Problem ID: 178
-- Difficulty: Medium
-- Language: MySQL
-- Runtime: 293 ms
-- Memory: 0B
-- Synced From: LeetCode
-- Date: 2026-10-04

SELECT 
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM Scores
ORDER BY score DESC;