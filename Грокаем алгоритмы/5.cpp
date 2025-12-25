#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::map<char, std::vector<char>> graph{
        {'S', {'A', 'B'}},
        {'A', {'S'}},
        {'B', {'S', 'C', 'D'}},
        {'C', {'B', 'J'}},
        {'D', {'B', 'E'}},
        {'E', {'D', 'G'}},
        {'F', {'G'}},
        {'G', {'E', 'H'}},
        {'H', {'G', 'I'}},
        {'I', {'H', 'J'}},
        {'J', {'C', 'I'}}
    };

    char start = 'S';
    char finish = 'I';

    std::queue<char> q;
    std::map<char, bool> visited;
    std::map<char, char> parent;

    q.push(start);
    visited[start] = true;
    parent[start] = 0; 

    // BFS
    while (!q.empty()) {
        char current = q.front();
        q.pop();

        for (char neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (!visited[finish]) {
        std::cout << "Путь не найден" << std::endl;
        return 0;
    }

    std::vector<char> path;
    for (char v = finish; v != 0; v = parent[v]) {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    std::cout << "Самый короткий путь: " << path.size() - 1 << std::endl;

    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i + 1 < path.size())
            std::cout << " -> ";
    }
    std::cout << std::endl;

    return 0;
}
