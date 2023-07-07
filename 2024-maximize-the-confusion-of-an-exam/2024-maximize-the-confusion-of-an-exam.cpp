class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans(0),start(0);
        int i(0),j(0);
        for(int x=0;x<answerKey.size();++x)
        {
            if(answerKey[x]=='F')
            {
                i++;
            }
            else if(answerKey[x]=='T')
            {
                j++;
            }
            while(x-start+1-max<int>(i,j)>k)
            {
                if(answerKey[start]=='F')
                {
                    i--;
                }
                else if(answerKey[start]=='T')
                {
                    j--;
                }
                start++;
            }
            ans=max<int>(ans,x-start+1);
        }
        return ans;
    }
};