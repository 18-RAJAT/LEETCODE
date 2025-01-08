class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int len=words[i].size();
                if(words[j].size()>=len &&
                   words[j].compare(0,len,words[i])==0 &&
                   words[j].compare(words[j].size()-len,len,words[i])==0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};