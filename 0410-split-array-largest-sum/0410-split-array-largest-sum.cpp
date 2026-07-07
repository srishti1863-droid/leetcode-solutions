class Solution {
public:
int findmax(vector<int>nums){
    int maxi=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
int sum(vector<int>&nums){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    return sum;
}
int countstudents(vector<int>&nums,int pages){
    int stu=1;
    int pagestu=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(pagestu+nums[i]<=pages){
            pagestu+=nums[i];;
        }
        else{
            stu++;
            pagestu=nums[i];
        }
    }
    return stu;
}
int findpages(vector<int>&nums,int n,int m){
    int low=findmax(nums);
    int high=sum(nums);
    while(low<=high){
        int mid=(low+high)/2;
        int noofstu=countstudents(nums,mid);
        if(noofstu>m) low=mid+1;
        else high=mid-1;
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findpages(nums,nums.size(),k);
    }
};