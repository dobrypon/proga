#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>

using namespace std;


void printVector(const vector<float>& v) {
    cout << "Вектор: ";
    for (float val : v) {
        cout << fixed << setprecision(3) << val << " ";
    }
    cout << endl;
}


class Settings {
public:
    static map<string, string> Map;

    static void Add(const string& key, const string& value) {
        Map[key] = value;
    }

    static string Get(const string& key) {
        if (Map.find(key) != Map.end()) {
            return Map[key];
        }
        else {
            return "";
        }
    }

    static void Print() {
        cout << "Содержимое Map:\n";
        for (auto& pair : Map) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
};


map<string, string> Settings::Map;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const double M_PI = 3.14159;


    string name;
    cout << "Введите своё имя: ";
    getline(cin, name);


    Settings::Add("username", name);

    regex name_regex("^[А-ЯA-Z][а-яa-z]{1,31}$");
    if (regex_match(name, name_regex)) {
        cout << "Имя корректно!\n";
    }
    else {
        cout << "Имя некорректно!\n";
    }


    string inputStr;
    cout << "\nВведите строку: ";
    getline(cin, inputStr);

    if (inputStr.length() >= 4) {
        cout << "Подстрока с 2-го по 4-й символ: " << inputStr.substr(1, 3) << endl;
    }
    else {
        cout << "Строка слишком короткая для извлечения подстроки." << endl;
    }

    size_t pos = inputStr.find('a');
    if (pos != string::npos) {
        cout << "Индекс первого вхождения 'a': " << pos << endl;
    }
    else {
        cout << "Символа a не найдено" << endl;
    }


    string text = "Например: alice@example.com, bob123@mail.com";
    regex email_regex(R"(([\w._%+-]+@[\w.-]+\.[a-zA-Z]{2,}))");
    auto words_begin = sregex_iterator(text.begin(), text.end(), email_regex);
    auto words_end = sregex_iterator();

    cout << "\nНайденные e-mail адреса:\n";
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        cout << match.str() << endl;
    }


    double r;
    cout << "\nВведите радиус окружности: ";
    cin >> r;
    cin.ignore();

    double S = 2 * M_PI * r;
    cout << "Длина окружности: " << fixed << setprecision(3) << S << endl;


    string fileInput;
    string filename = "file.txt";

    while (true) {
        cout << "\nВведите строку (read, erase или exit для действий): ";
        getline(cin, fileInput);

        if (fileInput == "read") {
            ifstream infile(filename);
            if (infile.is_open()) {
                cout << "Содержимое файла:\n";
                string line;
                while (getline(infile, line)) {
                    cout << line << endl;
                }
                infile.close();
            }
            else {
                cout << "Файл пуст или не существует.\n";
            }
        }
        else if (fileInput == "erase") {
            ofstream outfile(filename, ofstream::trunc);
            outfile.close();
            cout << "Файл очищен.\n";
        }
        else if (fileInput == "exit") {
            cout << "Выход из программы.\n";
            break;
        }
        else {
            ofstream outfile(filename, ofstream::app);
            if (outfile.is_open()) {
                outfile << fileInput << endl;
                outfile.close();
            }
            else {
                cout << "Ошибка при открытии файла для записи.\n";
            }
        }
    }


    vector<float> vec = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
    cout << "\nПосле добавления 5 элементов:\n";
    printVector(vec);

    vec.insert(vec.begin() + 3, 99.9f);
    cout << "После вставки элемента между 3 и 4:\n";
    printVector(vec);

    vec.pop_back();
    cout << "После удаления последнего элемента:\n";
    printVector(vec);


    cout << "\nРабота с классом Settings:\n";
    Settings::Add("theme", "dark");
    Settings::Print();
    cout << "Get username: " << Settings::Get("username") << endl;

    return 0;
}
