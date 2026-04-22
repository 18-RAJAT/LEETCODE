class Solution{
public:
    vector<string> twoEditWords(vector<string>& queries,vector<string>& dictionary) {
        int n=queries.size(),m=dictionary.size(),x=queries[0].length();
        vector<string>res;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int diff=0;
                for(int k=0;k<x;++k)
                {
                    if(queries[i][k]!=dictionary[j][k] && ++diff>2)break;
                }
                if(diff<3)
                {
                    res.push_back(queries[i]);
                    break;
                }
            }
        }
        return res;
    }
};