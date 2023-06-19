/*
Greedy Approach: Replace the smaller numbers one by one and track the maximum answer obtained among all replacements.
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
        int n,x,c;
        cin >> n >> x >> c;
        vector<int> a(n);
        for(auto &x: a) cin >> x;

        sort(all(a));

        int sum{0};
        for(auto x: a) sum += x;

        int cost{0}, ans = sum;
        for(int i = 0; i < n; i++){
            sum -= a[i];
            sum += x;
            cost += c;

            ans = max(ans, sum-cost);
        }
        cout << ans << '\n';
    }
    return 0;
}