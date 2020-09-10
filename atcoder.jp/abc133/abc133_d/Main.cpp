#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

int main(){
    int n; cin >> n;
    ll half_of_water = 0;
    vector <ll> gusu_sum, kisu_sum;
    vector <ll> A(n);
    rep(i, n) {
        cin >> A.at(i);
        half_of_water += A.at(i);
    }

    gusu_sum.push_back(A.at(0));
    kisu_sum.push_back(A.at(1));
    rep(i, n){
        if (i <= 1) continue;
        if (i % 2 == 0){
            gusu_sum.push_back(gusu_sum.back() + A.at(i));
        }
        else{
            kisu_sum.push_back(kisu_sum.back() + A.at(i));
        }
    }

    half_of_water /= 2;
    vector <ll> ans(n);

    rep(i, n){
        int first_index;
        ll min_sum = 0;
        if (i % 2 == 0){
            first_index = i - 2;
            if (first_index >= 0){
                min_sum += gusu_sum.at(first_index / 2);
            }
            min_sum += (kisu_sum.at(kisu_sum.size() - 1));
            if (i != 0){
                min_sum -= kisu_sum.at((i - 1) / 2);
            }
        }
        else{
            if (i >= 3){
                min_sum += kisu_sum.at((i - 2) / 2);
            }
            min_sum += (gusu_sum.at(gusu_sum.size() - 1));

            min_sum -= gusu_sum.at((i - 1) / 2);
        }

        cout << (half_of_water - min_sum) * 2 << " ";
    }
    cout << endl;
}