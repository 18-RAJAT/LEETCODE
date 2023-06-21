class Solution {
public:
    long long mod(int x){
        if(x>0)return x;
        return -x;
    }
    
    long long minCost(vector<int>& nums, vector<int>& costs) {
        auto findCost=[&](long long pivot) -> long long{
            long long ans=0;
            for(int j=0;j<nums.size();j++){
                long long diff = mod(nums[j]-pivot);
                ans+=diff*(long long)costs[j];     
            }

            return ans;
        };
        
        vector<pair<int,int>>arr;
        int n=nums.size();
        for(int i=0;i<n;i++)arr.push_back({nums[i],costs[i]});
        sort(arr.begin(),arr.end());
        int low=0, high=n-1;
        
        while(low<high){
            int mid = low + (high-low)/2;
            if(findCost(arr[mid].first)< findCost(arr[mid].first +1))high=mid;
            else low=mid+1;
        }
        
        return findCost(arr[low].first);
    }
};