class Solution {
public:
    int maxUniqueSplit(string s) {
        map<string,int>ans;
        function<int(int,string&,map<string,int>&)>unique_substrings=[&](int i,string& s,map<string,int>res)->int
        {
            int n=s.size();
            if(n<=i)
            {
                return 0;
            }
            string current_char="";
            int maximum_number=0;
            for(int j=i;j<n;++j)
            {
                current_char+=s[j];
                if(res[current_char]==0)
                {
                    res[current_char]=1;
                    int recur=1+unique_substrings(j+1,s,res);
                    maximum_number=max<int>(maximum_number,recur);
                    res[current_char]=0;
                }
            }
            return maximum_number;
        };
        ans.clear();
        return unique_substrings(0,s,ans);
    }
};  