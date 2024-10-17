class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int> arr(10,-1);
        for(int i=0;i<n;++i)
        {
            arr[s[i]-'0']=i;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=9;j>s[i]-'0';--j)
            {
                if(arr[j]>i)
                {
                    swap(s[i],s[arr[j]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};