class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            int tmp=nums[i],cnt=0,sum=0;
            for(int i=1;i*i<=tmp;++i)
            {
                if(tmp%i==0)
                {
                    int j=tmp/i;
                    cnt++,sum+=i;
                    if(i!=j)
                    {
                        cnt++,sum+=j;
                    }
                    if(cnt>=5)break;
                }
            }
            if(cnt==4)ans+=sum;
        }
        return ans;
    }
};