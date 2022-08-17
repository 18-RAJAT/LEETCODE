class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
//         map<string,int>wordFrequency;
//         map<int,set<string>>frequencyWord;
//         vector<string>res;
        
//         for(auto word:words){wordFrequency[word]++;}
        
//         for(auto it:wordFrequency)
//         {frequencyWord[it.second].insert(it.first);}
        
//         for(auto it=frequencyWord.begin();it!=frequencyWord.end();++i)

        if(words.empty()){return {};}
        map<string,int>mp;
        for(auto& it:words){mp[it]++;}
        map<int,set<string>,greater<int>>mpg;
        for(auto& ar:mp)
        {
            mpg[ar.second].insert(ar.first);
        }
        
        int i=0;
        vector<string>result;
        for(auto& p:mpg)
        {
            for(auto& q:p.second)
            {
                result.push_back(q);
                if(result.size()==k){return result;}
            }
        }
        return result;
    }
};