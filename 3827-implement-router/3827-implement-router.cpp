#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

struct Packet
{
    int s,d,t,id;
    bool operator==(const Packet& o)const{return s==o.s && d==o.d && t==o.t;}
};
struct PacketHash
{
    size_t operator()(const Packet& p)const noexcept
    {
        uint64_t x=(uint64_t)(unsigned)p.s;
        x=(x<<21)^(uint64_t)(unsigned)p.d;
        x=(x<<21)^(uint64_t)(unsigned)p.t;
        x^=(x>>33); x*=0xff51afd7ed558ccdULL;
        x^=(x>>33); x*=0xc4ceb9fe1a85ec53ULL;
        x^=(x>>33);
        return (size_t)x;
    }
};

template<class T>using ost=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

class Router {
public:
    size_t memory;
    queue<Packet>q;
    unordered_set<Packet,PacketHash>seen;
    unordered_map<int,ost<pair<int,int>>>destFreq;
    int uid;
    explicit Router(int memoryLimit):memory((size_t)memoryLimit),uid(0){seen.reserve((size_t)memoryLimit*2+3);}
    bool addPacket(int source,int destination,int timestamp)
    {
        Packet p{source,destination,timestamp,0};
        if(seen.count(p))return false;
        if(memory==0)return false;
        if(q.size()==memory)
        {
            Packet old=q.front(); q.pop();
            seen.erase(old);
            auto& t=destFreq[old.d];
            t.erase({old.t,old.id});
            if(t.empty())destFreq.erase(old.d);
        }
        p.id=uid++;
        q.push(p);
        seen.insert(p);
        destFreq[destination].insert({timestamp,p.id});
        return true;
    }
    vector<int> forwardPacket()
    {
        if(q.empty())return {};
        Packet p=q.front(); q.pop();
        seen.erase(p);
        auto& t=destFreq[p.d];
        t.erase({p.t,p.id});
        if(t.empty())destFreq.erase(p.d);
        return {p.s,p.d,p.t};
    }
    int getCount(int destination,int startTime,int endTime)
    {
        auto it=destFreq.find(destination);
        if(it==destFreq.end())return 0;
        auto& t=it->second;
        int L=t.order_of_key({startTime,INT_MIN});
        int R=t.order_of_key({endTime,INT_MAX});
        return R-L;
    }
};