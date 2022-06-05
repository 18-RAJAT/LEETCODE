class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            if(nums.size()<3){return {};}
            vector<vector<int>>answer;
            sort(nums.begin(),nums.end());
            
            for(int i=0;i+2<nums.size();++i)
            {
                    if(i>0 and nums[i]==nums[i-1]){continue;}
                    int l=i+1;
                    int r=nums.size()-1;
                    
                    while(l<r)
                    {
                    int sum=nums[i]+nums[r]+nums[l];
                    
                    if(sum==0)
                    {
                            answer.push_back({nums[i],nums[l++],nums[r--]});
                            
                            while(l<r and nums[l]==nums[l-1]){l++;}
                            while(l<r and nums[r]==nums[r+1]){r--;}
                    }
                            else if(sum<0){l++;}
                            else{r--;}
                    }       
            }
            return answer;
    }
};