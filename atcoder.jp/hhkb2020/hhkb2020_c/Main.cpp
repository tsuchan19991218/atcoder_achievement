#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    vector <int> p(n);
    rep(i, n) cin >> p.at(i);
    set <int> num;
    for(int i = 0; i < 200005; i ++){
        num.insert(i);
    }
    for(auto a: p){
        if(num.count(a)) num.erase(a);
        cout << *num.begin() << endl;
    }
}