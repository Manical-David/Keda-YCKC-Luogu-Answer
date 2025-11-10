#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string, int>> rounds;
    rounds.reserve(n);

    // Считываем все раунды игры
    for (int i = 0; i < n; i++){
        string name;
        int score;
        cin >> name >> score;
        rounds.push_back({name, score});
    }

    // Подсчитываем итоговый счет для каждого игрока
    map<string, int> finalScore;
    for (auto &r : rounds){
        finalScore[r.first] += r.second;
    }

    // Находим максимальный итоговый счет
    int maxScore = -1000000000;
    for (auto &entry : finalScore){
        if(entry.second > maxScore)
            maxScore = entry.second;
    }

    // Второй проход: определяем, кто из игроков с итоговым счетом maxScore
    // первым достиг суммы не меньше maxScore.
    map<string, int> cumulative;
    for (auto &r : rounds){
        cumulative[r.first] += r.second;
        if(cumulative[r.first] >= maxScore && finalScore[r.first] == maxScore){
            cout << r.first;
            break;
        }
    }

    return 0;
}
