#include <iostream>
#include <vector>

using namespace std;

/**
 * 数组旋转
 * */

void turn_round(vector<int> &data, int left, int right) {
    while (left < right) {
        std::swap(data[left], data[right]);
        ++left;
        --right;
    }
}

void show(const vector<int> &data) {
    for (const auto &d : data) {
        cout << d << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data { 1, 2, 3, 4, 5, 6 };
    turn_round(data, 0, 2 - 1);
    turn_round(data, 2, data.size() - 1);
    turn_round(data, 0, data.size() - 1);
    show(data);
}
