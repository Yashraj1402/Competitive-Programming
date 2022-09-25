/*
Suppose that we are given a number N
It can be divide as: (1, N-1) (2, N-2) (3, N-3) .... (N-1, 1)
All these pairs are of the form (i,j) such that i+j = N
It can be seen that these are N-1 pairs, this can also be observed by taking some examples like:
4 --> (1,3) (2,2) (3,1)
5 --> (1,4) (2,3) (3,2) (4,1)
Hence answer is always N-1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << n-1 << '\n';
    return 0;
}