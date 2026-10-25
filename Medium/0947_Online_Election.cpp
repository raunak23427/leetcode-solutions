/*
 * Problem: Online Election
 * Problem ID: 947
 * Difficulty: Medium
 * Language: C++
 * Runtime: 103 ms
 * Memory: 110.5 MB
 * Synced From: LeetCode
 * Date: 2026-10-25
 */


class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;

        unordered_map<int, int> count;
        int leader = -1;
        int maxVotes = 0;

        for (int person : persons) {
            count[person]++;

            if (count[person] >= maxVotes) {
                maxVotes = count[person];
                leader = person;
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int left = 0, right = times.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (times[mid] <= t)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return leaders[right];
    }
};
