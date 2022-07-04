class Solution {
public:
    int candy(vector<int>& r) {
       int n=r.size();
        if(n==1){return 1;}
        vector<int>v(n,1),v1(n,1);
        for(int i=1;i<n;++i)
        {
            // cout<<"1";
            if(r[i]>r[i-1]){v[i]=v[i-1]+1;}
        }
        for(int i=n-2;i>=0;--i)
        {
            // cout<<"2";
            if(r[i]>r[i+1]){v1[i]=v1[i+1]+1;}
        }
        int answer=0;
        for(int i=0;i<n;++i){answer+=max(v[i],v1[i]);}
        return answer;
    }
};