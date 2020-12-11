#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

ll S_size = 10000000000;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    if(n == 1 && s == "1"){
        cout << 2 * S_size << endl;
        return 0;
    }
    vector <char> s1(2 * 10e5 + 5), s2(2 * 10e5 + 5), s3(2 * 10e5 + 5);
    rep(i, n){
        if(i % 3 == 0){
            s1.at(i) = '1';
            s2.at(i) = '1';
            s3.at(i) = '0';
        }
        else if(i % 3 == 1){
            s1.at(i) = '1';
            s2.at(i) = '0';
            s3.at(i) = '1';
        }
        else{
            s1.at(i) = '0';
            s2.at(i) = '1';
            s3.at(i) = '1';
        }
    }

    bool flag = true;
    int pat = -1;
    rep(num, 3){
        flag = true;
        rep(i, n){
            if(num == 0){
                if(s1.at(i) != s.at(i)) flag = false;
            }
            else if(num == 1){
                if(s2.at(i) != s.at(i)) flag = false;
            }
            else{
                if(s3.at(i) != s.at(i)) flag = false;
            }
        }
        if(flag) pat = 3 - num;
    }
    if(pat == -1){
        cout << 0 << endl;
        return 0;
    }

    if(n < 3){
        if(s == "01"){
            cout << S_size - 1 << endl;
            return 0;
        }
        cout << S_size << endl;
        return 0;
    }

    int cnt = 0;
    cnt = ((n - pat) / 3) + (((n - pat) % 3) != 0) + 1;
    //cout << cnt << endl;
    cout << S_size - cnt + 1 << endl;
}