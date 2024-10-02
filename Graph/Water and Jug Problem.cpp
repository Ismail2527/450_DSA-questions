
#include<bits/stdc++.h>
class Solution {
public:
    bool solve(int x, int y, int z) {
        // base cases
        if (x + y < z) {
            return false;
        }
        if (z == 0) {
            return true;  // Always possible to measure 0 liters
        }

        vector<int>dir = {x, y, -x, -y};
        set<int>st;  // To track the visited states
        queue<int>q;
        
        st.insert(0);
        q.push(0);
        
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            
            for (int it : dir) {
                int total = top + it;
                if (total == z) {
                    return true;
                }
                // Skip invalid states
                if (total < 0 || total > x + y) {
                    continue;
                }
                if (st.find(total) == st.end()) {
                    st.insert(total);
                    q.push(total);
                }
            }
        }
        return false;  // If no solution found, return false
    }
    bool canMeasureWater(int x, int y, int target) {
        return solve(x,y,target);
    }
};