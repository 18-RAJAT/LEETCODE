class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
            {
                for(auto& it:{-1,1})
                {
                    vector<int>tmp=nums;
                    int curr=i,dir=it,ok=1;
                    while(curr>=0 && curr<n)
                    {
                        if(tmp[curr]==0)curr+=dir;
                        else if(tmp[curr]>=1)
                        {
                            tmp[curr]--,dir=-dir,curr+=dir;
                        }
                        else break;
                    }
                    for(auto &it:tmp)
                    {
                        if(it!=0)
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(ok)ans++;
                }
            }
        }
        return ans;
    }
};