class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0;
         int tp=-1;
        for(int i=0;i<arr.size();++i)
        {
            // int tp=-1;
            tp=max(arr[i],tp);
            if(tp==i)res++;
            // cout<<"1";
        }
        return res;
    }
};