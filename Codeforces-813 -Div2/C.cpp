#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // find the index till where elements are unsorted let's call it 'ind'
    // make all elements till that index zero
    // the numbers that have index greater than the 'ind' but are present in the subarray a.begin(), a.begin()+i will also become zero, find the number that have the greatest index among all such number and make all elements zero till this index
    // answer will be the number of unique numbers till the final index
    
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> a(n);
        int ind = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            
            if(i > 0 && a[i] < a[i-1]){
                ind = i-1;
            }
        }

        // if ind == -1 then it means array is sorted already:
        if(ind == -1){
            cout << 0 << '\n';
            continue;
        }

        // to keep track of number of unique elements use a set
        unordered_set<int> s;

        // all unique elements till index 'ind'
        for(int i = 0; i <= ind; i++){
            s.insert(a[i]);
        }

        // find extended index:
        int extended_index = -1;
        for(int i = ind; i < n; i++){
            if(s.find(a[i]) != s.end()){
                extended_index = i;
            }
        }

        // finally find the number of unique elements till extended index
        for(int i = 0; i <= extended_index; i++){
            s.insert(a[i]);
        }

        cout << s.size() << '\n';
    }
    return 0;
}