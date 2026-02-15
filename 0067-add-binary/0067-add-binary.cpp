class Solution {
public:
    string addBinary(string a, string b) {
        function<char(char,char,char&)>add=[](char x,char y,char& carryBt)->char
        {
            int X=x-'0';
            int Y=y-'0';
            int C=carryBt-'0';
            int sum=X+Y+C;
            carryBt=sum/2+'0';
            return sum%2+'0';
        };
        if(a.size()<b.size())
        {
            a=string(b.size()-a.size(),'0')+a;
        }
        else
        {
            b=string(a.size()-b.size(),'0')+b;
        }
        string ans;
        char carry='0';
        for(int i=a.size()-1;i>=0;--i)
        {
            ans=add(a[i],b[i],carry)+ans;
        }
        if(carry=='1')
        {
            ans=carry+ans;
        }
        return ans;
    }
};