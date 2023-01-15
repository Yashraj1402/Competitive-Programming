/*
Considering y > x
-> if x == y then N = x 
-> if y%x == 0 then y - x
-> we need to satisy (N+x)%y == 0 and (N+y)%x == 0 where y%x != 0.
So, we need to eliminate x from (N+x)%y and y from (N+y)%x
Observation 1: N should be of the form K - y - x
Observation 2: If N = K - y - x, (N+y)%x = (K - y - x + y)%x = (K - x)%x and (N+x)%y = (K - y)
Observation 3: K should be divisible by both y and x

Conclusion: The most obvious number that is divisible by x and y both is xy hence K = xy and N = xy - y - x => N = (x - 1)y - x
*/
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