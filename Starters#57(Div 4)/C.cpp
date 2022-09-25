/*
Observation 1: If the array has zero then the product will always be zero hence we dont need to do any operation
Observation 2: Negative numbers multiplied odd times results in a negative number whereas Negative numbers multiplied even times results in a positive number
Conclusion: If there exists one zero then we dont need to do anything.
            If number of negative numbers is even then we dont need to do anything
            If number of negative numebers is odd then we should delete one of them hence we need to do one operation
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
        vector<int> a(n);
        bool zero_found = false;
        int number_of_negative_numbers{0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 0){
                zero_found = true;
            } 
            if(a[i] < 0){
                number_of_negative_numbers++;
            }
        }
        if(zero_found){
            cout << 0 << '\n';
        } else{
            if(number_of_negative_numbers%2 == 0){
                cout << 0 << '\n';
            } else{
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}