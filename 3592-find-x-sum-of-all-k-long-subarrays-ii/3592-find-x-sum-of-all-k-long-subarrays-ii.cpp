#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    typedef long long ll;
    ll k,x,ans=0;
    map<ll,ll>mp;
    ordered_set<pair<ll,ll>>ost;
    void add(int n)
    {
        ll sz=mp.size();
        pair<ll,ll>pr=make_pair(mp[n],n);
        if(sz<x)
        {
            ost.erase(pr);
            pr.first++;
            ans+=n;
        }
        else
        {
            pair<ll,ll>ar=*ost.find_by_order(sz-x);
            ost.erase(pr);
            if(ar<=pr)
            {
                pr.first++;
                ans+=n;
            }
            else
            {
                pr.first++;
                if(ar<=pr)ans=ans-ar.first*ar.second+pr.first*pr.second;
            }
        }
        mp[n]++;
        ost.insert(pr);
    }
    void del(int n)
    {
        pair<ll,ll>pr=make_pair(mp[n],n);
        ll sz=mp.size();
        if(mp.size()<=x)
        {
            ans-=n;
            ost.erase(pr);
            mp[n]--;
            if(mp[n]==0)
            {
                mp.erase(n);
            }
            else
            {
                pr.first--;
                ost.insert(pr);
            }
        }
        else
        {
            pair<ll,ll>ar=*ost.find_by_order(sz-x);
            mp[n]--;
            if(mp[n]==0)mp.erase(n);
            if(pr<ar)
            {
                ost.erase(pr);
                pr.first--;
                if(pr.first!=0)ost.insert(pr);
            }
            else
            {
                ost.erase(pr);
                pr.first--;
                ost.insert(pr);
                pair<ll,ll>br=*ost.find_by_order(sz-x);
                if(pr.first==0)ost.erase(pr);
                if(ar==br)ans-=n;
                else ans=ans-(pr.first+1)*pr.second+br.first*br.second;
            }
        }
    }
    vector<long long> findXSum(vector<int>& nums, int y, int z) {
        vector<ll>res;
        k=y,x=z;
        for(ll i=0;i<k-1;++i)add(nums[i]);
        for(ll i=k-1;i<nums.size();++i)
        {
            add(nums[i]);
            res.push_back(ans);
            del(nums[i-k+1]);
        }
        return res;
    }
};