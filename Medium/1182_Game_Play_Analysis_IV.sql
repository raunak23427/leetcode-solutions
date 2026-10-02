-- Problem: Game Play Analysis IV
-- Problem ID: 1182
-- Difficulty: Medium
-- Language: MySQL
-- Runtime: 626 ms
-- Memory: 0B
-- Synced From: LeetCode
-- Date: 2026-10-02

# Write your MySQL query statement below
SELECT 
ROUND(
    COUNT(DISTINCT a.player_id) / 
    (SELECT COUNT(DISTINCT player_id) FROM Activity), 
    2
) AS fraction
FROM Activity a
JOIN(
    SELECT player_id, MIN(event_date) as first_date
    FROM Activity
    GROUP BY player_id
) f
ON a.player_id = f.player_id
AND a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY)