class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        
        for(auto it:prerequisites)
        {
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>que;
        for(int i=0;i<numCourses;++i)
        {
            if(indegree[i]==0){que.push(i);}
        }
         int count=0;
         while(!que.empty())
         {
             int value=que.front();
             que.pop();
             count++;
             
             for(auto it:graph[value])
             {
                 indegree[it]--;
                 
                 if(indegree[it]==0){que.push(it);}
             }
         }
           if(count==numCourses)return true;
        else return false;
    }
};