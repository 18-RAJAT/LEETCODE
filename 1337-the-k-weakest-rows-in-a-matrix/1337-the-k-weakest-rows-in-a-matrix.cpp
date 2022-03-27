class Solution {
public:
    
    int countOne(vector<int>arr)
    {
        if(arr[0] == 0)
        {
            return 0;
        }
        
        int answer = 0;
        int start = 0;
        int end = arr.size()-1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(arr[mid] == 1)
            {
                answer = mid;
                
                start = mid + 1;
            }
            else
            {
                end = mid - 1;   // This Count of 1 is index of last one + 1 
            }
        }
        
        return answer + 1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        //Using priority_queue = max heap
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<mat.size();++i)
        {
        
        pq.push({countOne(mat[i]),i});
        
        if(pq.size() > k)
         pq.pop();
            
         }
        
        vector<int> answer;               
        while (pq.size() > 0)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        //Then reverse
        reverse(answer.begin(),answer.end());
            
        return answer;
        
    }
};