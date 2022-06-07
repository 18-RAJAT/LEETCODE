// bool compare(vector<int>&a,vector<int>&b)
// {
//         return(a[0]<b[0]);
// }
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            vector<vector<int>>answer;
            
        sort(people.begin(),people.end(),[](auto& a,auto& b) 
    {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    for(auto & p : people)
            answer.insert(answer.begin()+p[1],p);
        return answer;
}
};
