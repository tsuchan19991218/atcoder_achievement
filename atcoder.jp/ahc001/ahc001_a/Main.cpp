#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)

vector <int> dy = {0, 1, 0, -1};
vector <int> dx = {1, 0, -1, 0};

const int INF = 1000000000;
const ll INFLL = 100000000000000000;

int individual_cnt = 7;
int learning_cnt = 1200;

struct Status {
    double score; //score
    vector <pair<int, int>> L_D; // 広告の左下座標
    vector <pair<int, int>> R_U; // 広告の右上座標
    vector <int> is_big; // 面積が理想よりも大きいか否か

    Status():score(),L_D(205),R_U(205),is_big(205)
    {
        score = 0;
    }

};

vector <Status> now_individuals(individual_cnt); //　現世代

vector <pair<int, int>> add_core; // 広告の核の座標
vector <pair<int, int>> sorted_core_xy, sorted_core_yx;

bool tmp_judge(int l1, int r1, int l2, int r2){
    if(l1 > l2){
        swap(l1, l2);
        swap(r1, r2);
    }

    if(l1 <= l2 && l2 < r2 && r2 <= r1) return true;
    return false;
}

void FIX(Status &one_individual){ // 重なっている広告を修正する
    for(int i = 0; i < add_core.size(); i ++){
        for(int j = 0; j < add_core.size(); j ++){
            if(i == j) continue;
            int L_i = one_individual.L_D.at(i).first;
            int D_i = one_individual.L_D.at(i).second;
            int R_i = one_individual.R_U.at(i).first;
            int U_i = one_individual.R_U.at(i).second;

            int L_j = one_individual.L_D.at(j).first;
            int D_j = one_individual.L_D.at(j).second;
            int R_j = one_individual.R_U.at(j).first;
            int U_j = one_individual.R_U.at(j).second;

            // 重なってないならスルー
            //if(L_i > L_j) continue;
            if(L_i < R_i && R_i <= L_j && L_j < R_j) continue;
            if(L_j < R_j && R_j <= L_i && L_i < R_i) continue;
            if(D_i < U_i && U_i <= D_j && D_j < U_j) continue;
            if(D_j < U_j && U_j <= D_i && D_i < U_i) continue;
            //cout << i << " " << j << endl;
            // 特別な場合
            if(tmp_judge(L_i, R_i, L_j, R_j)){
                int LEFT; int RIGHT;
                if(add_core.at(i).first < add_core.at(j).first){
                    LEFT = i;
                    RIGHT = j;
                }
                else{
                    LEFT = j;
                    RIGHT = i;
                }
                int tmp = add_core.at(LEFT).first + add_core.at(RIGHT).first + 1;
                tmp /= 2;
                // if(tmp <= add_core.at(LEFT).first) tmp = add_core.at(LEFT).first + 1;
                // if(tmp > add_core.at(RIGHT).first) tmp = add_core.at(RIGHT).first;
                one_individual.R_U.at(LEFT).first = min(one_individual.R_U.at(LEFT).first, tmp);
                one_individual.L_D.at(RIGHT).first = max(one_individual.L_D.at(RIGHT).first, tmp);

                continue;
                
            }
            // 重なってたら
            int dice = rand() % 2;
            if(dice == 0){
                // まず横を縮める
                int flag = false; //　横に縮めた時のフラグ
                if(!(L_i <= L_j && L_j < R_j && R_j <= R_i) || !(L_j <= L_i && L_i < R_i && R_i <= R_j)){ //横に縮めても意味ない場合は除く
                    int LEFT; int RIGHT;
                    if(L_i < L_j){
                        LEFT = i;
                        RIGHT = j;
                    }
                    else{
                        LEFT = j;
                        RIGHT = i;
                    }
                    // 核の位置によっては横に縮められない可能性がある
                    if(add_core.at(LEFT).first < add_core.at(RIGHT).first){
                        int tmp = one_individual.R_U.at(LEFT).first + one_individual.L_D.at(RIGHT).first + 1;
                        tmp /= 2;
                        if(tmp <= add_core.at(LEFT).first) tmp = add_core.at(LEFT).first + 1;
                        if(tmp > add_core.at(RIGHT).first) tmp = add_core.at(RIGHT).first;
                        one_individual.R_U.at(LEFT).first = tmp;
                        one_individual.L_D.at(RIGHT).first = tmp;
                        flag = true;
                        //cout << "横変化" << endl;
                    }
                }
                // 横に縮めてないときは縦に縮められる
                if(!flag){
                    int UP, DOWN;
                    if(D_i < D_j){
                        DOWN = i;
                        UP = j;
                    }
                    else{
                        DOWN = j;
                        UP = i;
                    }
                    int tmp = one_individual.R_U.at(DOWN).second + one_individual.L_D.at(UP).second + 1;
                    tmp /= 2;
                    if(tmp <= add_core.at(DOWN).second) tmp = add_core.at(DOWN).second + 1;
                    if(tmp > add_core.at(UP).second) tmp = add_core.at(UP).second;
                    one_individual.R_U.at(DOWN).second = tmp;
                    one_individual.L_D.at(UP).second = tmp;
                    //cout << "縦変化" << endl;
                }
            }
            else{
                // まず横を縮める
                int flag = false; //　横に縮めた時のフラグ
                if(!(D_i <= D_j && D_j < U_j && U_j <= U_i) || !(D_j <= D_i && D_i < U_i && U_i <= U_j)){ //横に縮めても意味ない場合は除く
                    int LEFT; int RIGHT;
                    if(D_i < D_j){
                        LEFT = i;
                        RIGHT = j;
                    }
                    else{
                        LEFT = j;
                        RIGHT = i;
                    }
                    // 核の位置によっては横に縮められない可能性がある
                    if(add_core.at(LEFT).second < add_core.at(RIGHT).second){
                        int tmp = one_individual.R_U.at(LEFT).second + one_individual.L_D.at(RIGHT).second + 1;
                        tmp /= 2;
                        if(tmp <= add_core.at(LEFT).second) tmp = add_core.at(LEFT).second + 1;
                        if(tmp > add_core.at(RIGHT).second) tmp = add_core.at(RIGHT).second;
                        one_individual.R_U.at(LEFT).second = tmp;
                        one_individual.L_D.at(RIGHT).second = tmp;
                        flag = true;
                        //cout << "横変化" << endl;
                    }
                }
                // 横に縮めてないときは縦に縮められる
                if(!flag){
                    int UP, DOWN;
                    if(L_i < L_j){
                        DOWN = i;
                        UP = j;
                    }
                    else{
                        DOWN = j;
                        UP = i;
                    }
                    int tmp = one_individual.R_U.at(DOWN).first + one_individual.L_D.at(UP).first + 1;
                    tmp /= 2;
                    if(tmp <= add_core.at(DOWN).first) tmp = add_core.at(DOWN).first + 1;
                    if(tmp > add_core.at(UP).first) tmp = add_core.at(UP).first;
                    one_individual.R_U.at(DOWN).first = tmp;
                    one_individual.L_D.at(UP).first = tmp;
                    //cout << "縦変化" << endl;
                }
            }
        }
    }
}

// 世代まとめてスコア計算
vector <double> ideal; // 理想の面積
void cal_score(vector <Status> &individuals){
    for(int I = 0; I < individual_cnt; I ++){
        double tmp_score = 0;
        for(int i = 0; i < ideal.size(); i ++){
            double S = individuals.at(I).R_U.at(i).first - individuals.at(I).L_D.at(i).first;
            S *= individuals.at(I).R_U.at(i).second - individuals.at(I).L_D.at(i).second;

            if(S >= ideal.at(i)) individuals.at(I).is_big.at(i) = 1;
            else individuals.at(I).is_big.at(i) = -1;

            tmp_score += 1.0 - (1.0 - (min(S, ideal.at(i))/max(S, ideal.at(i)))) * (1.0 - (min(S, ideal.at(i))/max(S, ideal.at(i))));
        }
        individuals.at(I).score = tmp_score;
    }
}

void init(){ // 初期化 第１世代目の決定
    for(int I = 0; I < individual_cnt; I ++){
        for(int i = 0; i < add_core.size(); i ++){
            int core_x = add_core.at(i).first;
            int core_y = add_core.at(i).second;
            // 今考えている広告の核を原点へ座標変換した時の最小x,yを求める
            int tmp = INF;
            for(int j = 0; j < add_core.size(); j ++){
                if(i == j) continue;
                int dist_yoko = add_core.at(j).first - core_x;
                if(dist_yoko < 0){
                    dist_yoko += 1;
                    dist_yoko *= -1;
                }
                int dist_tate = add_core.at(j).second - core_y;
                if(dist_tate < 0){
                    dist_tate += 1;
                    dist_tate *= -1;
                }
                //if(I == 0) cout << dist_yoko << " " << dist_tate << endl;
                tmp = min(tmp, max(dist_yoko, dist_tate));
            }
            if(tmp == 0) tmp = 1;
            if(tmp != 0)now_individuals.at(I).L_D.at(i) = make_pair(max(0, core_x - (rand() % tmp)), max(0, core_y - (rand() % tmp)));
            now_individuals.at(I).R_U.at(i) = make_pair(min(10000, core_x + (rand() % tmp + 1)), min(10000, core_y + (rand() % tmp + 1)));
        }
        FIX(now_individuals.at(I));
    }
}

// 2つの現個体を混ぜ合わせ、新しい個体を生成する O(N)
void cross(Status &now_indi_1, Status &now_indi_2, Status &next_indi){
    
    for(int i = 0; i < add_core.size(); i ++){
        int dice = rand() % 3;
        if(dice == 0){
            next_indi.L_D.at(i).first = now_indi_1.L_D.at(i).first;
            next_indi.L_D.at(i).second = now_indi_1.L_D.at(i).second;
            next_indi.R_U.at(i).first = now_indi_1.R_U.at(i).first;
            next_indi.R_U.at(i).second = now_indi_1.R_U.at(i).second;
        }
        if(dice == 1){
            next_indi.L_D.at(i).first = now_indi_2.L_D.at(i).first;
            next_indi.L_D.at(i).second = now_indi_2.L_D.at(i).second;
            next_indi.R_U.at(i).first = now_indi_2.R_U.at(i).first;
            next_indi.R_U.at(i).second = now_indi_2.R_U.at(i).second;
        }
        if(dice == 2){
            next_indi.L_D.at(i).first = (now_indi_2.L_D.at(i).first + now_indi_1.L_D.at(i).first) / 2;
            next_indi.L_D.at(i).second = (now_indi_2.L_D.at(i).second + now_indi_1.L_D.at(i).second) / 2;
            next_indi.R_U.at(i).first = (now_indi_2.R_U.at(i).first + now_indi_1.R_U.at(i).first) / 2;
            next_indi.R_U.at(i).second = (now_indi_2.R_U.at(i).second + now_indi_1.R_U.at(i).second) / 2;
        }
    }

    // 広告が重なっている可能性がある
    FIX(next_indi);
}

// 適応 (面積が大きいものは小さくする、逆も然り　自分の核を含み、他人の核を含まないようにする)
void adaptation(Status &one_individual){
    for(int i = 0; i < add_core.size(); i ++){
        if(one_individual.is_big.at(i) == 1){
            int allowance = add_core.at(i).first - one_individual.L_D.at(i).first;
            //allowance = max(1, allowance);
            int NEW_LEFT = one_individual.L_D.at(i).first + (allowance / 4);

            allowance = add_core.at(i).second - one_individual.L_D.at(i).second;
            //allowance = max(1, allowance);
            int NEW_DOWN = one_individual.L_D.at(i).second + (allowance / 4);

            allowance = one_individual.R_U.at(i).first - add_core.at(i).first;
            //allowance = max(1, allowance);
            int NEW_RIGHT = one_individual.R_U.at(i).first - (allowance / 4);

            allowance = one_individual.R_U.at(i).second - add_core.at(i).second;
            //allowance = max(1, allowance);
            int NEW_UP = one_individual.R_U.at(i).second - (allowance / 4);

            one_individual.L_D.at(i).first = NEW_LEFT;
            one_individual.L_D.at(i).second = NEW_DOWN;
            one_individual.R_U.at(i).first = NEW_RIGHT;
            one_individual.R_U.at(i).second = NEW_UP;

            // if(NEW_LEFT >= NEW_RIGHT) cout << "aaaaaaaa" << endl;
            // if(NEW_DOWN >= NEW_UP) cout << "bbbbbbbb" << endl;
        }
        if(one_individual.is_big.at(i) == -1){
            int dice = rand() % 2; //上下左右どの方向に伸ばすか
            int NOW_LEFT = one_individual.L_D.at(i).first;
            int NOW_DOWN = one_individual.L_D.at(i).second;
            int NOW_RIGHT = one_individual.R_U.at(i).first;
            int NOW_UP = one_individual.R_U.at(i).second;
            if(dice == 0){ // LEFT
                int LIMIT_LEFT = 0;
                for(int j = 0; j < add_core.size(); j ++){ // 全ての広告の核を全探索
                    if(one_individual.R_U.at(j).first <= one_individual.L_D.at(i).first){
                        int D_i = one_individual.L_D.at(i).second;
                        int U_i = one_individual.R_U.at(i).second;

                        int D_j = one_individual.L_D.at(j).second;
                        int U_j = one_individual.R_U.at(j).second;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_LEFT = max(LIMIT_LEFT, one_individual.R_U.at(j).first);
                    }
                    // if(sorted_core_xy.at(j).first > NOW_LEFT) break;
                    // // 伸ばすと含んでしまう核を特定
                    // if(NOW_DOWN <= sorted_core_xy.at(j).second && sorted_core_xy.at(j).second <= NOW_UP){
                    //     LIMIT_LEFT = sorted_core_xy.at(j).first + 1;
                    // }
                }
                if(NOW_LEFT < LIMIT_LEFT) LIMIT_LEFT = NOW_LEFT;
                int allowance = NOW_LEFT - LIMIT_LEFT;
                one_individual.L_D.at(i).first = one_individual.L_D.at(i).first - ((allowance + 1) / 2);
            }
            if(dice == 1){ // DOWN
                int LIMIT_DOWN = 0;
                for(int j = 0; j < add_core.size(); j ++){ // 全ての広告の核を全探索
                    if(one_individual.R_U.at(j).second <= one_individual.L_D.at(i).second){
                        int D_i = one_individual.L_D.at(i).first;
                        int U_i = one_individual.R_U.at(i).first;

                        int D_j = one_individual.L_D.at(j).first;
                        int U_j = one_individual.R_U.at(j).first;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_DOWN = max(LIMIT_DOWN, one_individual.R_U.at(j).second);
                    }
                }
                if(NOW_DOWN < LIMIT_DOWN) LIMIT_DOWN = NOW_DOWN;
                int allowance = NOW_DOWN - LIMIT_DOWN;
                one_individual.L_D.at(i).second = one_individual.L_D.at(i).second - ((allowance + 1) / 2);
            }
            if(dice == 0){ // RIGHT
                int LIMIT_RIGHT = 10000;
                for(int j = add_core.size() - 1; j >= 0; j --){ // 全ての広告の核を全探索
                    if(one_individual.R_U.at(i).first <= one_individual.L_D.at(j).first){
                        int D_i = one_individual.L_D.at(i).second;
                        int U_i = one_individual.R_U.at(i).second;

                        int D_j = one_individual.L_D.at(j).second;
                        int U_j = one_individual.R_U.at(j).second;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_RIGHT = min(LIMIT_RIGHT, one_individual.L_D.at(j).first);
                    }
                }
                if(NOW_RIGHT > LIMIT_RIGHT) LIMIT_RIGHT = NOW_RIGHT;
                int allowance = LIMIT_RIGHT - NOW_RIGHT;
                one_individual.R_U.at(i).first = one_individual.R_U.at(i).first + ((allowance + 1) / 2);
            }
            if(dice == 1){ // UP
                int LIMIT_UP = 10000;
                for(int j = add_core.size() - 1; j >= 0; j --){ // 全ての広告の核を全探索
                    if(one_individual.R_U.at(i).second <= one_individual.L_D.at(j).second){
                        int D_i = one_individual.L_D.at(i).first;
                        int U_i = one_individual.R_U.at(i).first;

                        int D_j = one_individual.L_D.at(j).first;
                        int U_j = one_individual.R_U.at(j).first;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_UP = min(LIMIT_UP, one_individual.L_D.at(j).second);
                    }
                }
                if(NOW_UP > LIMIT_UP) LIMIT_UP = NOW_UP;
                int allowance = LIMIT_UP - NOW_UP;
                one_individual.R_U.at(i).second = one_individual.R_U.at(i).second + ((allowance + 1) / 2);
            }
        }
    }
    FIX(one_individual);
}

// 突然変異 (面積が大きい広告の面積が確率で大きく減る)
void mutation(Status &one_individual){ 
    for(int i = 0; i < add_core.size(); i ++){
        if(rand() % 3 == 0){
            if(rand() % 2){
                int allowance = add_core.at(i).first - one_individual.L_D.at(i).first;
                int NEW_LEFT = one_individual.L_D.at(i).first + (allowance / ((rand() % 3) + 2));

                allowance = add_core.at(i).second - one_individual.L_D.at(i).second;
                int NEW_DOWN = one_individual.L_D.at(i).second + (allowance / ((rand() % 3) + 2));

                one_individual.L_D.at(i).first = NEW_LEFT;
                one_individual.L_D.at(i).second = NEW_DOWN;
            }
            else{
                int allowance = one_individual.R_U.at(i).first - add_core.at(i).first - 1;
                int NEW_RIGHT = one_individual.R_U.at(i).first - (allowance / ((rand() % 3) + 2));

                allowance = one_individual.R_U.at(i).second - add_core.at(i).second - 1;
                int NEW_UP = one_individual.R_U.at(i).second - (allowance / ((rand() % 3) + 2));

                one_individual.R_U.at(i).first = NEW_RIGHT;
                one_individual.R_U.at(i).second = NEW_UP;
            }
        }
        else{
            if(rand() % 2){
                int LIMIT_LEFT = 0;
                int LIMIT_RIGHT = 10000;
                for(int j = 0; j < add_core.size(); j ++){
                    if(one_individual.R_U.at(i).first <= one_individual.L_D.at(j).first){
                        int D_i = one_individual.L_D.at(i).second;
                        int U_i = one_individual.R_U.at(i).second;

                        int D_j = one_individual.L_D.at(j).second;
                        int U_j = one_individual.R_U.at(j).second;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_RIGHT = min(LIMIT_RIGHT, one_individual.L_D.at(j).first);
                    }
                    if(one_individual.R_U.at(j).first <= one_individual.L_D.at(i).first){
                        int D_i = one_individual.L_D.at(i).second;
                        int U_i = one_individual.R_U.at(i).second;

                        int D_j = one_individual.L_D.at(j).second;
                        int U_j = one_individual.R_U.at(j).second;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_LEFT = max(LIMIT_LEFT, one_individual.R_U.at(j).first);
                    }
                }
                one_individual.R_U.at(i).first = LIMIT_RIGHT;
                one_individual.L_D.at(i).first = LIMIT_LEFT;
            }
            else{
                int LIMIT_DOWN = 0;
                int LIMIT_UP = 10000;
                for(int j = 0; j < add_core.size(); j ++){
                    if(one_individual.R_U.at(i).second <= one_individual.L_D.at(j).second){
                        int D_i = one_individual.L_D.at(i).first;
                        int U_i = one_individual.R_U.at(i).first;

                        int D_j = one_individual.L_D.at(j).first;
                        int U_j = one_individual.R_U.at(j).first;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_UP = min(LIMIT_UP, one_individual.L_D.at(j).second);
                    }
                    if(one_individual.R_U.at(j).second <= one_individual.L_D.at(i).second){
                        int D_i = one_individual.L_D.at(i).first;
                        int U_i = one_individual.R_U.at(i).first;

                        int D_j = one_individual.L_D.at(j).first;
                        int U_j = one_individual.R_U.at(j).first;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_DOWN = max(LIMIT_DOWN, one_individual.R_U.at(j).second);
                    }
                }
                one_individual.R_U.at(i).second = LIMIT_UP;
                one_individual.L_D.at(i).second = LIMIT_DOWN;
            }
        }
    }
}

// 世代内をスコア順にソート
void SORT(vector <Status> &individuals){
    vector <pair<double, int>> score_index(individuals.size());
    vector <Status> _individuals(individuals.size());
    copy(individuals.begin(), individuals.end(), _individuals.begin());
    int i = 0;
    for(auto indi: individuals){
        score_index.at(i) = make_pair(indi.score, i);
        i ++;
    }
    sort(score_index.rbegin(), score_index.rend());
    for(int i = 0; i < individuals.size(); i ++){
        individuals.at(i) = _individuals.at(score_index.at(i).second);
    }
}

// すでにソートされている現世代、次世代から生き残りを選択する
void select(vector <Status> &now_individuals, vector <Status> &next_individuals){
    vector <Status> survive_individuals(individual_cnt);
    int cnt = 0;
    survive_individuals.at(cnt) = now_individuals.at(cnt);
    cnt ++;
    rep(i, (individual_cnt / 2) - 1){
        survive_individuals.at(cnt) = now_individuals.at(rand() % individual_cnt);
        cnt ++;
    }
    rep(i, (individual_cnt / 2)){
        survive_individuals.at(cnt) = next_individuals.at(rand() % individual_cnt);
        cnt ++;
    }

    if(cnt < individual_cnt){
        survive_individuals.at(cnt) = next_individuals.at(rand() % individual_cnt);
    }

    now_individuals = survive_individuals;

}

// 現世代から次世代を生成し、生き残りを選択
void generate_next_individuals(vector <Status> &now_individuals, vector <Status> &next_individuals){
    //SORT(now_individuals);
    rep(i, individual_cnt){
        // 現世代の最も優秀なものは残す
        if(i == 0){
            next_individuals.at(i) = now_individuals.at(i);
            continue;
        }

        // 生成方法をランダムに決定
        // 交叉
        int dice_1 = rand() % individual_cnt;
        int dice_2 = rand() % individual_cnt;
        while(dice_2 == dice_1) dice_2 = rand() % individual_cnt;
        cross(now_individuals.at(dice_1), now_individuals.at(dice_2), next_individuals.at(i));
        //
        // 30%の確率で適応する
        if(rand() % 2 == 0) adaptation(next_individuals.at(i));
        // 10%の確率で突然変異
        if(rand() % 10 == 0) mutation(next_individuals.at(i));
    }
    // 次世代のスコアを計算しておく
    cal_score(next_individuals);
    SORT(next_individuals);

    // 生き残りの選択
    select(now_individuals, next_individuals);
    SORT(now_individuals);
}

void last_task(vector <Status> &now_individuals){
    for(int I = 0; I < individual_cnt; I ++){
        for(int i = 0; i < add_core.size(); i ++){
            if(now_individuals.at(I).is_big.at(i) == 1){
                double R = ideal.at(i);
                double S;
                double NOW_LEFT, NOW_RIGHT, NOW_DOWN, NOW_UP;
                NOW_LEFT = now_individuals.at(I).L_D.at(i).first;
                NOW_DOWN = now_individuals.at(I).L_D.at(i).second;
                NOW_RIGHT = now_individuals.at(I).R_U.at(i).first;
                NOW_UP = now_individuals.at(I).R_U.at(i).second;
                double d_x, d_y;
                d_x = NOW_RIGHT - NOW_LEFT;
                d_y = NOW_UP - NOW_DOWN;
                S = d_x * d_y;
                double p = R / S;
                if(p >= 1) continue;
                double g_d_x = d_x * p;
                int NEW_LEFT = NOW_RIGHT - g_d_x;
                NEW_LEFT = min(add_core.at(i).first, NEW_LEFT);
                now_individuals.at(I).L_D.at(i).first = NEW_LEFT;

                NOW_LEFT = now_individuals.at(I).L_D.at(i).first;
                d_x = NOW_RIGHT - NOW_LEFT;
                S = d_x * d_y;
                p = R / S;
                g_d_x = d_x * p;
                int NEW_RIGHT = NOW_LEFT + g_d_x;
                NEW_RIGHT = max(add_core.at(i).first + 1, NEW_RIGHT);
                now_individuals.at(I).R_U.at(i).first = NEW_RIGHT;


            }
            else{
                double R = ideal.at(i);
                double S;
                double NOW_LEFT, NOW_RIGHT, NOW_DOWN, NOW_UP;
                NOW_LEFT = now_individuals.at(I).L_D.at(i).first;
                NOW_DOWN = now_individuals.at(I).L_D.at(i).second;
                NOW_RIGHT = now_individuals.at(I).R_U.at(i).first;
                NOW_UP = now_individuals.at(I).R_U.at(i).second;
                double d_x, d_y;
                d_x = NOW_RIGHT - NOW_LEFT;
                d_y = NOW_UP - NOW_DOWN;
                S = d_x * d_y;
                double p = R / S;
                double g_d_x = d_x * p;
                int NEW_LEFT = NOW_RIGHT - g_d_x;
                int LIMIT_LEFT = 0;
                for(int j = 0; j < add_core.size(); j ++){
                    if(i == j) continue;
                    if(now_individuals.at(I).R_U.at(j).first <= now_individuals.at(I).L_D.at(i).first){
                        int D_i = now_individuals.at(I).L_D.at(i).second;
                        int U_i = now_individuals.at(I).R_U.at(i).second;

                        int D_j = now_individuals.at(I).L_D.at(j).second;
                        int U_j = now_individuals.at(I).R_U.at(j).second;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_LEFT = max(LIMIT_LEFT, now_individuals.at(I).R_U.at(j).first);
                    }
                }
                NEW_LEFT = max(NEW_LEFT, LIMIT_LEFT);
                now_individuals.at(I).L_D.at(i).first = NEW_LEFT;
                NOW_LEFT = now_individuals.at(I).L_D.at(i).first;

                d_x = NOW_RIGHT - NOW_LEFT;
                S = d_x * d_y;
                p = R / S;
                if(p <= 1) continue;
                g_d_x = d_x * p;
                int NEW_RIGHT = NOW_LEFT + g_d_x;
                int LIMIT_RIGHT = 10000;
                for(int j = 0; j < add_core.size(); j ++){
                    if(i == j) continue;
                    if(now_individuals.at(I).R_U.at(i).first <= now_individuals.at(I).L_D.at(j).first){
                        int D_i = now_individuals.at(I).L_D.at(i).second;
                        int U_i = now_individuals.at(I).R_U.at(i).second;

                        int D_j = now_individuals.at(I).L_D.at(j).second;
                        int U_j = now_individuals.at(I).R_U.at(j).second;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_RIGHT = min(LIMIT_RIGHT, now_individuals.at(I).L_D.at(j).first);
                    }
                }
                NEW_RIGHT = min(NEW_RIGHT, LIMIT_RIGHT);
                now_individuals.at(I).R_U.at(i).first = NEW_RIGHT;
                NOW_RIGHT = now_individuals.at(I).R_U.at(i).first;

                d_x = NOW_RIGHT - NOW_LEFT;
                S = d_x * d_y;
                p = R / S;
                if(p <= 1) continue;
                double g_d_y = d_y * p;
                int NEW_DOWN = NOW_UP - g_d_y;
                int LIMIT_DOWN = 0;
                for(int j = 0; j < add_core.size(); j ++){
                    if(i == j) continue;
                    if(now_individuals.at(I).R_U.at(j).second <= now_individuals.at(I).L_D.at(i).second){
                            int D_i = now_individuals.at(I).L_D.at(i).first;
                            int U_i = now_individuals.at(I).R_U.at(i).first;

                            int D_j = now_individuals.at(I).L_D.at(j).first;
                            int U_j = now_individuals.at(I).R_U.at(j).first;

                            if(U_i < D_j) continue;
                            if(D_i > U_j) continue;

                            LIMIT_DOWN = max(LIMIT_DOWN, now_individuals.at(I).R_U.at(j).second);
                    }
                }
                NEW_DOWN = max(NEW_DOWN, LIMIT_DOWN);
                now_individuals.at(I).L_D.at(i).second = NEW_DOWN;
                NOW_DOWN = now_individuals.at(I).L_D.at(i).second;

                d_y = NOW_UP - NOW_DOWN;
                S = d_x * d_y;
                p = R / S;
                if(p <= 1) continue;
                g_d_y = d_y * p;
                int NEW_UP = NOW_DOWN + g_d_y;
                int LIMIT_UP = 10000;
                for(int j = 0; j < add_core.size(); j ++){
                    if(i == j) continue;
                    if(now_individuals.at(I).R_U.at(i).second <= now_individuals.at(I).L_D.at(j).second){
                        int D_i = now_individuals.at(I).L_D.at(i).first;
                        int U_i = now_individuals.at(I).R_U.at(i).first;

                        int D_j = now_individuals.at(I).L_D.at(j).first;
                        int U_j = now_individuals.at(I).R_U.at(j).first;

                        if(U_i < D_j) continue;
                        if(D_i > U_j) continue;

                        LIMIT_UP = min(LIMIT_UP, now_individuals.at(I).L_D.at(j).second);
                    }
                }
                NEW_UP = min(NEW_UP, LIMIT_UP);
                now_individuals.at(I).R_U.at(i).second = NEW_UP;
            }
        }
    }
    cal_score(now_individuals);
    SORT(now_individuals);
}


int main(){
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    rep(i, n){
        //cin >> add_core.at(i).first >> add_core.at(i).second >> ideal.at(i);
        int x, y; cin >> x >> y;
        double r; cin >> r;
        add_core.push_back(make_pair(x, y));
        sorted_core_xy.push_back(make_pair(x, y));
        sorted_core_yx.push_back(make_pair(y, x));
        ideal.push_back(r);
    }
    sort(sorted_core_xy.begin(), sorted_core_xy.end());
    sort(sorted_core_yx.begin(), sorted_core_yx.end());
    // 初期設定
    init();
    cal_score(now_individuals);
    SORT(now_individuals);
    //cout << "初期化完了" << endl;
    vector <Status> next_individuals(individual_cnt);
    rep(i, learning_cnt){
        //cout << "第" << i << "世代" << endl;
        //for(auto individual: now_individuals){
            //cout << individual.score << endl;
        //}
        generate_next_individuals(now_individuals, next_individuals);
    }

    last_task(now_individuals);

    for(int i = 0; i < n; i ++){
        cout << now_individuals.at(0).L_D[i].first << " ";
        cout << now_individuals.at(0).L_D[i].second << " ";
        cout << now_individuals.at(0).R_U[i].first << " ";
        cout << now_individuals.at(0).R_U[i].second << " ";
        cout << endl;
    }


}