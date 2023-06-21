#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define revall(x) x.rbegin(),x.rend()
#define INF 1e18
typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define LOCAL
#ifndef LOCAL
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<'\n';
#else
#define debug(x) cout<<#x<<" ";_print(x);cout<<'\n';
#endif

template<class T> void _print(T a){cerr<<a;}
template<class T1,class T2> void _print(pair<T1,T2> p){_print(p.first);cerr<<",";_print(p.second);}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T it:v){_print(it);cerr<<" ";}cerr<<"]"<<'\n';}
template<class T1,class T2> void _print(map<T1,T2> m){cerr<<"[";for(auto it:m){_print(it.first);cerr<<" ";_print(it.second);cerr<<";";}cerr<<"]";}
template<class T1,class T2> void _print(unordered_map<T1,T2> m){cerr<<"[";for(auto it:m){_print(it.first);cerr<<" ";_print(it.second);cerr<<";";}cerr<<"]";}
template<class T1,class T2> void _print(vector<pair<T1,T2>> v){cerr<<"[";for(auto it:v){_print(it.first);cerr<<" ";_print(it.second);cerr<<";";}cerr<<"]";}
template<class T> void _print(set<T> s){cerr<<"[";for(auto it:s){_print(it);cerr<<" ";}cerr<<"]";}
template<class T> void _print(unordered_set<T> s){cerr<<"[";for(auto it:s){_print(it);cerr<<" ";}cerr<<"]";}
template<class T> void _print(multiset<T> s){cerr<<"[";for(auto it:s){_print(it);cerr<<" ";}cerr<<"]";}
/*----------------USEFUL FUNCTIONS--------------------------------------------------*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll fact(ll n, ll mod) {ll ans{1};for(ll i = 1; i <= n; i++){ans = (ans * i) % mod;}return ans;}
ll C(ll n, ll k, ll mod) {return fact(n,mod) * expo(fact(k,mod), mod - 2,mod)%mod * expo(fact(n - k,mod), mod - 2, mod)%mod;}
vector<ll> sieve(int n) {int* arr = new int[n + 1]();vector<ll> vect;for (int i = 2; i <= n; i++) {if (arr[i] == 0) {vect.push_back(i);for (int j = 2 * i; j <= n; j += i) {arr[j] = 1;}}}return vect;}
ll getRandomNumber(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rng);}
/*-----------------------------------------------------------------------------------*/
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> segments(m);
    for(auto &x: segments) cin >> x.first >> x.second;

    int q;
    cin >> q;
    vector<int> changes(q);
    for(auto &x: changes) cin >> x;

    int left = 0, right = q-1, ans = -1;
    while(left <= right){
        int mid = left + (right - left)/2;

        vector<int> a(n+1,0);
        for(int i = 0; i <= mid; i++){
            a[changes[i]] = 1;
        }

        vector<int> prefix_sum(n+1, 0);
        prefix_sum[1] = a[1];
        for(int i = 2; i <= n; i++){
            prefix_sum[i] = prefix_sum[i-1] + a[i];
        }

        bool found = false;
        for(auto segment: segments){
            int len = segment.second - segment.first + 1;
            int one = prefix_sum[segment.second] - prefix_sum[segment.first] + a[segment.first];
            int zero = len - one;

            if(one > zero){
                found = true;
                ans = mid+1;
                right = mid-1;
                break;
            }
        }
        if(!found){
            left = mid+1;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
    // freopen("input.txt", "r" ,stdin);
    // freopen("output.txt", "w" ,stdout);
    #ifndef LOCAL
    freopen("Error.txt","w",stderr);
    #endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}