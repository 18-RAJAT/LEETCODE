class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();++i)
        {
            long long k=ceil(double(success*1.0/spells[i]));
            
            auto LB=lower_bound(potions.begin(),potions.end(),k);
            ans.push_back(potions.size()-(LB-potions.begin()));
        }
        return ans;
    }
};