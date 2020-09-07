#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
    long long n; cin >> n;
    vector <long long> yakusu;
    yakusu = divisor(n);

    long long ans;
    if (yakusu.size() % 2 == 0){
        ans = yakusu.at(yakusu.size() / 2) + yakusu.at((yakusu.size() / 2) - 1);
    }
    else{
        ans = 2 * yakusu.at((yakusu.size() / 2));
    }

    cout << ans - 2 << endl;

}