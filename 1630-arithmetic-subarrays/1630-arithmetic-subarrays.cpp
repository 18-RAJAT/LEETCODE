class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int x=l.size(),y=r.size();
        vector<bool>ans;
        for(int i=0;i<x;++i)
        {
            vector<int>tmp;
            for(int j=l[i];j<=r[i];++j)
            {
                tmp.push_back(nums[j]);
            }
            sort(tmp.begin(),tmp.end());
            int diff=abs(tmp[0]-tmp[1]);
            bool flag=false;
            
            int sz=tmp.size();
            for(int i=1;i<sz;++i)
            {
                if(tmp[i]-tmp[i-1]!=diff)
                {
                    flag=true;
                    break;
                }
            }
            ans.push_back(flag==false?true:false);
        }
        return ans;
    }
};