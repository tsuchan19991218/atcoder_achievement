#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector <string> s;   
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i ++){
        string _s;
        cin >> _s;
        s.push_back(_s);
    }
    long long m, a, r, c, h;
    m = 0; a = 0; r = 0; c = 0; h = 0;
    for(auto cs: s){
        char _c = cs[0];
        if (_c == 'M') m++;
        if (_c == 'A') a++;
        if (_c == 'R') r++;
        if (_c == 'C') c++;
        if (_c == 'H') h++;
    }
    long long sum = m + a + r + c + h;
    //cout << sum << " " << r << " " << a << " " << c << " " << h << " " << endl;
    ans = sum * (sum - 1) * (sum - 2) / 6;

    ans -= m * (m - 1) * (m - 2) / 6;
    ans -= (m * (m - 1) / 2) * (sum - m);

    ans -= a * (a - 1) * (a - 2) / 6;
    ans -= (a * (a - 1) / 2) * (sum - a);

    ans -= r * (r - 1) * (r - 2) / 6;
    ans -= (r * (r - 1) / 2) * (sum - r);

    ans -= c * (c - 1) * (c - 2) / 6;
    ans -= (c * (c - 1) / 2) * (sum - c);

    ans -= h * (h - 1) * (h - 2) / 6;
    ans -= (h * (h - 1) / 2) * (sum - h);

    cout << ans << endl;
}