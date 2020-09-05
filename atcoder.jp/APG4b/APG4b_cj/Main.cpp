#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector <int> a(n);

    int sum = 0;
    for (int i = 0; i < n; i ++){
        int _a; cin >> _a;
        sum += _a;
        a.at(i) = _a;
    }

    int ave = sum / a.size();

    for (int i = 0; i < n; i ++){
        cout << abs(ave - a.at(i)) << endl;
    }
}