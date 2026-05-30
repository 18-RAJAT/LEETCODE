class SegmentTree{
public:
    int n;
    vector<int>seg;

    SegmentTree(int sz){
        n=1;
        while(n<sz)n<<=1;
        seg.assign(2*n,0);
    }

    void update(int pos,int val,int node,int l,int r){
        if(r-l==1){
            seg[node]=val;
            return;
        }

        int mid=(l+r)/2;

        if(pos<mid)update(pos,val,2*node+1,l,mid);
        else update(pos,val,2*node+2,mid,r);

        seg[node]=max(seg[2*node+1],seg[2*node+2]);
    }

    void update(int pos,int val){
        update(pos,val,0,0,n);
    }

    int query(int ql,int qr,int node,int l,int r){
        if(r<=ql||l>=qr)return 0;
        if(ql<=l&&r<=qr)return seg[node];

        int mid=(l+r)/2;

        return max(
            query(ql,qr,2*node+1,l,mid),
            query(ql,qr,2*node+2,mid,r)
        );
    }

    int query(int l,int r){
        return query(l,r,0,0,n);
    }
};

class Solution{
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx=0;
        for(auto& it:queries)
        {
            mx=max(mx,it[1]);
        }
        SegmentTree st(mx+5);
        set<int>pos;
        pos.insert(0);
        pos.insert(mx+1);
        st.update(mx+1,mx+1);
        for(auto& it:queries)
        {
            if(it[0]==1)
            {
                int x=it[1];
                auto jt=pos.upper_bound(x);
                int r=*jt,l=*prev(jt);
                st.update(r,r-x);
                st.update(x,x-l);
                pos.insert(x);
            }
        }
        vector<bool>ans;
        pos.clear();
        pos.insert(0);
        pos.insert(mx+1);
        SegmentTree seg(mx+5);
        seg.update(mx+1,mx+1);
        for(auto& it:queries)
        {
            if(it[0]==1)
            {
                int x=it[1];
                auto jt=pos.upper_bound(x);
                int r=*jt,l=*prev(jt);
                seg.update(r,r-x);
                seg.update(x,x-l);
                pos.insert(x);
            }
            else
            {

                int x=it[1],sz=it[2];
                auto jt=pos.upper_bound(x);
                int l=*prev(jt);
                int best=seg.query(0,l+1);
                ans.push_back(max(best,x-l)>=sz);
            }
        }
        return ans;
    }
};