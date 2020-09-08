#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;

#define rep(i, r) for(int i = 0; i < (int)(r); i ++)

int main(){
    int n; cin >> n;
    vector <ll> A(n);
    vector <ll> sum_of_A(n);

    rep(i, n){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());

    rep(i, n){
        sum_of_A.at(i) = A.at(i);
        if (i == 0) continue;
        sum_of_A.at(i) += sum_of_A.at(i - 1);
    }

    int b, e, m;
    b = 0;
    e = n - 1;
    while (abs(e - b) > 1){
        m = (e + b) / 2;
        ll num = sum_of_A.at(m);

        bool flag = true;
        for (int i = m + 1; i < n; i ++){
            if (num * 2 < A.at(i)) {
                flag = false;
                break;
            }
            num += A.at(i);
        }

        if (flag) e = m;
        else b = m;

    }

    ll num = sum_of_A.at(b);
    bool flag = true;
    for (int i = b + 1; i < n; i ++){
        if (num * 2 < A.at(i)) {
            flag = false;
            break;
        }
        num += A.at(i);
    }

    auto ans_itr = A.begin();
    if (flag) ans_itr = lower_bound(ALL(A), A.at(b));
    else ans_itr = lower_bound(ALL(A), A.at(e));
    cout << A.end() - ans_itr << endl;
}