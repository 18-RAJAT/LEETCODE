class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0,j=0;
        int sum=0,ans=0,res=0;
        for(;j<grumpy.size();)
        {
            (grumpy[j]==0)?sum+=customers[j]:ans+=customers[j];
            if(j-i+1==minutes)
            {
                res=max(res,ans);
                if(grumpy[i]==1)
                {
                    ans-=customers[i];
                }
                i++;
            }
            j++;
            
        }
        return sum+res;
    }
};