#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile) {
        cerr << "Не удалось открыть файл input.txt\n";
        return 1;
    }

    unordered_set<int> numbers; 
    int x;

    while (infile >> x) {
        if (x > 0) {
            numbers.insert(x);       
        }
        else if (x < 0) {
            numbers.erase(-x);      
        }
        else { // x == 0
            break;                 
        }
    }

    vector<int> sorted_numbers(numbers.begin(), numbers.end());
    sort(sorted_numbers.begin(), sorted_numbers.end());


    for (size_t i = 0; i < sorted_numbers.size(); i++) {
        if (i > 0) outfile << " ";
        outfile << sorted_numbers[i];
    }
    outfile << endl;

    infile.close();
    outfile.close();

    return 0;
}