class Solution {
public:
    int fillCups(vector<int>& a) {
        int answer=0;
        while(true)
        {
            sort(a.begin(),a.end());
            if(a[2]==0){break;}
            if(a[1]==0){answer=answer+a[2];break;}
            a[1]--;a[2]--;answer++;
        }
        return answer;
    }
};