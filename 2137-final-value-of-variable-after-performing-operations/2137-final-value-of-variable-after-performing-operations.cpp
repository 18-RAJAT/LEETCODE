class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(auto& it:operations)
        {
            if(it=="++X" || it=="X++")ans++;
            else ans--;
        }
        return ans;
    }
};