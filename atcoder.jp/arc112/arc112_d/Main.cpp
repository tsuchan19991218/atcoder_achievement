#include <bits/stdc++.h>
#include <atcoder/all>
#include <math.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

int main(){
    int h, w; cin >> h >> w;

    vector <string> s(h);
    rep(i, h){
        cin >> s.at(i);
    }

    deque <pair<int, int>> bom;
    vector <int> die_row(h), die_col(w);
    die_row.at(0) = 1;
    die_row.at(h-1) = 1;
    die_col.at(0) = 1;
    die_col.at(w-1) = 1;

    bom.push_back(make_pair(0, 0));
    bom.push_back(make_pair(0, w-1));
    bom.push_back(make_pair(h-1, 0));
    bom.push_back(make_pair(h-1, w-1));

    while(bom.size()){
        auto p = bom.front();
        int x, y;
        x = p.second;
        y = p.first;
        bom.pop_front();
        for(int i = 0; i < h; i ++){
            if(s.at(i).at(x) == '#'){
                if(die_row.at(i) == 1 && die_col.at(x) == 1) continue;
                die_row.at(i) = 1;
                die_col.at(x) = 1;
                bom.push_back(make_pair(i, x));
            }
        }

        for(int i = 0; i < w; i ++){
            if(s.at(y).at(i) == '#'){
                if(die_row.at(y) == 1 && die_col.at(i) == 1) continue;
                die_row.at(y) = 1;
                die_col.at(i) = 1;

                bom.push_back(make_pair(y, i));
            }
        }
    }

    dsu row(h);

    int ans1 = 0;
    int cnt1 = 0;
    for(int j = 0; j < w; j ++){
        int tmp = -1;
        for(int i = 0; i < h; i ++){
            if(die_row.at(i) == 1) continue;
            if(j == 0) ans1 ++;

            if(s.at(i).at(j) == '#'){
                if(tmp != -1){
                    if(row.same(tmp, i)) continue;
                    row.merge(tmp, i);
                    cnt1 ++;
                }
                tmp = i;
            }
        }
    }
    ans1 -= cnt1;
    //cout << ans1 << endl;

    dsu col(w);

    int ans2 = 0;
    int cnt2 = 0;
    for(int j = 0; j < h; j ++){
        int tmp = -1;
        for(int i = 0; i < w; i ++){
            if(die_col.at(i) == 1) continue;
            if(j == 0) ans2 ++;

            if(s.at(j).at(i) == '#'){
                if(tmp != -1){
                    if(col.same(tmp, i)) continue;
                    col.merge(tmp, i);
                    cnt2 ++;
                }
                tmp = i;
            }
        }
    }
    ans2 -= cnt2;
    cout << min(ans1, ans2) << endl;;

}