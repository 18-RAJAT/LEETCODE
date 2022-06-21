class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st({nums.begin(),nums.end()});
        int longestSeq=0;
        for(int n:nums)
        {
            if(!st.count(n-1))
            {
                int currentNum=n;
                int currentSeq=1;
                while(st.count(currentNum+1)){currentNum++;currentSeq++;}
                longestSeq=max(longestSeq,currentSeq);
            }
        }
        return longestSeq;
    }
};