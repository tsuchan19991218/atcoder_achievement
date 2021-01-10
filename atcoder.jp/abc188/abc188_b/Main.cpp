#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int main(){
    int n; cin >> n;
    vector <ll> a(n), b(n);
    ll S = 0;
    rep(i, n){
        cin >> a.at(i);
    }
    rep(i, n) cin >> b.at(i);

    rep(i, n){
        S += a.at(i) * b.at(i); 
    }

    if(S == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}