#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector <int> counter(26, 0);
    long long ans = 1;

    for (auto c: s){
        int ord = c - 'a';
        //cout << ord << endl;
        counter.at(ord) += 1;
    }

    for (auto cnt: counter){
        ans *= cnt + 1;
        ans %= 1000000007;
    }

    cout << ans - 1 << endl;
}