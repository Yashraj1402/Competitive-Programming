/*
Alice's marks = X
Bob's marks = Y
for Alice to be happy X >= 2*Y
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int X,Y;
    cin >> X >> Y;
    if(X >= 2*Y){
        cout << "Yes\n";
    } else{
        cout << "No\n";
    }
    return 0;
}