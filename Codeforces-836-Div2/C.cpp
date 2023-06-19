// if n%x != 0 answer = -1, else answer always exist
// let's say our permutation is:
// a[1] a[2] a[3] ..... a[n]
// a[1] = x and a[n] = 1
// we fill all the other positions like a[i] = i
// this will fill all positions except for a[x]
// which we can make a[x] = N but we need smallest permutation so we find a number (y) such that y > x and N%y == 0 and y%x == 0 and we put y at x and now we have a[y] empty.
// we repeat the above process to fill a[y] and do this until we cannot find any 'y'
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--){
        int n,x;
        cin >> n >> x;
        
        if(n%x != 0){
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans(n+1);

        ans[1] = x;
        ans[n] = 1;

        for(int i = 2; i < n; i++){
            if(i == x) ans[i] = n;
            else ans[i] = i;
        }

        int cur = x;
        for(int i = x+1; i < n; i++){
            if(n%i == 0 && i%cur == 0){
                swap(ans[i], ans[cur]);
                cur = i;
            }
        }     

        for(int i = 1; i <= n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}