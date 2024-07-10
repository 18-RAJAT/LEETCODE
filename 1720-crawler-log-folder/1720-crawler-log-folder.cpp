class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operation=0;
        for(auto& it:logs)
        {
            if(it=="../" && operation)operation--;
            else if(it!="./" && it!="../")operation++;
        }
        return operation;
    }
};