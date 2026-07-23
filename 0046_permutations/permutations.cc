#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size());
        dfs(nums, used, res);
        return res;
    }

private:
    vector<int> stack;
    void dfs(vector<int>& nums, vector<bool>& used, vector<vector<int>>& res) {
        if (stack.size() == nums.size()) {
            res.push_back(stack);
            return;
        }

        // Reverse order is allowed in permutation so in each level it could
	// select from nums[0...size-1] except from the selected[used] ones.
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                // Used marks all the allowable remaining elements in the next
                // DFS levels
                used[i] = true;
                stack.push_back(nums[i]);
                dfs(nums, used, res);
                stack.pop_back();
                used[i] = false;
            }
        }
    }
};
