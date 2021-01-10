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
    ll size = 1;
    rep(i, n){
        size *= 2;
    }
    vector <pair<ll, int>> a(size);
    pair <ll, int> m1, m2;
    rep(i, size){
        ll _a;
        cin >> _a;
        a.at(i) = make_pair(_a, i);
        if(i < size/2) m1 = max(m1, a.at(i));
        else m2 = max(m2, a.at(i));
    }
    // rep(i, size/2){
    //     ll _a;
    //     cin >> _a;
    //     a.at(i + size/2) = make_pair(_a, i + size/2);
    //     m2 = max(m2, a.at(i + size/2));
    // }

    if(m1.first > m2.first) cout << m2.second+1 << endl;
    else cout << m1.second+1 << endl;
    // sort(a.begin(), a.end());
    // cout << size << endl;
    // cout << a.at((size-1)/2).second + 1 << endl;
}