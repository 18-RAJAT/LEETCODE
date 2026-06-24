class Solution {
public:
    static const int MOD=1e9+7;
    using Matrix=vector<vector<long long>>;
    Matrix multiply(const Matrix& ar,const Matrix& br)
    {
        int n=ar.size();
        Matrix res(n,vector<long long>(n,0));
        for(int i=0;i<n;++i)
        {
            for(int k=0;k<n;++k)
            {
                if(ar[i][k]==0)continue;
                for(int j=0;j<n;++j)
                {
                    if(br[k][j]==0)continue;
                    res[i][j]=(res[i][j]+ar[i][k]*br[k][j])%MOD;
                }
            }
        }
        return res;
    }
    Matrix power(Matrix ar,long long exp)
    {
        int n=ar.size();
        Matrix res(n,vector<long long>(n,0));
        for(int i=0;i<n;++i)res[i][i]=1;
        while(exp)
        {
            if(exp&1)
            {
                res=multiply(res,ar);
            }
            ar=multiply(ar,ar);
            exp>>=1;
        }
        return res;
    }
    vector<long long>MulMat(const Matrix& ar,const vector<long long>& v)
    {
        int n=ar.size();
        vector<long long>res(n,0);
        for(int i=0;i<n;++i)
        {
            long long cur=0;
            for(int j=0;j<n;++j)cur=(cur+ar[i][j]*v[j])%MOD;
            res[i]=cur;
        }
        return res;
    }
    int zigZagArrays(long long n,int l,int r)
    {
        int m=r-l+1;
        if(n==1)return m;
        int sz=2*m;
        Matrix dp(sz,vector<long long>(sz,0));
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<i;++j)
            {
                dp[i][m+j]=1;
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int j=i+1;j<m;++j)
            {
                dp[m+i][j]=1;
            }
        }
        vector<long long>base(sz,0);
        for(int i=0;i<m;++i)
        {
            base[i]=i;
            base[m+i]=m-1-i;
        }
        if(n==2)
        {
            long long ans=0;
            for(auto& it:base)ans=(ans+it)%MOD;
            return ans;
        }
        Matrix pw=power(dp,n-2);
        vector<long long>state=MulMat(pw,base);
        long long ans=0;
        for(auto& it:state)
        {
            ans=(ans+it)%MOD;
        }
        return ans;
    }
};