class Solution {
private:
    unordered_map<string,int>mp;
    vector<vector<double>>graph;
    
public:
    Solution() 
    {
        mp.clear();
        graph.clear();
    }
    
    ~Solution() 
    {
        mp.clear();
        graph.clear();
    }
    
    vector<double>calcEquation(vector<vector<string>>& equations,vector<double>& values, vector<vector<string>>& queries) 
    {
        buildGraph(equations,values);
        floydWarshall();
        return evaluateQueries(queries);
    }
    
private:
    void buildGraph(vector<vector<string>>& equations,vector<double>& values) {
        int n=equations.size();
        int count=0;
        for(int i=0;i<n;++i)
        {
            if(mp.find(equations[i][0])==mp.end())
            {
                mp[equations[i][0]]=count;
                count++;
            }
            if(mp.find(equations[i][1])==mp.end())
            {
                mp[equations[i][1]]=count;
                count++;
            }
        }
        graph.resize(count,vector<double>(count,-1.0));
        for(int i=0;i<n;++i)
        {
            int src=mp[equations[i][0]];
            int dest=mp[equations[i][1]];
            
            graph[src][dest]=values[i];
            graph[dest][src]=1.0/values[i];
        }
    }
    void floydWarshall()
    {
        double vals=-1.0;
        for(int k=0;k<graph.size();++k)
        {
            for(int i=0;i<graph.size();++i)
            {
                for(int j=0;j<graph.size();++j)
                {
                    if(graph[i][k]!=vals and graph[k][j]!=vals)
                    {
                        graph[i][j]=graph[i][k]*graph[k][j];
                    }
                }
            }
        }
    }
    vector<double>evaluateQueries(vector<vector<string>>& query)
    {
        vector<double>res;
        for(auto& it:query)
        {
            if(mp.find(it[0])==mp.end() or mp.find(it[1])==mp.end())
            {
                res.push_back(-1.0);
                continue;
            }
            int u=mp[it[0]];
            int v=mp[it[1]];
            res.push_back(graph[u][v]);
        }
        return res;
    }
};