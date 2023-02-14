namespace
{
    pair<int,string>Get(int n)
    {
        vector<pair<int,string>>dataSet=
        {
            {1000,"M"},
            {900,"CM"},
            {500,"D"},
            {400,"CD"},
            {100,"C"},
            {90,"XC"},
            {50,"L"},
            {40,"XL"},
            {10,"X"},
            {9,"IX"},
            {5,"V"},
            {4,"IV"},
            {1,"I"},
        };
        for(pair<int,string>it:dataSet)
        {
            int f=it.first;
            if(n-f>=0)
            {
                return{n-f,it.second};
            }
        }
        assert(false);
        return{0,""};
    }
}
class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while(num!=0)
        {
            pair<int,string>p=Get(num);
            num=p.first;
            ans.append(p.second);
        }
        return ans;
    }
};