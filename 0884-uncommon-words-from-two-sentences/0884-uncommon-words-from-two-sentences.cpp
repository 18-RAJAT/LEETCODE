class Solution {
public:
    vector<string> uncommonFromSentences(string s1,string s2) {
        unordered_map<string,int>count;
        istringstream stream1(s1),stream2(s2);
        string word;
        vector<string>ans;
        while(stream1>>word)count[word]++;
        while(stream2>>word)count[word]++;
        for(auto& it:count)
        {
            if (it.second==1)ans.push_back(it.first);
        }
        return ans;
    }
};