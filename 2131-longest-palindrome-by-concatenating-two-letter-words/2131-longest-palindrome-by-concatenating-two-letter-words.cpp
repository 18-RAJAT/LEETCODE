class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ch[26][26]={};
        int answer=0;
        for(auto it:words)
        {
            int x=it[0]-'a';
            int y=it[1]-'a';
            
            if(ch[x][y])
            {
                answer+=4;
                ch[x][y]--;
            }
            else
            {
                ch[y][x]++;
            }
        }
        for(int i=0;i<26;++i)
        {
            if(ch[i][i])
            {
                answer+=2;
                break;
            }
        }
        return answer;
    }
};