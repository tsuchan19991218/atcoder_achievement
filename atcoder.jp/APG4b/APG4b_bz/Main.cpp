#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)


 
int main() {
    int n; cin >> n;
    vector <int> A(n);
    map <int, int> Counter;

    rep(i, n) {
        cin >> A.at(i);
        int a = A.at(i);
        if (Counter.count(a)) Counter[a] += 1;
        else Counter[a] = 1;
    }

    vector <pair <int, int>> ans(n);
    int i = 0;
    for (auto p: Counter){
        ans.at(i) = make_pair(p.second, p.first);
        i += 1;
    }

    sort(ans.rbegin(), ans.rend());
    cout << ans.at(0).second << " " << ans.at(0).first << endl;
}
