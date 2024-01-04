class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;  
        mp.clear();
        for(int i=0;i<n;++i)
        {
            mp[nums[i]]++;
        }
        int count=0;
        for(auto &it:mp)
        {
            if(it.second<=1)
            {
                return -1;
            }
            int S=it.second;
            while(S)
            {
                if(S<=2)
                {
                    count++;
                    break;
                }
                else
                {
                    count+=S/3;
                    S%=3;
                }
            }
        }
        return count;
    }
};