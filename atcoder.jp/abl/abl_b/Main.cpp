#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const int INF = 1000000000;

int main(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if(b < c || a > d){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}