#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;

    vector <vector<int>> G(n + 1);
    vector <pair<int, int>> ans;

    if(n % 2 == 1){
         for(int i = 1; i < n; i ++){
            G.at(n).push_back(i);
            G.at(i).push_back(n);
            ans.push_back(make_pair(i, n));
        }
        n -= 1;
    }

    for(int now = 1; now <= n; now ++){
        for(int to = 1; to < n + 1; to ++){
            if(to + now == n + 1 || to == now) continue;
            if(find(G.at(now).begin(), G.at(now).end(), to) != G.at(now).end()) continue;
            ans.push_back(make_pair(now, to));
            G.at(now).push_back(to);
            G.at(to).push_back(now);
        }
    }

    cout << ans.size() << endl;
    for(auto P: ans){
        cout << P.first << " " << P.second << endl;
    }
}