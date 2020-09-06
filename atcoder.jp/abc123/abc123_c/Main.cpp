#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    vector <long long> a(5);
    cin >> n >> a.at(0) >> a.at(1) >> a.at(2) >> a.at(3) >> a.at(4);
    long long fast_member; 
    long long fast_time = 5;

    fast_member = *min_element(a.begin(), a.end());

    long long ans = fast_time + ((n - 1) / fast_member);
    cout << ans << endl;
}