class Solution {
public:
    int tmp=-1;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& RE, vector<vector<int>>& BE) {
    
    function<void(vector<pair<int,char>>arr[],vector<int>&Rvis,vector<int>&Bvis,int node,int d,char pre)>dfs=[&](vector<pair<int,char>>             arr[],vector<int> &Rvis,vector<int> &Bvis,int node,int d,char pre)
    {
        if(pre=='R')
        {
            Rvis[node]=d;//to store the distance of the node from the source
        }
        else
        {
            Bvis[node]=d;
        }
        for(auto it:arr[node])
        {
            if(pre=='R')
            {
                //if the previous node was red then we can only go to the blue node
                if(it.second=='B' and Bvis[it.first]>(d+1))
                {
                    dfs(arr,Rvis,Bvis,it.first,d+1,'B');
                }
            }
            else 
            {
                //if the previous node was blue then we can only go to the red node
                if(it.second=='R' and Rvis[it.first]>(d+1))
                {
                    dfs(arr,Rvis,Bvis,it.first,d+1,'R');
                } 
            }
        }
    };
        vector<pair<int,char>>arr[n];
        for(auto it:RE)
        {
            arr[it[0]].push_back({it[1],'R'});
        }
        for(auto it:BE)
        {
            arr[it[0]].push_back({it[1],'B'});
        }
        vector<int> Rvis(n,INT_MAX);
        vector<int> Bvis(n,INT_MAX);
        //we will do dfs from the source node and will store the distance of each node from the source
        dfs(arr,Rvis,Bvis,0,0,'R');
        dfs(arr,Rvis,Bvis,0,0,'B');
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int mn=min(Rvis[i],Bvis[i]);
            ans.push_back(mn);
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==INT_MAX)
            {
                ans[i]=tmp;
            }
        }
        return ans;
    }
};