class Solution {
public:
    vector<long long>mnT,mxT,ar;
    void push(int idx,int l,int r)
    {
        if(ar[idx]!=0)
        {
            mnT[idx]+=ar[idx];
            mxT[idx]+=ar[idx];
            if(l<r)
            {
                ar[2*idx]+=ar[idx],ar[2*idx+1]+=ar[idx];
            }
            ar[idx]=0;
        }
    }
    void update(int l,int r,int idx,int delta,int L,int R)
    {
        push(idx,L,R);
        if(L>r || R<l)return;
        if(l<=L && r>=R)
        {
            ar[idx]+=delta;
            push(idx,L,R);
            return;
        }
        long long mid=(L+R)/2;
        update(l,r,2*idx,delta,L,mid);
        update(l,r,2*idx+1,delta,mid+1,R);
        mnT[idx]=min(mnT[2*idx],mnT[2*idx+1]);
        mxT[idx]=max(mxT[2*idx],mxT[2*idx+1]);
    }
    int recur(int l,int r,int idx,int L,int R)
    {
        push(idx,L,R);
        if(L>r || R<l)return -1;
        if(mnT[idx]>0 || mxT[idx]<0)return -1;
        if(L==R)
        {
            if(mnT[idx]==0)
            return L;
        }
        long long mid=(L+R)/2;
        int tmp=recur(l,r,2*idx,L,mid);
        if(~tmp)return tmp;
        int ok=recur(l,r,2*idx+1,mid+1,R);
        return ok;
    }
    void init(int n)
    {
        mnT.resize(4*(n),0);
        mxT.resize(4*(n),0);
        ar.resize(4*(n),0);
    }
    int longestBalanced(vector<int>& nums) {
        init(nums.size());
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            int l=-1,r=i;
            auto it=mp.find(nums[i]);
            if(it!=mp.end())l=it->second;l++;
            if(nums[i]&1)update(l,r,1,1,0,nums.size()-1);
            else update(l,r,1,-1,0,nums.size()-1);
            mp[nums[i]]=i;
            int id=recur(0,r,1,0,nums.size()-1);
            if(~id)ans=max(ans,i-id+1);
        }
        return ans;
    }
};