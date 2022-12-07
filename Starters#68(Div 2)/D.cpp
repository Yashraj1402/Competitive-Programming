/*
Let's say initially product of the array = prod.
If we perform the operation once on a[i] and a[j] the product will become: res_prod = (prod * (a[i]^a[j]))/(a[i]*a[j]) where ^ is xor.
For res_prod to be greater than prod a[i]^a[j] > a[i]*a[j].

Now:
1. let's say we have an even number E then E^1 = E+1 and E*1 = E hence they can make a good pair.
2. let's say we have an odd number O then O^1 = O-1 and O*1 = O hence this is a bad pair

By experimentation it can concluded:
1. Any pair apart from (E,1) is a bad pair
2. Pair (E,1) is better for smaller even numbers as compared to bigger even numbers

Implementation:
Count all the number of one's and greedily pick the even numbers until all one's are paired or all even numbers are exhausted.
*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define revall(x) x.rbegin(),x.rend()
#define INF 1e18
typedef long long ll;
typedef long double ld;
ll mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;

        ll cnt{0};
        for(auto x: a) if(x == 1) ++cnt;

        vector<ll> even, odd;
        for(auto x: a){
            if(x%2 == 0) even.push_back(x);
            else odd.push_back(x);
        }

        sort(revall(even));

        while(cnt > 0 && !even.empty()){
            odd.push_back(even.back()+1);
            even.pop_back();
            --cnt;
        }

        ll prod{1};
        for(auto x: odd){
            prod = (prod * x)%mod;
        }
        for(auto x: even){
            prod = (prod * x)%mod;
        }

        cout << prod%mod << '\n';
    }
    return 0;
}