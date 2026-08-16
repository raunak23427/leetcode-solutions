/*
 * Problem: Last Stone Weight
 * Problem ID: 1127
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.9 MB
 * Synced From: LeetCode
 * Date: 2026-08-16
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int i =0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int stone=p.top();
            p.pop();
            int stone2=p.top();
            p.pop();
            if(stone==stone2){
                p.push(stone2-stone);
            }
            else if(stone<stone2){
                p.push(stone2-stone);
            }
            else{
                p.push(stone-stone2);
            }
        }
        return p.top();
    }
};