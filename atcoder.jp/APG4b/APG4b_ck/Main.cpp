#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 1;
    for (auto c: s){
        if (c == '+'){
            ans += 1;
        }
        else if (c == '-'){
            ans -= 1;
        }
    }

    cout << ans << endl;
}