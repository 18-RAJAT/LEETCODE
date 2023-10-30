class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        function<int(int)> countBits=[&](int x)->int
        {
            int ctr=0;
            while(x)
            {
                ctr++;
                x&=(x-1);//removes the last set bit
            }
            return ctr;
        };
        sort(arr.begin(),arr.end(),[&](int a,int b)->bool
        {
            int x=countBits(a);
            int y=countBits(b);
            if(x==y)
            {
                return a<b?true:false;
            }
            return x<y?true:false;
        });
        return arr;
    }
};