typedef long long ll;
ll mod = 1000000007;
#define f first
#define s second
#define ss string
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define pp pair<int, p>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvs vector<vs>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound

class Solution {
public:
    
    bool check(ss k, ss t){
        int count = 0;
        rep(i, k.size()){
            if(k[i] != t[i]){
                count++;
            }
        }
        if(count == 1){
            return true;
        }
        return false;
    }
    
    int bfs(int st, vv &a, int l, int x){
        queue<int> q;
        q.push(st);
        vb vis(x, false);
        v level(x, -1);
        level[st] = 0;
        vis[st] = true;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            rep(j, a[i].size()){
                if(!vis[a[i][j]]){
                    q.push(a[i][j]);
                    vis[a[i][j]] = true;
                    level[a[i][j]] = level[i] + 1;
                    if(a[i][j] == l){
                        return level[a[i][j]];
                    }
                }
            }
        }
        return -1;
    }
    
    int minMutation(string start, string end, vector<string>& b){
        unordered_map<ss, int> map;
        map[start] = 1;
        int x = 2, n = b.size(), l;
        rep(i, n){
            if(map[b[i]] == 0){
                map[b[i]] = x;
                x++;
            }
        }
        vv a(x);
        b.pb(start);
        rep(i, n){
            repa(j, i+1, n){
                if(check(b[i], b[j])){
                    a[map[b[i]]].pb(map[b[j]]);
                    a[map[b[j]]].pb(map[b[i]]);
                }
            }
        }
        if(map[end] == 0){
            l = x+10;
        }
        else{
            l = map[end];   
        }
        return bfs(1, a, l, x);
    }
};