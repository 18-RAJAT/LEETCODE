class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle==""){return 0;}
            cout<<"YES";
            int found=haystack.find(needle);
            return found;
            if(found!=string::npos){return -1;}
    }
};