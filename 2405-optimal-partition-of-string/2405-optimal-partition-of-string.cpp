class Solution {
public:
    int partitionString(string s) {
        int PartitionCnt=1;
        int hash[26];
        memset(hash,0,sizeof(hash));
        
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(hash[s[i]-'a']==0)
            {
                hash[s[i]-'a']++;
            }
            else
            {
                memset(hash,0,sizeof(hash));
                PartitionCnt++;
                hash[s[i]-'a']++;
            }
        }
        return PartitionCnt;
    }
};