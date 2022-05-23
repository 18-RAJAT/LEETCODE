class Solution {
public:
    int strStr(string f, string needle) {
        if(needle==" "){return 0;}
            int found=f.find(needle);return found;
            if(found!=string::npos){return -1;}
      
    }
};