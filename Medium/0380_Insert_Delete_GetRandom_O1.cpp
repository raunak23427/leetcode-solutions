/*
 * Problem: Insert Delete GetRandom O(1)
 * Problem ID: 380
 * Difficulty: Medium
 * Language: C++
 * Runtime: 154 ms
 * Memory: 113 MB
 * Synced From: LeetCode
 * Date: 2026-10-31
 */

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIdx;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valToIdx.count(val)) return false;
        valToIdx[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!valToIdx.count(val)) return false;
        int idx = valToIdx[val];
        int lastVal = nums.back();
        nums[idx] = lastVal;
        valToIdx[lastVal] = idx;
        nums.pop_back();
        valToIdx.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};