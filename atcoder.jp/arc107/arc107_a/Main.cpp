#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

  
ll mod = 998244353;

int main(){
    ll a, b, c; cin >> a >> b >> c;
    ll suma = (a + 1) * a / 2;
    ll sumb = (b + 1) * b / 2;
    ll sumc = (c + 1) * c / 2;

    suma %= mod;
    sumb %= mod;
    sumc %= mod;

    cout << (((suma * sumb) % mod) * sumc) % mod << endl;
}