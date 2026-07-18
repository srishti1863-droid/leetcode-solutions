class Solution {
public:
int minimum(vector<int>&nums){
    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        mini=min(mini,nums[i]);
    }
    return mini;
}
int maximum(vector<int>&nums){
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
    int findGCD(vector<int>& nums) {
        int min=minimum(nums);
        int max=maximum(nums);
        return gcd(min,max);
    }
};