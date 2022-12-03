class Solution {
public:
    string frequencySort(string s) {
        // sort(s.begin(),s.end());
        map<int,int>used;
        // char ch;
        // int n=s.length();
        // for(int i=0;i<n;++i)
        for(auto it:s)
        {
            used[it]++;
        }
        // {
        //     for(int j=0;j<n-1;++j)
        //     {
        //         if(s[j+1]<s[j])
        //         {
        //             ch=s[j];
        //             s[j]=s[j+1];
        //             s[j+1]=ch;
        //         }
        //     }
        // }
        sort(s.begin(),s.end(),[&](auto a,auto b)
             {
                 if(used[a]!=used[b])
                 {
                     return used[a]>used[b];
                 }
                 else
                 {
                     return a>b;
                 }
             });
        // return s;
        return s;
    }
};