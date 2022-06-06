class Solution {
public:
    int maximum69Number (int num) {
        string answer=to_string(num);
            for(auto &c:answer)
            if(c=='6')
            {c='9';break;}
            return stoi(answer);
    }
};
 