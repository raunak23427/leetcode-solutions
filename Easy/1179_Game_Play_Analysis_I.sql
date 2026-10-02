-- Problem: Game Play Analysis I
-- Problem ID: 1179
-- Difficulty: Easy
-- Language: MySQL
-- Runtime: 515 ms
-- Memory: 0B
-- Synced From: LeetCode
-- Date: 2026-10-02

# Write your MySQL query statement below
# Write your MySQL query statement below
select player_id, min(event_date) as first_login
from Activity
group by player_id;