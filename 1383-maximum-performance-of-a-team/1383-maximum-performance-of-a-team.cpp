class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
       vector<pair<int,int>> v;
        
       for(int i=0;i<n;i++) v.push_back({efficiency[i],speed[i]});
       sort(v.rbegin(),v.rend());
        
       long long ans = 0,spd = 0;
       priority_queue<int,vector<int>,greater<int> >pq;
        
       for(int i=0;i<n;i++){
           if(pq.size() == k){
               spd -= pq.top(); // remove minimum speed 
               pq.pop();
           }
           
           spd += v[i].second;
           pq.push(v[i].second);
           
           ans = max(ans,spd * 1LL * v[i].first);
       }
        return ans % mod;
    }
};