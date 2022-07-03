class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>vis(nums.size()+1,false);
        int tp=0;
        for(int i=0;i<nums.size();++i)
        {
            if(vis[nums[i]]==true){tp=nums[i];}vis[nums[i]]=true;
        }
        int missingEle=0;
        for(int i=1;i<vis.size();++i)
        {
            if(vis[i]==false)missingEle=i;
        }
         vector<int>v1={tp,missingEle};return v1;
    }
};