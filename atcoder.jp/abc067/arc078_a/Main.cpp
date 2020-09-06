#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <long long> a(n);
    for (int i = 0; i < n; i ++){
        long long _a; cin >> _a;
        a.at(i) = _a;
    }

    for (int i = 1; i < n; i ++) a.at(i) += a.at(i - 1);
    long long sum_of_a = a.at(n - 1);

    long long ans = 100000000000000000;
    for (int i = 0; i < n - 1; i ++){
        ans = min(ans, abs((sum_of_a - a.at(i)) - a.at(i)));
    }

    cout << ans << endl;
}