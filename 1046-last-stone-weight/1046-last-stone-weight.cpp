class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>Max_Heap;
        
        int n = stones.size();

        for(int i=0;i<n;++i)
        {
            Max_Heap.push(stones[i]);
        }
        
        int first,second;
        
        while(n > 1)
        {
            first = Max_Heap.top();
            Max_Heap.pop();
            
            second = Max_Heap.top();
            Max_Heap.pop();
            
            n = n-2;
            
            if(first - second > 0)
            {
                Max_Heap.push(first - second);
                
                n = n + 1;
            }
        }
        
        if(!Max_Heap.empty())
        {
            return Max_Heap.top();
        }
        return 0;
    }
};