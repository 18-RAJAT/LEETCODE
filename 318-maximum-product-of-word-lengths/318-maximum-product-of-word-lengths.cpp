class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
            int answer=0;
            vector<int>tp(n);
            for(int i=0;i<n;++i)
            {
                    for(auto& ch : words[i])
                            tp[i] |= 1<<(ch-'a');
                    
                    for(int j=0;j<i;++j)
                            if((tp[i] & tp[j])==0)
                                    answer =max(answer,int(size(words[i]) * size(words[j])));
            }
            
            return answer;
    }
};