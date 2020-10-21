#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int MAX_N = 100005;

int main(){
    vector <int> primary(MAX_N, 1);
    primary.at(0) = 0;
    primary.at(1) = 0;
    for(int i = 2; i <= 1005; i ++){
        if(primary.at(i) != 1) continue;
        for(int j = i * i; j < MAX_N; j += i){
            primary.at(j) = 0;
        }
    }
    vector <int> cnt(MAX_N);
    rep(i, primary.size()){
        if(i == 0) continue;
        cnt.at(i) += cnt.at(i - 1);
        if(i % 2 == 0) continue;
        if(primary.at(i) == 1 && primary.at((i + 1) / 2) == 1) cnt.at(i)++;
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << cnt.at(r) - cnt.at(l - 1) << endl;
    }
}