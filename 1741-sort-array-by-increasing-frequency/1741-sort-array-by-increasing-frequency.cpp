class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>freq;
        for(auto& it:nums)
        {
            freq[it]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b)->bool
             {
                if(freq[a]!=freq[b])
                {
                    return freq[a]<freq[b];
                }
                 return a>b?true:false;
             });
        return nums;
    }
};