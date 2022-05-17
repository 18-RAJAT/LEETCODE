class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
         unordered_set<string>s;
            for(auto& find : words)
            {
                    string odd,even;
                    for(int i=0;i<find.size();++++i)odd+=find[i];
                    sort(odd.begin(),odd.end());
                    for(int i=1;i<find.size();++++i)even+=find[i];
                    sort(even.begin(),even.end());
                    sort(even.begin(),even.end());
                    s.insert(odd+even);
            }
           return s.size();
    }
};