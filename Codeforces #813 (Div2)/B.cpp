#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Observation 1: if n is even, all odd indices should have even elements sorted in increasing order and all even indices should have odd numbers sorted in increasing order
    // Observation 2: if n is odd, 1 should be at first index and all other indices should be filled by observation 1
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> ans(n+1);
        if(n%2 == 0){
            for(int i = 1; i <= n; i++){
                if(i%2 == 0){
                    ans[i] = i-1;
                } else{
                    ans[i] = i+1;
                }
            }
        } else{
            ans[1] = 1;
            for(int i = 2; i <= n; i++){
                if(i%2 == 0){
                    ans[i] = i+1;
                } else{
                    ans[i] = i-1;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}