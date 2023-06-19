/*
Observation based!
if a is even and b is even answer always exists
if a is even and b is odd answer always exist except for b == 1
if a is odd and b is even asnwer always exist except for a == 1
if a is odd and b is odd answer never exist
*/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long a,b;
    cin >> a >> b;
    if(a%2 == 0 && b%2 == 0){
        cout << "Yes\n";
        return;
    }
    if(a%2 == 0 && b%2 == 1){
        if(b == 1){
            cout << "No\n";
        } else{
            cout << "Yes\n";
        }
        return;
    }
    if(a%2 == 1 && b%2 == 0){
        if(a == 1){
            cout << "No\n";
        } else{
            cout << "Yes\n";
        }
        return;
    }
    if(a%2 == 1 && b%2 == 1){
        cout << "No\n";
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}