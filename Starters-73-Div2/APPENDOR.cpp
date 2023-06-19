/*
let's say we the OR of all the array is all_or.
the only case when answer = -1 is if all_or have 1 and Y have 0 at the same position in there binary representation because a 1 cannot be converted to 0 using OR
Rest all the time answer exists.

So, we have 2 cases for a position 'i' considering binary representatio of both all_or and Y
case 1: all_or[i] = y[i], X[i] = 0 because nothing needs to be changed
case 2: all_or[i] = 0 and y[i] = 1, X[i] = 1 because all_or[i] needs to be changed to 1
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
    int n,y;
    cin >> n >> y;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    int all_or{0};
    for(auto x: a){
        all_or |= x;
    }

    int x{0};
    for(int i = 31; i >= 0; i--){
        int h1 = all_or & (1 << i);
        int h2 = y & (1 << i);

        if(h1 != 0 && h2 == 0){
            cout << -1 << '\n';
            return;
        }

        if(h1 != 0 && h2 == 0){
            x += 0;
        }

        if(h1 == 0 && h2 != 0){
            x += (1 << i);
        }
    }

    cout << x << '\n';
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