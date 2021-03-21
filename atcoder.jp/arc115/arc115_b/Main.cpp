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
    int n; cin >> n;
    vector <vector<ll>> c(n, vector <ll>(n));
    vector <ll> dist_yoko(n - 1);
    ll m = INFLL;
    int index_0 = -1;
    rep(i, n)rep(j, n){
        cin >> c.at(i).at(j);
        if(i == 0){
            //cout << j << endl;
            if(m > c.at(i).at(j)){
                m = c.at(i).at(j);
                index_0 = j;
            }
            if(j > 0)dist_yoko.at(j-1) = c.at(i).at(j) - c.at(i).at(j-1);
            continue;
        }

        if(i != 0){
            if(j > 0){
                if(dist_yoko.at(j-1) != c.at(i).at(j) - c.at(i).at(j-1)){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    vector <ll> b(n);
    //cout << index_0 << endl;
    for(int i = index_0 - 1; i >= 0; i --){
        //cout << i << endl;
        b.at(i) = b.at(i + 1) - dist_yoko.at(i);
        if(b.at(i) < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = index_0 + 1; i < n; i ++){
        b.at(i) = b.at(i - 1) + dist_yoko.at(i - 1);
        if(b.at(i) < 0){
            cout << "No" << endl;
            return 0;
        }
    }

    vector <ll> a(n);
    for(int i = 0; i < n; i ++){
        a.at(i) = c.at(i).at(0) - b.at(0);
        if(a.at(i) < 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(auto num: a){
        cout << num << " ";
    }
        cout << endl;
    for(auto num: b){
        cout << num << " ";
    }
        cout << endl;
}