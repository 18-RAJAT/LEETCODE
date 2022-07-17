class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        // map<int,int>mp;
        // for(auto it:nums)mp[it]++;
        // int p=0;
        // int up=0;
        // for(auto it:mp)
        // {
        //     p+=it.second/2;
        //     up+=it.second%2;
        // }
        // vector<int>v;
        // v.push_back(p);
        // v.push_back(up);
        // return v;
        map<int,int>ct;
        int a=0,b=0;
        for(auto it:nums){ct[it]++;}
        for(auto c:ct)
        {
            a+=c.second/2;
            b+=c.second%2;
        }
        return{a,b};
    }
};