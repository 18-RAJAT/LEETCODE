class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int fz[26];
        fill(fz,fz+26,0);
        for(int i=0;i<tasks.size();++i)fz[tasks[i]-'A']++;
        sort(fz,fz+26);
        int maxFz=fz[25];
        //calculate the maximum possible idle time
        int idleTime=(maxFz-1)*n;
        for(int i=24;~i;--i)
        {
            idleTime-=min(maxFz-1,fz[i]);
        }
        return max((int)tasks.size(),(int)tasks.size()+idleTime);
    }
};