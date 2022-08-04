#define ll long long
class Solution {
public:
    int mirrorReflection(int p, int q) {
        ll extension=q,reflection=p;
        
        while(extension%2==0 and reflection%2==0)
        {
            extension=extension/2;
            reflection=reflection/2;
        }
        if(extension%2==0 and reflection%2!=0){return 0;}
        if(extension%2==1 and reflection%2==0){return 2;}
        if(extension%2==1 and reflection%2!=0){return 1;}
        
        return -1;
    }
};