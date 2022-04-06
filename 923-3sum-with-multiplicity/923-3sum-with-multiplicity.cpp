class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unordered_map<int,int>mp; //Using unordered map
        
        int result = 0;
        int mod = 1e9+7;
        
        for(int i=0;i<arr.size();++i)
        {
            result = (result + mp[target - arr[i]]) % mod;
            
            for(int j=0;j<i;++j)
            {
                mp[arr[i] + arr[j]]++;
            }
        }
        return result;
    }
};