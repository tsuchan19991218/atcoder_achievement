#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const ll INF = 1000000000;

int main(){
    int n, q; cin >> n >> q;
    vector <ll> a(n);
    fenwick_tree <ll> fw(n);
    rep(i, n){
        cin >> a.at(i);
        fw.add(i, a.at(i));
    }
    vector <tuple<int, int, ll>> Q(q);
    rep(i, q){
        int num1, num2;
        ll num3; cin >> num1 >> num2 >> num3;
        Q.at(i) = make_tuple(num1, num2, num3);
    }
    for(auto p: Q){
        int num1, num2;
        ll num3; tie(num1, num2, num3) = p;
        if(num1 == 0){
            fw.add(num2, num3);
        }
        else if(num1 == 1){
            
            cout << fw.sum(num2, num3) << endl;
        }
    }
}