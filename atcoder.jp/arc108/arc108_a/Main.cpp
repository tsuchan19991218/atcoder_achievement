#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

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
    ll s, p; cin >> s >> p;
    auto divisors = divisor(p);

    for(int i = 0; i < divisors.size(); i ++){
        ll num1 = divisors.at(i);
        ll num2 = p / num1;
        if(num1 + num2 == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}