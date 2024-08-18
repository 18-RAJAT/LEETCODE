class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ans;
        ans.push_back(1);
        int Two=0,Three=0,Five=0;
        while(ans.size()<n)
        {
            int v2=ans[Two]*2;
            int v3=ans[Three]*3;
            int v5=ans[Five]*5;
            int check=min(v2,min(v3,v5));
            if(check==v2)Two++;
            if(check==v3)Three++;
            if(check==v5)Five++;
            ans.push_back(check);
        }
        return ans[n-1];
    }
};