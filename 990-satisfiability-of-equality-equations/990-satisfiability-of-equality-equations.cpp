class Solution {
public:
    int ch[26];
    bool equationsPossible(vector<string>& equations) {
        // int n=equations.size();
        // vector<int>parent(26);
        // for(int i=0;i<26;i++)
        //     parent[i]=i;
        // for(int i=0;i<n;i++)
        // {
        //     if(equations[i][1]=='=')
        //     {
        //         int x=equations[i][0]-'a';
        //         int y=equations[i][3]-'a';
        //         int p1=find(x,parent);
        //         int p2=find(y,parent);
        //         if(p1!=p2)
        //             parent[p1]=p2;
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(equations[i][1]=='!')
        //     {
        //         int x=equations[i][0]-'a';
        //         int y=equations[i][3]-'a';
        //         int p1=find(x,parent);
        //         int p2=find(y,parent);
        //         if(p1==p2)
        //             return false;
        //     }
        // }
        // return true;
        
        for(int i=0;i<26;++i)ch[i]=i;
        for(auto eq:equations)
            if(eq[1]=='=')
                ch[find(eq[0]-'a')]=find(eq[3]-'a');
        for(auto eq:equations)
            if(eq[1]=='!' and find(eq[0]-'a')==find(eq[3]-'a')) return 0;
        return 1;
    }
    
    int find(int x)
    {
        if(x!=ch[x])ch[x]=find(ch[x]);return ch[x];
    }
};