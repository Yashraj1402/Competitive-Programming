#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // We need to sort first k elements of array in minimum moves possible
    // We can swap any 2 elements
    // Every element among first K elements should be in range [1,k]
    // We won't disturb the elements that are already in range are among the first k elements (let's say these are the 'good' elements) 
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto &x: a) cin >> x;

        int swap_cnt{0};
        for(int i = 0; i < k; i++){
            if(1 <= a[i] && a[i] <= k) /*Don't change the good elements */ continue;
            else /*Need one swap for non-good elements*/ ++swap_cnt;
        }

        cout << swap_cnt << '\n';
    }
    return 0;
}