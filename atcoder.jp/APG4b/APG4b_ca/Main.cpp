#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)


 
int main() {
    int n; cin >> n;
    vector <pair <int, int>> a_b(n);

    rep(i, n){
        int a; cin >> a;
        int b; cin >> b;
        a_b.at(i) = make_pair(b, a);
    }

    sort(a_b.begin(), a_b.end());

    rep(i, n) cout << a_b.at(i).second << " " << a_b.at(i).first << endl;
}
