class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
		priority_queue<int>pq;
        
        int n=piles.size();
        for(int i=0;i<n;++i)
        {
            pq.push(piles[i]);
        }
        for(int i=k-1;i>=0;--i)
        {
            int tp=pq.top();
            pq.pop();
            int halfSide=tp/2;
            
            int op=abs(tp-halfSide);
            pq.push(op);
        }
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;      
    }
};