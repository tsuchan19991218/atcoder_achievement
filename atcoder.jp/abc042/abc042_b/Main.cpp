#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n, l; cin >> n >> l;
    vector <string> s(n);
    rep(i, n) cin >> s.at(i);
    sort(s.begin(), s.end());
    for(auto ans: s){
        cout << ans;
    }
    cout << endl;
}