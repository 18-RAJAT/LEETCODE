class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        //All alphabets are containing...!!
        vector<int>label(26,0),answer;
        
        for(int i=0;i<s.length();++i)

            label[s[i]-'a'] = i; //String all the occurence of the letter
            
            int i = 0,start = 0,end = -1;
            
            while(i<s.length())
            {
                end = max(label[s[i] - 'a'],end);
                
                if(i == end)
                {
                    answer.push_back(end - start+1);
                    
                    start = end+1;
                }
                i++;
            }
        
        return answer;  
    }
};