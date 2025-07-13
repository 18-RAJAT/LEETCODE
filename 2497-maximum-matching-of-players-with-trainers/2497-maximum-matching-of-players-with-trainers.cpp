class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i=0,j=0,count=0;
        while(i<players.size() && j<trainers.size())
        {
            ((players[i]<=trainers[j])?count++,i++,j++:j++);
        }
        return count;
    }
};