class Solution {
public:
    bool check(vector<int>& freq,string& s)
    {
        vector<int>letters(26,0);
        for(auto& it:s)
        {
            letters[it-'a']++;
        }
        for(int i=0;i<26;++i)
        {
            if(freq[i]<letters[i])
            {
                return false;
            }
        }
        return true;
    }
    int sol(vector<string>& words,vector<int>& freq,vector<int>& score,int i)
    {
        if(words.size()<=i)return 0;
        if(check(freq,words[i]))
        {
            int curr_score=0,ans1=0,ans2=0;
            for(auto& it:words[i])
            {
                curr_score+=score[it-'a'];
                freq[it-'a']--;
            }
            ans1=sol(words,freq,score,i+1)+curr_score;
            for(auto& it:words[i])freq[it-'a']++;
            ans2=sol(words,freq,score,i+1);
            return max(ans1,ans2);
        }
        else
        {
            return sol(words,freq,score,i+1);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(auto& it:letters) 
        {
            freq[it-'a']++;
        }
        return sol(words,freq,score,0);
    }
};