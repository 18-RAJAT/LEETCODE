class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>q;
        long long ans=0;
        for(auto& it:gifts)
        {
            q.push(it);ans+=it;
        }
        while(k--)
        {
            int v=q.top();
            ans-=(v-sqrt(v));
            q.pop();
            q.push(sqrt(v));
        }
        return ans;
        
    }
};