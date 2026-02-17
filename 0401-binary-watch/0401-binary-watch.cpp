class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<12;++i)//hour
        {
            for(int j=0;j<60;++j)//minute
            {
                int bits=__builtin_popcount(i)+__builtin_popcount(j);
                if(bits==turnedOn)
                {
                    string time=to_string(i)+":";
                    if(j<10)time+="0";//2 digit check
                    time+=to_string(j);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};