class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        int start=0,end=s1.size()-1;
        while(s2[start]==s1[start])start++;
        while(s2[end]==s1[end])end--;
        swap(s2[start],s2[end]);
        return s1==s2?true:false;
    }
};