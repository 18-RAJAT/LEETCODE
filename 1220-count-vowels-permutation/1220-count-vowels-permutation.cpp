class Solution {
public:
    int countVowelPermutation(int n) {
        const int modulo=1000000007;
        unsigned int a,e,i,o,u;
        a=e=i=o=u=1;
        unsigned int ap,ep,ip,op,up;
        for(int k=1;k<n;k++) {
            ap=a;
            ep=e;
            ip=i;
            op=o;
            up=u;
            a=((ep+up+ip)%modulo);
            e=((ap+ip)%modulo);
            i=((ep+op)%modulo);
            o=((ip)%modulo);
            u=((op+ip)%modulo);
        }
        return ((a+e)%modulo+(i+o)%modulo+u)%modulo;
    }
};