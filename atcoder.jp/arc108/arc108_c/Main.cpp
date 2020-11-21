#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int n, m; cin >> n >> m;
    map <pair<int, int>, int> edge;
    vector <vector<int>> G(n);
    rep(i, m){
        int v, u, c; cin >> v >> u >> c;
        v --;
        u --;
        edge[make_pair(max(v, u), min(v, u))] = c;
        G.at(v).push_back(u);
        G.at(u).push_back(v);
    }

    deque <pair<int, int>> d;
    vector <int> seen(n, -1);
    vector <int> ans(n);

    d.push_back(make_pair(0, 1)); seen.at(0) = 1; ans.at(0) = 1;
    while(!d.empty()){
        auto now = d.back();
        d.pop_back();

        for(auto next: G.at(now.first)){
            if(seen.at(next) != -1) continue;
            seen.at(next) = 1;
            int pre_node = now.first;
            int pre_ans = now.second;

            int pre_next_weight = edge[make_pair(max(next, pre_node), min(next, pre_node))];
            int next_ans = -1;
            if(pre_next_weight == pre_ans){
                next_ans = pre_ans - 1;
                if(next_ans == 0) next_ans = pre_ans + 1;
            }
            else{
                next_ans = pre_next_weight;
            }
            ans.at(next) = next_ans;
            d.push_back(make_pair(next, next_ans));
        }
    }

    for(auto ans: ans){
        cout << ans << endl;
    }

}