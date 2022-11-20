typedef vector<int> vi;
#define fl(a,b) for(int i=a;i<b;i++)
#define pb push_back

class Solution {
public:
    void helper(vi& result,int n,int tp)
    {
        // for(int i=0;i<10;++i)
        // {
        //     int st=i+tp;
        //     if(st>n and result.size()>=n){break;}
        //     result.pb(st);
        //     helper(result,n,st*10);
        // }
        if(tp>n)return;
        result.pb(tp);
        
        helper(result,n,tp*10);
        if(tp%10!=9)
        {
            helper(result,n,tp+1);
        }
    }
    
        vi lexicalOrder(int n) {
        vi result;
        // if(n<=0){return result;}
        // result.reserve(n);
        // helper(result,n,1);
        // return result;
        helper(result,n,1);
        return result;
    }
};