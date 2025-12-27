class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int x=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long>room(n,0),count(n,0);
        for(int i=0;i<x;++i)
        {
            long long minimum=LONG_MAX;
            int index=0;
            bool ok=false;
            for(int j=0;j<n;++j)
            {
                if(minimum>room[j])
                {
                    minimum=room[j];
                    index=j;
                }
                if(room[j]<=meetings[i][0])
                {
                    room[j]=meetings[i][1];
                    count[j]++;
                    ok=true;
                    break;
                }
            }
            if(ok==false)
            {
                room[index]+=(long long)(meetings[i][1]-meetings[i][0]);
                count[index]++;
            }
        }
        int room_no=0;
        long long max_meeting=0;
        for(int i=0;i<n;++i)
        {
            if(count[i]>max_meeting)
            {
                room_no=i;
                max_meeting=count[i];
            }
        }
        return room_no;
    }
};