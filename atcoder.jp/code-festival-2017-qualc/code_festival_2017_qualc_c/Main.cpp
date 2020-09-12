#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    string s; cin >> s;
    string s_rm_x = "";
    vector <int> x_index_cnt(200000);

    int x_cnt = 0;
    int index = 0;
    for(auto c: s){
        if(c == 'x'){
            x_index_cnt.at(index - x_cnt) += 1;
            x_cnt += 1;
            index += 1;
            continue;
        }
        s_rm_x += c;
        index += 1;
    }
    
    bool flag = true;
    if(s_rm_x.size() > 1){
        rep(i, (int)(s_rm_x.size()) / 2){
            if(s_rm_x.at(i) != s_rm_x.at(s_rm_x.size() - 1 - i)){
                flag = false;
            }
        }
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    int size = s_rm_x.size();
    int ans = 0;

    if(size == 0){
        ans = 0;
    }
    else if(size == 1){
        ans = abs(x_index_cnt.at(0) - x_index_cnt.at(1));
    }
    else {
        if(size % 2 == 1){
            rep(i, size / 2 + 1){
            ans += abs(x_index_cnt.at(i) - x_index_cnt.at(size - i));
            }
        }
        else{
            rep(i, size / 2){
            ans += abs(x_index_cnt.at(i) - x_index_cnt.at(size - i));
            }
        }
    }

    cout << ans << endl;

}