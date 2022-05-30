typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
            if(dividend==divisor){
            return 1;
        }
        if(divisor>0&&dividend>=0&&divisor>dividend){
            return 0;
        }   
        if(divisor==1){
            return dividend;
        }
        if(divisor==-1){
            if(dividend==INT_MIN){
                dividend+=1;
            }
            return -1*dividend;
        }
        ll n=abs((ll)dividend);
        ll m=abs((ll)divisor);
        ll t=m; //used for shifting
        ll count=0;
        
        for(int i=31;i>=0;i--){
            if((t<<i)<=n){
                t=t<<i;
                count=1<<i;
                break;
            }
        }
        while(t+m<=n){
            t+=m;
            count++;
        }
        if(dividend<=0&&divisor>0||dividend>=0&&divisor<0){
            return -1*count;
        }
        return (int)count;
    }
};