-- Problem: Customers Who Bought All Products
-- Problem ID: 1135
-- Difficulty: Medium
-- Language: MySQL
-- Runtime: 616 ms
-- Memory: 0B
-- Synced From: LeetCode
-- Date: 2026-10-04

SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*)
    FROM Product
);