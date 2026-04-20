class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(),i=0,color=colors[0];
        while(colors[i]==colors[n-1-i] && colors[i]==color)i++;
        return n-1-i;
    }
};