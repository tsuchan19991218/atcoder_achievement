#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    string s; cin >> s;

    int cnt_r, cnt_l;
    cnt_r = 0; cnt_l = 0;

    deque <char> ans;

    bool cnt_start = false;

    int _cnt = 0;

    reverse(s.begin(), s.end());
    for(auto c: s){
        if(c == ')') cnt_start = true;
        if(cnt_start){
            if(c == ')') {
                _cnt += 1;
            }
            else{
                //cnt_l += 1;
                cnt_r += _cnt;
                cnt_r -= 1;
                if(cnt_r < 0) cnt_r = 0;
                _cnt = 0;
            }
        }
    }

    rep(i, _cnt + cnt_r) ans.push_front('(');

    cnt_r = 0; cnt_l = 0;
    cnt_start = false;
    if(ans.front() == '(') cnt_start = true;
    _cnt = 0;
    
    reverse(s.begin(), s.end());
    for(auto c: s){
        ans.push_back(c);
        if(c == '(') cnt_start = true;
        if(cnt_start){
            if(c == '(') {
                _cnt += 1;
            }
            else{
                //cnt_r += 1;
                cnt_l += _cnt;
                cnt_l -= 1;
                if(cnt_l < 0) cnt_l = 0;
                _cnt = 0;
            }
        }
    }

    rep(i, _cnt + cnt_l) ans.push_back(')');

    
    int size = ans.size();
    rep(i, size){
        cout << ans.front();
        ans.pop_front();
    }
    cout << endl;
}