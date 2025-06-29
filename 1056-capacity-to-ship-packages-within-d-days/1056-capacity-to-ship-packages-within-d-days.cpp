class Solution {
public:
    int maxDays(vector<int>&weights,int n)
    {
        int check=0,days=1;
        for(int i=0;i<weights.size();++i)
        {
            if(n<check+weights[i])++days,check=weights[i];
            else check+=weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>&weights,int days){
        int l=*max_element(weights.begin(),weights.end()),r=1e9;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(maxDays(weights,m)<=days)r=m;
            else l=m;
        }
        return (maxDays(weights,l)<=days?l:r);
    }
};