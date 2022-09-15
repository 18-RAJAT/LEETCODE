class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maximum=INT_MIN;
        
        int count;
        for(int i=0;i<sentences.size();++i)
        {
            count=0;
            for(int j=0;j<sentences[i].size();++j)
            {
                if(sentences[i][j]==' ')
                {
                    count++;
                }
            }
            if(count>maximum)
            {
                maximum=count;
            }
        }
        return maximum+1;
    }
};