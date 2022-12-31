class Solution {
public:
    bool check(vector<int>&price,int n,int tastiness,int k)
    {
        int baskets=1;
        int lastPosBasket=price[0];//initial
        
        for(int i=0;i<n;++i)
        {
            if(tastiness<=abs(price[i]-lastPosBasket))
            {
                   baskets++;
                   lastPosBasket=price[i];
                   
                   if(baskets==k)
                   {
                       return true;
                   }
             }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int l=1;
        int h=price[n-1]-price[0];
        int ans=0;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(check(price,n,mid,k))
            {
                ans=mid;
                l=mid+1;
                
                // cout<<l<<" "<<ans<<"\n";
            }
            else
            {
                h=mid-1;
                // cout<<h<<" "<<ans<<"\n";
            }
        }
        return ans;
    }
};