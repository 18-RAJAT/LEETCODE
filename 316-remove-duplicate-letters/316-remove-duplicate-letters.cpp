class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        unordered_map<char,int>last_idx;
        
        vector<bool>visited(26);
        string answer = "";
        
        for(int i=0;i<s.size();++i)

            last_idx[s[i]] = i; //Storing the last index of each character...!
        
        for(int i=0;i<s.size();++i)
        {
            //If index is visited...!
            if(visited[s[i] - 'a'])
                continue;
        
        while(!answer.empty() and answer.back() > s[i] and last_idx[answer.back()] > i)
        {  
            visited[answer.back()-'a'] = false;
            answer.pop_back();
        }
        
        answer.push_back(s[i]);  //Adding the current element we will be get...!
            
        visited[s[i]-'a'] = true;  //Marking the current node is visited...!
       }
        
            return answer;   
    }
};