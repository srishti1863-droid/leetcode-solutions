class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx)
                mx = nums[i];
        }

        vector<int> freq(mx + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<int> cnt(mx + 1, 0);

        // Count numbers divisible by i
        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                cnt[i] += freq[j];
            }
        }

        vector<long long> exact(mx + 1, 0);

        // Total pairs divisible by i
        for (int i = 1; i <= mx; i++) {
            exact[i] = 1LL * cnt[i] * (cnt[i] - 1) / 2;
        }

        // Inclusion-Exclusion
        for (int i = mx; i >= 1; i--) {
            for (int j = i + i; j <= mx; j += i) {
                exact[i] = exact[i] - exact[j];
            }
        }

        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;

        // Binary Search
        for (int i = 0; i < queries.size(); i++) {

            long long k = queries[i];

            int low = 1;
            int high = mx;

            while (low < high) {
                int mid = (low + high) / 2;

                if (prefix[mid] > k)
                    high = mid;
                else
                    low = mid + 1;
            }

            ans.push_back(low);
        }

        return ans;
    }
};