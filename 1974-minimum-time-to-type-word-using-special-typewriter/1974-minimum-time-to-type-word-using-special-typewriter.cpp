class Solution {
public:
    int minTimeToType(string word) {
        int result=word.size();
            int pointer='a';
            for(auto w:word)
            {
                    result=result+min(abs(w-pointer),26-abs(pointer-w));
                    pointer=w;
            }
            return result;
    }
};