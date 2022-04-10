class Solution {
public:
    int calPoints(vector<string>& ops) {
        
             vector<int> scores;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] != "C" && ops[i] != "D" && ops[i] != "+")
                scores.push_back(stoi(ops[i]));
            else if(ops[i] == "C")
                scores.pop_back();
            else if(ops[i] == "D")
                scores.push_back(2 * scores[scores.size() - 1]);
            else if(ops[i] == "+")
                scores.push_back(scores[scores.size() - 2] + scores[scores.size() - 1]);
        }
        
        return accumulate(scores.begin(),scores.end(),0);
        
    }
};