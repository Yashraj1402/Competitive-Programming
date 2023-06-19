// For odd n: every number of sequence can be 1
// For even n: n-2 numbers can be 2 and rest two can be 1 and 3
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        if(n%2 == 0){
            for(int i = 1; i <= n-2; i++){
                cout << 2 << ' ';
            }
            cout << 1 << ' ' << 3 << '\n';
        } else{
            for(int i = 1; i <= n; i++){
                cout << 1 << ' ';
            }
        }
    }
    return 0;
}