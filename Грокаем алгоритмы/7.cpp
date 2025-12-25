#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


void task_lectures() {
    struct Lecture {
        int start;
        int end;
    };

    int N;
    cin >> N;
    vector<Lecture> lectures(N);
    for (auto& lec : lectures)
        cin >> lec.start >> lec.end;


    sort(lectures.begin(), lectures.end(), [](const Lecture& a, const Lecture& b) {
        return a.end < b.end;
        });

    int count = 0;
    int last_end = 0;

    for (auto& lec : lectures) {
        if (lec.start >= last_end) {
            count++;
            last_end = lec.end;
        }
    }

    cout << count << endl;
}


void task_boxes() {
    struct Box {
        int weight;
        int capacity;
    };

    int N;
    cin >> N;
    vector<Box> boxes(N);
    for (auto& box : boxes)
        cin >> box.weight >> box.capacity;

    
    sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
        if (a.weight + a.capacity != b.weight + b.capacity)
            return a.weight + a.capacity < b.weight + b.capacity;
        return a.capacity < b.capacity;
        });

    vector<long long> dp(N + 1, numeric_limits<long long>::max());
    dp[0] = 0;
    int max_boxes = 0;

    for (const auto& box : boxes) {
        for (int j = max_boxes; j >= 0; j--) {
            if (dp[j] <= box.capacity) {
                long long new_weight = dp[j] + box.weight;
                if (new_weight < dp[j + 1]) {
                    dp[j + 1] = new_weight;
                    max_boxes = max(max_boxes, j + 1);
                }
            }
        }
    }

    cout << max_boxes << endl;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int choice;
    cout << "Выберите задачу:\n";
    cout << "1 - Лекции\n";
    cout << "2 - Коробки\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите данные для задачи Лекции:\n";
        task_lectures();
        break;
    case 2:
        cout << "Введите данные для задачи Коробки:\n";
        task_boxes();
        break;
    default:
        cout << "Неверный выбор!" << endl;
    }

    return 0;
}
