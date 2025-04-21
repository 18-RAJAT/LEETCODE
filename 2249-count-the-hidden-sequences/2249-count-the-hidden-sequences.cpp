class Solution{
public:
    int numberOfArrays(vector<int>&differences,int lower,int upper){ 
        long long mn=0,mx=0,sum=0;
        for(auto& it:differences)
        {
            sum+=it;
            mn=min(sum,mn),mx=max(sum,mx);
        }
        long L=upper-mx,R=lower-mn;
        return((L-R+1)>0)?(L-R+1):0;
    }
};