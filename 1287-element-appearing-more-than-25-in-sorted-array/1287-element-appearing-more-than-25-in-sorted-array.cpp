class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        map<int,int>appearances;
        for(auto& it:arr)
        {
            appearances[it]++;
        }
        int mx=0;
        int ans=0;
        for(auto& it:appearances)
        {
            if(mx<it.second)
            {
                ans=it.first;
                mx=it.second;
            }
        }
        return ans;
    }
};