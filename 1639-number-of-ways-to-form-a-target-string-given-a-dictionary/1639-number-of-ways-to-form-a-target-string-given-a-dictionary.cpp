class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int modulo=1000000007;
        vector<long long int>finish(target.size()+1);
        finish[0]=1;
        for(int i=0;i<words[0].size();++i)
        {
            vector<int>countWords(26,0);
            for(auto& word:words)
            {
                countWords[word[i]-'a']++;
            }
            for(int j=target.size()-1;j>=0;--j)
            {
                finish[j+1]+=finish[j]*countWords[target[j]-'a']%modulo;
            }
        }
        int allTarget=finish[target.size()]%modulo;
        return allTarget;
    }
};