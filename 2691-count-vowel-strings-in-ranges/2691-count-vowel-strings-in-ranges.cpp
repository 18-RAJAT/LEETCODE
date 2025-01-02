class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>vowels={'a','e','i','o','u','A','E','I','O','U'};
        int n=words.size();
        vector<int>prefixSum(n+1,0);
        for(int i=0;i<n;++i)
        {
            if(vowels.count(words[i].front()) && vowels.count(words[i].back()))
            {
                prefixSum[i+1]=prefixSum[i]+1;
            }
            else
            {
                prefixSum[i+1]=prefixSum[i];
            }
        }
        vector<int>ans;
        for(auto& query:queries)
        {
            int l=query[0],r=query[1];
            ans.push_back(prefixSum[r+1]-prefixSum[l]);
        }
        return ans;
    }
};