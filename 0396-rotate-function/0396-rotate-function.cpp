class Solution{
public:
    int maxRotateFunction(vector<int>&arr){
        int ans=0,f=0,sum=0,n=arr.size();
        for(int i=0;i<n;++i)
        {
            f+=(i*arr[i]);
            sum+=arr[i];
        }
        ans=f;
        for(int i=1;i<n;++i)
        {
            f=f+sum-(n*arr[n-i]);
            ans=max(ans,f);
        }
        return ans;
    }
};