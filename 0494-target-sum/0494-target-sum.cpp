class Solution {
public:
    int f(int ind, int target, vector<int>& nums,
          vector<vector<int>>& dp, int offset) {

        // Target is outside possible range
        if (target < -offset || target > offset)
            return 0;

        if (ind == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;

            if (target == nums[0] || target == -nums[0])
                return 1;

            return 0;
        }

        if (dp[ind][target + offset] != -1)
            return dp[ind][target + offset];

        int add = f(ind - 1, target - nums[ind],
                    nums, dp, offset);

        int subtract = f(ind - 1, target + nums[ind],
                         nums, dp, offset);

        return dp[ind][target + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (target > sum || target < -sum)
            return 0;

        int offset = sum;

        vector<vector<int>> dp(
            n,
            vector<int>(2 * sum + 1, -1)
        );

        return f(n - 1, target, nums, dp, offset);
    }
};