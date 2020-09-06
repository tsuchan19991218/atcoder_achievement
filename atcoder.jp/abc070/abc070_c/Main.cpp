#include <bits/stdc++.h>
using namespace std;

long long my_lcm(long long a, long long b);

int main(){
    int n; cin >> n;
    vector <long long> t(n);

    long long ans = 1;
    for (int i = 0; i < n; i ++){
        long long _t; cin >> _t;
        ans = my_lcm(ans, _t);
        t.at(i) = _t;
    }

    cout << ans << endl;
}

long long my_lcm (long long a, long long b){
    return (a / gcd(a,b)) * b;
}