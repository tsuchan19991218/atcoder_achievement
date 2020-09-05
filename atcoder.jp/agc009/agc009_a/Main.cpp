#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector <long long> a, b;
    for (int i = 0; i < n; i ++){
        long long _a, _b; cin >> _a >> _b;
        a.push_back(_a);
        b.push_back(_b);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // for (int i = 0; i < a.size(); i ++) cout << a[i];
    // cout << endl;

    long long ans = 0;
    for (int i = 0; i < n; i ++){
        if ((a[i] + ans) % b[i] == 0) continue;

        ans += b[i] - ((a[i] + ans) % b[i]);
    }

    cout << ans << endl;

}