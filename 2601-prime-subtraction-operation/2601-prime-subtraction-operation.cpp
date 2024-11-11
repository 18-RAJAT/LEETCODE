class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool>Primes(1005,false);
        Primes[2]=true;
        Primes[3]=true;
        Primes[5]=true;
        for(int i=7;i<=1000;i+=2)
        {
            Primes[i]=true;
            for(int j=2;j<i;++j)
            {
                if(i%j==0)
                {
                    Primes[i]=false;
                    break;
                }
            }
        }
        int last=nums.back();
        for(int i=nums.size()-2;~i;--i)
        {
            if(nums[i]<last)
            {
                last=nums[i];continue;
            }
            for(int j=2;j<nums[i];++j)
            {
                if(Primes[j]==false)continue;
                if(j>=nums[i])
                {
                    break;
                }
                if(nums[i]-j<last)
                {
                   nums[i]-=j;
                    break;
                }
            }
            if(nums[i]>=1 && nums[i]<last)
            {
                last=nums[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};