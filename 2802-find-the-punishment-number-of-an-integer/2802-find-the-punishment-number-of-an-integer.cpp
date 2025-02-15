class Solution {
public:
    int punishmentNumber(int n) {
        function<int(int,string&,int,int)>steps=[&](int i,string& s,int n,int sum)->int
        {
            if(i==s.size())
            {
                if(sum==n)return 1;
                return 0;
            }
            int cnt=0;
            for(int j=i;j<s.size();++j)
            {
                int num=stoi(s.substr(i,j-i+1)),tot=num+sum;
                cnt+=steps(j+1,s,n,tot);
            }
            return cnt;
        };
        function<int(int)>Sum=[&](int n)->int
        {
            string s=to_string(n*n);
            return steps(0,s,n,0);
        };
        int res=0;
        for(int i=1;i<=n;++i)
        {
            if(Sum(i))res+=i*i;
        }
        return res;
    }
};