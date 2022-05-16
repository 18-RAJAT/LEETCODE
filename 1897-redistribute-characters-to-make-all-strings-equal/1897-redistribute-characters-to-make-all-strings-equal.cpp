class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
            unordered_map<char,int>m;int n=words.size();
            if(n==1){return true;}
            for(int i=0;i<n;++i)
            {
                 for(char c:words[i]){m[c]++;}
            }
            for(auto p:m){if(p.second%n!=0) {return false;}}
            return true;
    }
};
