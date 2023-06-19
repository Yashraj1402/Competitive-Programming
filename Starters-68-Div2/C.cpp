/*
Obtain the length of the longest common sśubsequence, let it be max_len.
If there exist any "boring" subsequence which occurs more than once and has length = max_len then answer = max_len
Otherwise answer = max_len-1, because, if our answer is not max_len then it has to be <= max_len-1 and we can always obatin a string of max_len-1 from our longest subsequnce.
Suppose our longest boring string is aaa and let's say that this is not the answer then the boring string "aa" occurs 2 times in "aaa" and hence "aa" can be our answer.
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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int len{1}, i{0}, j{0}, ind1{0},ind2{0};
        for(j = 1;  j < n; j++){
            if(s[j] != s[j-1]) break;
            ++len;
        }
        int max_len = len;
        ind2 = j-1;
        while(j < n && i < n){
            i = j;
            int len = 1;
            for(; j < n; j++){
                if(j == i) continue;
                if(s[j] != s[j-1]) break;
                ++len;
            }
            if(len > max_len){
                ind1 = i;
                ind2 = j-1;
                max_len = len;
            }
        }

        i = 0; j = 0;
        unordered_map<string,int> m;
        while(j < n && i < n){
            i = j;
            len = 1;
            for(; j < n; j++){
                if(j == i) continue;
                if(s[j] != s[j-1]) break;
                ++len;
            }
            if(len == max_len){
                string sub = s.substr(i,len);
                m[sub]++;
                if(m[sub] > 1){
                    cout << max_len << '\n';
                    return 0;
                }
            }
        }
        cout << max_len-1 << '\n';
    }
    return 0;
}