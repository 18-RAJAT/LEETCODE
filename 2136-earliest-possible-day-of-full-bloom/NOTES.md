**class Solution {
public:
int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
int n = plant.size();
vector<pair<int,int>> v;
for(int i=0; i<n; i++)
v.push_back({grow[i], plant[i]});
sort(v.begin(), v.end());
int ans=0;
for(int i=0; i<n; i++){
ans = max(ans, v[i].first);
ans += v[i].second;
}
return ans;
}
};**