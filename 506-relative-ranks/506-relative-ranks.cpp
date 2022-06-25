class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<score.size();++i)
        
          pq.push({score[i],i});   
        
        vector<string>ans(score.size());
        
        string temp;
        int count=1;
        
        while(pq.size())
        {
            auto[score,i]=pq.top();pq.pop();
            temp = to_string(count);

            if(count == 1)
            {temp = "Gold Medal";}
            
            else if(count == 2)
            {temp = "Silver Medal";}
            
            else if(count == 3)
            {temp = "Bronze Medal";}
            
            ans[i]=temp;count++;
        }
        return ans; 
    }
};