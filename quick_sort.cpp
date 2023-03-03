#include <iostream>
#include <vector>

using namespace std;

void show(const vector<int> &data) {
    for (const auto &d : data) {
        cout << d << " ";
    }
    cout << endl;
}

void quick_sort(vector<int> &data, int left, int right) {
    int tmp = data.at(left);

    int i = left, j = right; 
    while(i <= j) {
        while (data[i] < tmp) {
            i++;
        }
        while (data[j] > tmp) {
            j--;
        }
        if (i <= j) {
            std::swap(data[i], data[j]);
            ++i;
            --j;
        }
    }
    show(data);
    if (left < j) {
        quick_sort(data, left, j);
    }
    if (i < right) {
        quick_sort(data, i, right);
    }
}

int main() {
    vector<int> data { 2, 1, 4, 8, 5, 3 };
    quick_sort(data, 0, data.size() - 1);
    show(data);
    return 0;
}
