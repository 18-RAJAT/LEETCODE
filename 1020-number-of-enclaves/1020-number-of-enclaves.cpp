class Solution {
public:
    void helper(vector<vector<int>>& a,int i,int j,bool &flag,int& ct)
    {
       if(i<0 or j<0 or i>=a.size() or j>=a[0].size()){flag=true;return;}
        
        if(a[i][j]==0){return;}
        else
        {
           ct++;a[i][j]=0;
            helper(a,i+1,j,flag,ct);
            helper(a,i-1,j,flag,ct);
            helper(a,i,j+1,flag,ct);
            helper(a,i,j-1,flag,ct);
        }
    }
    int numEnclaves(vector<vector<int>>& a)
    {
        int answer;
        for(int i=0;i<a.size();++i)
        {
            for(int j=0;j<a[0].size();++j)
            {
                bool flag=false;int ct=0;
                helper(a,i,j,flag,ct);
                if(!flag)answer=answer+ct;
            }
        }
        return answer;
    }
};