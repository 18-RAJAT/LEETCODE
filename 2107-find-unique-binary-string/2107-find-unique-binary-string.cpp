class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans="";
        for(int i=0;i<n;++i)
        {
            (nums[i][i]=='0')?ans+='1':ans+='0';
        }
        return ans;
    }
};