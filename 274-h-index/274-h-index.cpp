class Solution {
public:
    int hIndex(vector<int>& c) {
        int length=c.size();
        if(length==0){return 0;}
        sort(c.begin(),c.end(),[](int a,int b){return a>b;});
        int result=0;
        for(int i=0;i<length;++i)
        {
            result=max(result,min(i+1,c[i]));
        }
        return result;
    }
};
