class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        deque<int>q;
        q.push_back(deck.back());
        for(int i=deck.size()-2;~i;--i)
        {
            q.push_front(q.back());
            q.pop_back();
            q.push_front(deck[i]);
        }
        vector<int>ans;
        for(int i=0;i<deck.size();++i)
        {
            ans.push_back(q[i]);
        }
        return ans;
    }
};