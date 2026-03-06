class Solution {
public:
    bool checkOnesSegment(string s) {
        int ok=0;
        for(auto& it:s)
        {
            if(it=='0')ok=1;
            if(it=='1' && ok)return 0;
        }
        return 1;
    }
};