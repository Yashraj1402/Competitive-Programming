// Print the string forward and then backward
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--){
        string s;
        cin >> s;
        cout << s;
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}