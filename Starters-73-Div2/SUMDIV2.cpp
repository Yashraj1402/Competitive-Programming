#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define revall(x) x.rbegin(),x.rend()
#define INF 1e18
typedef long long ll;
typedef long double ld;
void solve()
{
    ll x,y;
    cin >> x >> y;

    if(x == y){
        cout << x << '\n';
        return;
    }

    if(y < x){
        swap(y,x);
    }

    if(y%x == 0){
        cout << y - x << '\n';
        return;
    }

    ll n = (x - 1)*y - x;
    cout << n << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}