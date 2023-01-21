class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int n=s.size();
        for(int i=1;i<=3;i++)
        {
            for(int j=i+1;j<=i+3;j++)
            {
                for(int k=j+1;k<=j+3;k++)
                {
                    if(k>=n)break;
                    string a=s.substr(0,i);
                    string b=s.substr(i,j-i);
                    string c=s.substr(j,k-j);
                    string d=s.substr(k,n-k);
                    if(a.size()>3 or b.size()>3 or c.size()>3 or d.size()>3)continue;
                    if(a.size()>1 and a[0]=='0')continue;
                    if(b.size()>1 and b[0]=='0')continue;
                    if(c.size()>1 and c[0]=='0')continue;
                    if(d.size()>1 and d[0]=='0')continue;
                    if(stoi(a)>255 or stoi(b)>255 or stoi(c)>255 or stoi(d)>255)continue;
                    ans.push_back(a+"."+b+"."+c+"."+d);
                }
            }
        }
        return ans;      
    }
};