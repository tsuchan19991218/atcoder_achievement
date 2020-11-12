#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int INF = 1000000005;

int main(){
    int n; cin >> n;
    vector <ll> c(n); rep(i, n)cin >> c.at(i);
    int q; cin >> q;
    vector <vector<int>> s(q);
    pair <ll, int> gusu_min = make_pair(INF, -1);
    pair <ll, int> all_min = make_pair(INF, -1);
    rep(i, q){
        int chr; cin >> chr;
        s.at(i).push_back(chr);
        if(chr == 1){
            ll c1, c2; cin >> c1 >> c2;
            c1 = c1 - 1;
            s.at(i).push_back(c1);
            s.at(i).push_back(c2);
        }
        else if(chr == 2){
            ll c1; cin >> c1;
            s.at(i).push_back(c1);
        }
        else{
            ll c1; cin >> c1;
            s.at(i).push_back(c1);
        }
    }

    rep(i, n){
        if(all_min.first > c.at(i)){
            all_min.first = c.at(i);
            all_min.second = i;
        }
        if(i % 2 == 0){
            if(gusu_min.first > c.at(i)){
                gusu_min.first = c.at(i);
                gusu_min.second = i;
            }
        }
    }

    ll ans = 0; ll minus_gusu = 0; ll minus_all = 0; 
    for(auto query: s){
        if(query.size() == 3){
            int index = query.at(1);
            ll value = query.at(2);
            ll minus = minus_all;
            if(index % 2 == 0) minus += minus_gusu;
            if(value > c.at(index) - minus){
                //cout << "N" << endl;
                continue;
            }
            // ------------- ↓　減らせるとき
            ans += value;
            c.at(index) -= value;
            if(all_min.first > c.at(index) - minus){
                all_min = make_pair(c.at(index) - minus, index);
            }
            if(index % 2 == 0){
                if(gusu_min.first > c.at(index) - minus){
                    gusu_min = make_pair(c.at(index) - minus, index);
                }
            }
            //cout << "Y" << endl;
        }
        else{
            if(query.at(0) == 2){
                //int index = query.at(1);
                ll value = query.at(1);
                if(value > gusu_min.first){
                    //cout << "N" << endl;
                    continue;
                }
                // -----------
                ans += value * ((n + 1) / 2);
                gusu_min.first -= value;
                minus_gusu += value;

                if(gusu_min.first < all_min.first){
                    all_min = gusu_min;
                }
                //cout << "Y" << endl;
            }
            else{
                //int index = query.at(1);
                ll value = query.at(1);
                if(value > all_min.first){
                    //cout << "N" << endl;
                    continue;
                }
                // -----------
                ans += value * n;
                all_min.first -= value;
                gusu_min.first -= value;

                minus_all += value;

                //cout << "Y" << endl;
            }
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
}