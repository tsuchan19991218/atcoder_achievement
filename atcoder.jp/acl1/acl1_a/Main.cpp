#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

const ll INF = 1000000000;

int main(){
    int n; cin >> n;
    vector <pair<int, int>> town(n);
    vector <int> ans_index(n);
    rep(i, n){
        int x, y; cin >> x >> y;
        town.at(i) = make_pair(x, y);
        ans_index.at(i) = y;
    }
    sort(town.begin(), town.end());

    dsu d(n + 1);

    set <int> set_y;
    int min_y = n + 1;
    for(int i = 0; i < n; i ++){
        int y = town.at(i).second;
        // if(min_y > y){
        //     set_y.emplace(y);
        //     min_y = y;
        //     continue;
        // }

        // auto it_end = upper_bound(set_y.begin(), set_y.end(), y);
        // auto it_sta = set_y.begin();
        // d.merge(*it_sta, y);
        // it_sta ++;
        // for(auto it = it_sta; it != it_end;){
        //     d.merge(*it, y);
        //     it = set_y.erase(it);
        // }
            //cout << set_y.size() << endl;
        auto it = set_y.begin();
        int min_y = y; // 最小値のyを保存しておくよう
        while(it != set_y.end()){
            if(*it < y){ //マージできる時
                d.merge(*it, y);
                if(min_y > *it){
                    min_y = *it; //set_y内の最小値を保存
                }
                it = set_y.erase(it);
            }
            else break; //マージできない時(set_y内に今のyよりも小さい数がなくなった)
        }
        set_y.emplace(min_y);

    }
    for(int index: ans_index){
        cout << d.size(index) << endl;
    }
}