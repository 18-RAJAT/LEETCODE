class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxfrequency(26,0);
        for(auto& it:words2)
        {
            vector<int>frequency(26,0);
            for(auto& ch:it)frequency[ch-'a']++;
            for(int i=0;i<26;++i)maxfrequency[i]=max(maxfrequency[i],frequency[i]);
        }
        vector<string>ans;
        for(auto& it:words1)
        {
            int subset=1;
            vector<int>frequency(26,0);
            for(auto& ch:it)frequency[ch-'a']++;
            for(int i=0;i<26;++i)
            {
                if(frequency[i]<maxfrequency[i])
                {
                    subset=0;
                    break;
                }
            }
            if(subset)ans.push_back(it);
        }
        return ans;
    }
};