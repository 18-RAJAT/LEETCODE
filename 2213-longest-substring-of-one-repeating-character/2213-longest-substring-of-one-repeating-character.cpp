class Solution{
public:
    class SegmentTree
    {
    public:
        string s;
        vector<vector<int>>seg;
        SegmentTree(string s)
        {
            this->s=s;
            int n=s.length();
            seg.resize(4*n,vector<int>(3));
        }
        void build(int i,int j,int idx=0)
        {
            if(i==j)
            {
                seg[idx]={1,1,1};
                return;
            }
            int mid=(i+j)/2;
            int left=idx*2+1,right=idx*2+2;
            build(i,mid,left);
            build(mid+1,j,right);
            seg[idx][0]=seg[left][0];
            seg[idx][1]=max(seg[left][1],seg[right][1]);
            seg[idx][2]=seg[right][2];
            if(s[mid]==s[mid+1])
            {
                seg[idx][1]=max(seg[idx][1],seg[left][2]+seg[right][0]);
                if(seg[left][0]==mid-i+1)seg[idx][0]=seg[left][0]+seg[right][0];
                if(seg[right][2]==j-mid)seg[idx][2]=seg[right][2]+seg[left][2];
            }
        }
        int ch,Idx;
        void query(int i,int j,int idx=0)
        {
            if(Idx<i||Idx>j)return;
            if(i==j)
            {
                s[Idx]=ch;
                return;
            }
            int mid=(i+j)/2;
            int left=idx*2+1,right=idx*2+2;
            query(i,mid,left);
            query(mid+1,j,right);
            seg[idx][0]=seg[left][0];
            seg[idx][1]=max(seg[left][1],seg[right][1]);
            seg[idx][2]=seg[right][2];
            if(s[mid]==s[mid+1])
            {
                seg[idx][1]=max(seg[idx][1],seg[left][2]+seg[right][0]);
                if(seg[left][0]==mid-i+1)seg[idx][0]=seg[left][0]+seg[right][0];
                if(seg[right][2]==j-mid)seg[idx][2]=seg[right][2]+seg[left][2];
            }
        }
    };
    vector<int>longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.length();
        SegmentTree st(s);
        st.build(0,n-1);
        vector<int>ans;
        int q=queryCharacters.size();

        for(int i=0;i<q;++i)
        {
            st.Idx=queryIndices[i];
            st.ch=queryCharacters[i];
            st.query(0,n-1);
            ans.push_back(st.seg[0][1]);
        }
        return ans;
    }
};