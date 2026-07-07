class Solution {
public:
int findmax(vector<int>&nums){
    int n=nums.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
int sumbyD(vector<int>& nums,int div){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)nums[i]/div);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=findmax(nums);
        while(low<=high){
            int mid=(low+high)/2;
            if(sumbyD(nums,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};