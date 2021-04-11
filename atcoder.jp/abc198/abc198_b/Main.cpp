#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    ll n; cin >> n;
    if(n == 0){
        cout << "Yes" << endl;
        return 0;
    }
    while(n % 10 == 0){
        n /= 10;
    }

    string s_n = to_string(n);
    string r_n = to_string(n);
    reverse(r_n.begin(), r_n.end());
    if(s_n == r_n){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}