/*
 * Problem: Simplify Path
 * Problem ID: 71
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 10.7 MB
 * Synced From: LeetCode
 * Date: 2026-08-11
 */

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp = "";

        for (int i = 0; i <= path.size(); i++) {
            
            if (i == path.size() || path[i] == '/') {
                
                if (temp == "" || temp == ".") {
                    // Ignore empty string and "."
                }
                else if (temp == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else {
                    st.push_back(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        string ans = "";

        for (string dir : st) {
            ans += "/" + dir;
        }

        if (ans == "")
            return "/";

        return ans;
    }
};