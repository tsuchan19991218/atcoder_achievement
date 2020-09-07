#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    long long int k, ans = 0;
    cin >> k;

    bool setubi = false;

    if (s.at(0) == s.at(s.size() - 1)) setubi = true;

    long long int b_seq, e_seq;
    b_seq = 1;
    e_seq = 1;
    if (setubi){

        for (int i = 1; i < s.size(); i ++){
            if (s.at(i) != s.at(i - 1)){
                break;
            }
            b_seq += 1;
        }
        string r_s(s);
        //reverse_copy(s.begin(), s.end(), r_s);
        reverse(r_s.begin(), r_s.end());
        for (int i = 1; i < r_s.size(); i ++){
            if (r_s.at(i) != r_s.at(i - 1)){
                break;
            }
            e_seq += 1;
        }
        if (b_seq + e_seq >= s.size()){
            ans = (k * s.size()) / 2;
        }
        else{
            ans += (b_seq / 2) + (e_seq / 2);
            ans += ((b_seq + e_seq) / 2) * (k - 1);

            string sub_s = s.substr(b_seq, s.size() - b_seq - e_seq);
            long long seq_cnt = 1;
            for (int i = 1; i < sub_s.size(); i ++){
                if (sub_s.at(i - 1) == sub_s.at(i)){
                    seq_cnt += 1;
                    continue;
                }
                else{
                    ans += (seq_cnt / 2) * k;
                    seq_cnt = 1;
                }
            }
            ans += (seq_cnt / 2) * k;
        }

    }
    else{
        long long seq_cnt = 1;
        for (int i = 1; i < s.size(); i ++){
                if (s.at(i - 1) == s.at(i)){
                    seq_cnt += 1;
                    continue;
                }
                else{
                    ans += (seq_cnt / 2) * k;
                    seq_cnt = 1;
                }
            }
            ans += (seq_cnt / 2) * k;
    }


    cout << ans << endl;
}