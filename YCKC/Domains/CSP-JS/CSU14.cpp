#include <bits/stdc++.h>
using namespace std;
struct Player {
    set<int>不屈牌;
    bool 加一马 = false;
    bool 减一马 = false;
    vector<char>手牌;
    bool check(Player 对手) const {
        if (!减一马 && 对手.加一马) {
            return false;
        }
        return true;
    }
    bool add不屈牌(int 点数, int& 牌堆索引, const vector<int>& 点s) {
        if (不屈牌.count(点数)) {
            return true;
        }
        不屈牌.insert(点数);
        return false;
    }
};
int main() {
    int n;
    cin >> n;
    string str;  // 牌类型
    vector<int> pts(n);  // 牌点数
    cin >> str;
    for (int i = 0; i < n; i++) {
        cin >> pts[i];
    }
    int myc, tuc;
    cin >> myc >> tuc;
    Player tu;
    Player op;
    tu.不屈牌.insert(myc);
    op.不屈牌.insert(tuc);
    int 牌堆索引 = 0;
    int 当前回合玩家 = 0;
    bool 游戏结束 = false;
    string 结果 = "ping";
    while (牌堆索引 < n && !游戏结束) {
        Player& 当前玩家 = (当前回合玩家 == 0) ? tu : op;
        Player& 对方玩家 = (当前回合玩家 == 0) ? op : tu;
        vector<char>新手牌;
        for (int i = 0; i < 2 && 牌堆索引 < n; i++) {
            新手牌.push_back(str[牌堆索引]);
            牌堆索引++;
        }
        bool flag = false;
        for (char card : 新手牌) {
            if (card == '+') {
                当前玩家.加一马 = true;
            } else if (card == '-') {
                当前玩家.减一马 = true;
            } else if (card == 'a') {
                flag = true;
            }
        }
        if (flag && 当前玩家.check(对方玩家)) {
            if (牌堆索引 >= n) {
                结果 = "ping";
                游戏结束 = true;
                break;
            }
            int 不屈点数 = pts[牌堆索引];
            牌堆索引++;
            bool 对手死亡 = 对方玩家.add不屈牌(不屈点数, 牌堆索引, pts);
            if (对手死亡) {
                结果 = (当前回合玩家 == 0) ? "win" : "lose";
                游戏结束 = true;
                break;
            }
        }
        当前回合玩家 = 1 - 当前回合玩家;
    }
    cout << 结果 << '\n';
    return 0;
}