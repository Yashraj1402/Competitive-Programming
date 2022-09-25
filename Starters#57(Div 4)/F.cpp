/*
As string can be rearranged it is better to concatenate strings and form the largest number possible by that and then insert operands in between
4-89+20 
The largest number that can be formed by concatenation :
98420
now insert operands in between such that all the bigger numbers are getting added and smaller numbers are getting subtracted
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string num,op;
        for(int i = 0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num.push_back(s[i]);
            } else{
                op.push_back(s[i]);
            }
        }
        sort(num.rbegin(),num.rend());
        sort(op.begin(),op.end());
        int N = num.size();
        int ind{0};
        for(int i = 0; i < N; i++){
            cout << num[i];
            if(i >= N-op.size()-1){
                cout << op[ind];
                ind++;
            }
        }
        cout << '\n';
    }
    return 0;
}