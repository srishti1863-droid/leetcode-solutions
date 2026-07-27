class Solution {
public:
    bool subsetsumtok(int n, int k, vector<int>& nums) {
        vector<bool> prev(k + 1, false), cur(k + 1, false);

        prev[0] = true;
        cur[0] = true;

        // First element
        if (nums[0] <= k)
            prev[nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool nottake = prev[target];

                bool take = false;
                if (nums[ind] <= target) {
                    take = prev[target - nums[ind]];
                }

                cur[target] = take || nottake;
            }

            prev = cur;
        }

        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }

        // If total sum is odd, equal partition is impossible
        if (totalsum % 2 != 0)
            return false;

        int target = totalsum / 2;

        return subsetsumtok(n, target, nums);
    }
};