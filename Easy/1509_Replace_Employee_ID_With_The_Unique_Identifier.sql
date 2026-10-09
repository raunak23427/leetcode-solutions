-- Problem: Replace Employee ID With The Unique Identifier
-- Problem ID: 1509
-- Difficulty: Easy
-- Language: MySQL
-- Runtime: 1446 ms
-- Memory: 0B
-- Synced From: LeetCode
-- Date: 2026-10-09

# Write your MySQL query statement below
SELECT eU.unique_id as unique_id, e.name as name
FROM Employees e
LEFT JOIN EmployeeUNI eU
ON eu.id = e.id;