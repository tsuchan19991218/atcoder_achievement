#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

string convert(string &s){
    string tmp = "";
    for(auto c: s){
        switch (c)
        {
        case 'b':
        case 'c':
            tmp.push_back('1');
            break;
        case 'd':
        case 'w':
            tmp.push_back('2');
            break;
        case 't':
        case 'j':
            tmp.push_back('3');
            break;
        case 'f':
        case 'q':
            tmp.push_back('4');
            break;
        case 'l':
        case 'v':
            tmp.push_back('5');
            break;
        case 's':
        case 'x':
            tmp.push_back('6');
            break;
        case 'p':
        case 'm':
            tmp.push_back('7');
            break;
        case 'h':
        case 'k':
            tmp.push_back('8');
            break;
        case 'n':
        case 'g':
            tmp.push_back('9');
            break;
        case 'z':
        case 'r':
            tmp.push_back('0');
            break;
        }
    }
    return tmp;
}

int main(){
    int n; cin >> n;
    vector <string> s(n);
    rep(i, n) cin >> s.at(i);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < (int)(s.at(i).size()); j ++){
            auto c = &s.at(i).at(j);
            if(*c >= 'A' && *c <= 'Z') *c += abs('A' - 'a');
        }
    }
    bool flag = false;
    for(auto str: s){
        auto ans = convert(str);
        if(ans.size() != 0){
            if(flag) cout << " ";
            cout << ans;
            flag = true;
        }
    }
    cout << endl;
}