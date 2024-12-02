class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans=-1,j=0,cnt=1;
        for(int i=0;i<sentence.size();++i)
        {
            if(sentence[i]==' ')
            {
                j=0;
                cnt++;
            }
            else if(j<0)continue;
            else if(sentence[i]==searchWord[j])
            {
                j++;
                if(j==searchWord.size())
                {
                    ans=cnt;
                    break;
                }
            }
            else j=-1;
        }
        return ans;
    }
};