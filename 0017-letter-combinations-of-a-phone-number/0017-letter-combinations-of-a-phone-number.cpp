class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>path;
        vector<string>res;
        vector<string>m={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        function<void(string,int,vector<string>&,vector<string>&,vector<string>&)>dfs=[&](string digits,int index,vector<string>&path,vector<string>&res,vector<string>&m)->void
        {
            if(index==digits.size())
            {
                string temp;
                for(auto c:path)temp+=c;
                res.push_back(temp);
                return;
            }
            for(auto c:m[digits[index]-'0'])
            {
                path.push_back(string(1,c));
                dfs(digits,index+1,path,res,m);
                path.pop_back();
            }
        };
        if(digits.size()==0)return res;
        dfs(digits,0,path,res,m);
        return res;
    }
};