class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    
        if(n==0){return tasks.size();}
        int freq[26] = {0};
        int maxFreq = INT_MIN;
        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]-'A']++;
            maxFreq = max(maxFreq,freq[tasks[i]-'A']);
        }
        
        int maxFreqCount  = 0;
        for(int i=0;i<26;i++){if(freq[i]==maxFreq){maxFreqCount++;}}
        
        return max((int)tasks.size(),(maxFreq-1)*(n+1)+maxFreqCount);
    }
};

     