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
    vector <int> a(n-1), b(n-1);
    vector <vector<int>> G(n);
    rep(i, n-1){
        int _a, _b; cin >> _a >> _b;
        _a--; _b--;
        a.at(i) = _a;
        b.at(i) = _b;
        G.at(_a).push_back(_b);
        G.at(_b).push_back(_a);
    }

    vector <vector<int>> tree(n);
    map<pair<int, int>, int> Tree;
    deque <int> d; d.push_back(0);
    vector <int> seen(n, -1); seen.at(0) = 1;
    while(d.size()){
        auto now = d.front();
        d.pop_front();
        for(auto next: G.at(now)){
            if(seen.at(next) != -1) continue;
            seen.at(next) = 1;
            tree.at(now).push_back(next);
            Tree[make_pair(now, next)] = 1;
            d.push_back(next);
        }
    }

    // for(int i = 0; i < n; i ++){
    //     cout << i << ": ";
    //     for(auto v: tree.at(i)){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    vector <ll> w(n);
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        ll e, x; cin >> e >> x;
        e --;
        int v_a, v_b;
        v_a = a.at(e);
        v_b = b.at(e);

        int from, not_to;
        if(t == 1){
            from = v_a;
            not_to = v_b;
        }
        else if(t == 2){
            from = v_b;
            not_to = v_a;
        }

        if(Tree[make_pair(from, not_to)] == 1){
            w.at(0) += x;
            w.at(not_to) += -x;
        }
        else{
            w.at(from) += x;
        }
    }
    deque <int> d2; d2.push_back(0);
    vector <int> seen2(n, -1); seen2.at(0) = 1;
    while(d2.size()){
        auto now = d2.front();
        d2.pop_front();
        for(auto next: G.at(now)){
            if(seen2.at(next) != -1) continue;
            seen2.at(next) = 1;
            d2.push_back(next);

            w.at(next) += w.at(now);
        }
    }

    for(auto ans: w){
        cout << ans << endl;
    }

}