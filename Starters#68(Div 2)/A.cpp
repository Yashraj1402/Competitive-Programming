/*
Total income = 2^x
Money spent till first expence = (2^x) / 2 = 2^(x-1)
Money spent till second expence = 2^(x-2)
Money spent till third expence = 2^(x-3)
.
.
.
Money spent till nth expence = 2^(x - n)

so the answer = 2^(x-n)
*/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define revall(x) x.rbegin(),x.rend()
#define INF 1e18
typedef long long ll;
typedef long double ld;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int n,x;
        cin >> n >> x;
        
        if(n > x){
            cout << 0 << '\n';
        } else if(n == x){
            cout << 1 << '\n';
        } else{
            ll a{1};
            for(int i = 1; i <= x-n; i++){
                a *= (ll)2;
            }
            cout << a << '\n';
        }
    }
    return 0;
}