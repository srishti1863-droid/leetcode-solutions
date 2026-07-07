class Solution {
public:
int findmax(vector<int>&weights){
    int n=weights.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,weights[i]);
    }
    return maxi;
}
int sum(vector<int>& weights){
    int sum=0;
    int n=weights.size();
    for(int i=0;i<n;i++){
        sum+=weights[i];
    }
    return sum;
}
int func(vector<int>& weights,int cap){
    int days=1;
    int load=0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>cap){
            days=days+1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=findmax(weights);
        int high=sum(weights);
        while(low<=high){
            int mid=(low+high)/2;
            int noofdays=func(weights,mid);
            if(noofdays<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};