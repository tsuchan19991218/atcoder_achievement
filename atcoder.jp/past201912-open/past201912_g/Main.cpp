#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int INF = 1000000005;

string int_to_3(int num, int n){
    string tmp = "";
    while(num > 0){
        tmp.push_back(num % 3 + '0');
        num /= 3;
    }
    while(tmp.size() < n) tmp.push_back('0');
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main(){
    int n; cin >> n;
    vector <vector<int>> a(n, vector<int>(n, -1));
    rep(i, n)for(int j = i + 1; j < n; j ++) cin >> a.at(i).at(j);

    int all_pat = pow(3, n);
    int ans = -INF;
    for(int one_pat = 0; one_pat < all_pat; one_pat ++){
        string str = int_to_3(one_pat, n);
        vector <vector<int>> groups(3);
        for(int i = 0; i < n; i ++){
            groups.at(str.at(i) - '0').push_back(i);
        }
        int ans_tmp = 0;
        for(auto group: groups){
            for(int i = 0; i < group.size(); i ++){
                for(int j = i + 1; j < group.size(); j ++){
                    ans_tmp += a.at(min(group.at(i), group.at(j))).at(max(group.at(i), group.at(j)));
                }
            }
        }
        ans = max(ans, ans_tmp);
    }
    cout << ans << endl;
}