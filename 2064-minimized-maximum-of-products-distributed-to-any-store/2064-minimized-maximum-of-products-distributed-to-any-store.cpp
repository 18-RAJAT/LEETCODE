class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=quantities.empty()?0:quantities[0];
        for(auto& it:quantities)
        {
            if(r<it)r=it;
        }
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int count=0;
            for(int i=0;i<quantities.size();++i)
            {
                count+=quantities[i]/mid;
                if(quantities[i]%mid)count++;
            }
            (count<=n)?ans=mid,r=mid-1:l=mid+1;
        }
        return ans;
    }
};