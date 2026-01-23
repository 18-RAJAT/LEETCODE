class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        vector<long long>arr(n);
        for(int i=0;i<n;++i)arr[i]=nums[i];
        vector<int>left(n,-1),right(n,-1);
        for(int i=0;i<n;++i)
        {
            if(i>0)left[i]=i-1;
            if(i<n-1)right[i]=i+1;
        }
        vector<bool>chk(n,true);
        int rem=0;
        for(int i=0;i<n-1;++i)
        {
            if(arr[i]>arr[i+1])rem++;
        }
        if(rem==0)return 0;
        vector<int>nwPairs(n,0);
        using T=tuple<long long,int,int>;
        auto cmp=[&](T& a,T& b)
        {
            if(get<0>(a)!=get<0>(b))return get<0>(a)>get<0>(b);
            return get<1>(a)>get<1>(b);
        };
        priority_queue<T,vector<T>,decltype(cmp)>pq(cmp);
        for(int i=0;i<n-1;++i)
        {
            pq.emplace(arr[i]+arr[i+1],i,nwPairs[i]);
        }
        int ans=0;
        while(rem>0 && !pq.empty())
        {
            auto [sum,i,nw]=pq.top();
            pq.pop();
            int j=right[i];
            if(j==-1 || !chk[i] || !chk[j] || nw!=nwPairs[i])continue;

            int l=left[i],r=right[j];
            int Prev=0;
            if(~l && chk[l] && arr[l]>arr[i])Prev++;
            if(arr[i]>arr[j])Prev++;
            if(~r && chk[r] && arr[j]>arr[r])Prev++;
            long long tot=arr[i]+arr[j];
            arr[i]=tot,chk[j]=false;
            right[i]=r;
            if(~r)left[r]=i;
            int count=0;
            if(~l && chk[l] && arr[l]>arr[i])count++;
            if(~r && chk[r] && arr[i]>arr[r])count++;
            rem=rem-Prev+count;
            ans++;
            if(~l && right[l]==i && chk[l])
            {
                nwPairs[l]++;
                pq.emplace(arr[l]+arr[i],l,nwPairs[l]);
            }
            // for(auto& it:left)
            // {
            //     if(it==j)it=i;
            //     cout<<"Checking "<<it<<endl;
            //     if(it==-1)continue;
            //     if(chk[it] && arr[it]>arr[i])
            //     {
            //         nwPairs[it]++;
            //         pq.emplace(arr[it]+arr[i],it,nwPairs[it]);
            //     }
            //     cout<<"Nw->> "<<it<<" "<<nwPairs[it]<<endl;
            // }
            if(~right[i])
            {
                nwPairs[i]++;
                pq.emplace(arr[i]+arr[right[i]],i,nwPairs[i]);
            }
        }
        return ans;
    }
};