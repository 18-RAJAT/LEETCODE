class Solution{
public:
    int rotatedDigits(int n){
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int num=i;
            bool ok=true,f=false;
            while(num>0)
            {
                int digit=num%10;
                if(digit==3 || digit==4 || digit==7)
                {
                    ok=false;
                    break;
                }
                if(digit==2 || digit==5 || digit==6 || digit==9)f=true;
                num/=10;
            }
            if(ok && f)++ans;
        }
        return ans;
    }
};