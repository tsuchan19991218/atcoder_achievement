#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    string s; cin >> s;
    int k; cin >> k;

    for(auto &c: s){
        //cout << k << endl;
        if(c == 'a') continue;
        if(abs(c - ('z' + 1)) <= k){
            //cout << abs(c - ('z' + 1)) << endl;
            k -= abs(c - ('z' + 1));
            c = 'a';
        }
        if(k <= 0) break;
    }
    if(k > 0){
        s.at(s.size() - 1) += k % (abs('a' - ('z' + 1)));
    }
    cout << s << endl;
}