class disjointset{
    public:
    vector<int>par, rank;
    disjointset(int n){
        par.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
    }
    int findp(int u){
        if(u==par[u]){return u;}
        return par[u]=findp(par[u]);
    }
    void un(int u, int v){
        int pu=findp(u), pv=findp(v);
        if(pu==pv){return;}
        if(rank[pu]<rank[pv]){
            par[pu]=pv;
        }
        else{
            par[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int mst(int n, vector<pair<int, pair<int, int>>>& v, pair<int, pair<int, int>>a, pair<int, pair<int, int>>b){
        disjointset d(n);
        int ans=0;
        if(a.second.first!=-1 && a.second.second!=-1){d.un(a.second.first, a.second.second); ans+=a.first;}
        //if(b.second.first!=-1 && b.second.second!=-1){d.un(b.second.first, b.second.second);}
        for(auto it: v){
            if(b!=it && (d.findp(it.second.first)!=d.findp(it.second.second))){
                ans+=it.first;
                d.un(it.second.first, it.second.second);
            }
        }
        set<int>s;
        for(int i=0; i<n; i++){s.insert(d.findp(i));}
        if(s.size()==1){return ans;}
        return INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<pair<int, pair<int, int>>>v;
        vector<vector<int>>ans;
        vector<int>c, p;
        int i=0;
        map<pair<int, int>, int>m;
        for(auto it: edges){
            v.push_back({it[2], {it[0], it[1]}});
            m[{it[0], it[1]}]=i;
            i++;
        }
        sort(v.begin(), v.end());
        int sum=mst(n, v, {-1, {-1, -1}}, {-1, {-1, -1}});
        //cout<<sum<<endl;
        for(auto it: v){
            int s1=mst(n, v, {-1, {-1, -1}}, it), s2=mst(n, v, it, {-1, {-1, -1}});
            cout<<sum<<" "<<s1<<" "<<s2<<endl;
            if(s1>sum){c.push_back(m[{it.second.first, it.second.second}]);}
            else{
                if(s2==sum){p.push_back(m[{it.second.first, it.second.second}]);}
            }
        }
        ans.push_back(c);
        ans.push_back(p);
        return ans;
    }
};