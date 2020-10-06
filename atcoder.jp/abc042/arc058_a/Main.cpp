#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int to_int(string s){
    reverse(s.begin(), s.end());
    int d = 1; int tmp = 0;

    for(auto c: s){
        tmp += d * (c - '0');
        d *= 10;
    }
    return tmp;
}


int main(){
    int n, k; cin >> n >> k;
    vector <int> d(k);
    map <int, int> can_use;
    rep(i, k){
        cin >> d.at(i);
        can_use[d.at(i)] = 1;
    }
    int min_use;
    for(int i = 1; i <= 9; i ++){
        if(can_use[i] == 0){
            min_use = i;
            break;
        }
    }
    string s_n = to_string(n);
    bool flag = false;
    while(!flag){
        flag = true;
        for(int i = 0; i < s_n.size(); i ++){
            if(can_use[s_n.at(i) - '0'] == 0) continue;
            flag = false;
            int k = i + 1;
                while(k < s_n.size()){
                    if(d.at(0) != 0) s_n.at(k) = '0';
                    else s_n.at(k) = min_use + '0';
                    k ++;
                }
            while(can_use[s_n.at(i) - '0'] != 0){
                if(s_n.at(i) - '0' == 9){
                    int j = i;
                    while(j >= 0){
                        if(s_n.at(j) - '0' == 9){
                            if(d.at(0) != 0) s_n.at(j) = '0';
                            else s_n.at(j) = min_use + '0';
                            j --;
                        }
                        else{
                            s_n.at(j) ++;
                            break;
                        }
                    }
                    if(j < 0){
                        s_n = to_string(min_use) + s_n;
                        flag = false;
                        break;
                    }
                    flag = false;
                }
                else s_n.at(i) += 1;
            }
        }
    }
    cout << s_n << endl;

}