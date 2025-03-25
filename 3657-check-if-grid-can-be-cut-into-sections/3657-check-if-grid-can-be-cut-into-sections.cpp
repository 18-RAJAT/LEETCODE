class Solution{
public:
    bool canPartition(int s,int e,vector<vector<int>>&rectangles)
    {
        vector<vector<int>>arr=rectangles;
        sort(arr.begin(),arr.end(),[&](vector<int>&a,vector<int>&b)->bool
        {
            if(a[s]!=b[s])return a[s]<b[s];
            return a[e]<b[e];
        });
        int m=arr.size();
        vector<int>pref(m,0),suf(m,0),ans;
        
        pref[0]=arr[0][e];
        for(int i=1;i<m;++i)pref[i]=max(pref[i-1],arr[i][e]);
        
        suf[m-1]=arr[m-1][s];
        for(int i=m-2;~i;--i)suf[i]=min(suf[i+1],arr[i][s]);
        
        for(int i=1;i<m;++i)
        {
            if(pref[i-1]<=suf[i])ans.push_back(i);
        }
        return ans.size()>=2;
    }
    bool checkValidCuts(int n,vector<vector<int>>&rectangles){
        return canPartition(1,3,rectangles) || canPartition(0,2,rectangles);
    }
};