class Solution {
public:
int f(int ind,int target,vector<int>& nums){
    if(ind==0){
        if(target==0 && nums[0]==0) return 2;
        if(target==nums[0] || target==-nums[0]) return 1;
        return 0;
    }
    int add=f(ind-1,target-nums[ind],nums);
    int subtract=f(ind-1,target+nums[ind],nums);
    return add+subtract;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,target,nums);
    }
};