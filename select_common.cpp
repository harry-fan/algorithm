#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 选择公共元素
 * */

vector<int> select_common(const vector<int> &vec1, const vector<int> &vec2) {
    map<int, int> cnt; 
    for (const auto &vec : vec1) {
        cnt[vec] += 1;
    }
    vector<int> res;
    for (const auto &vec : vec2) {
        if (cnt[vec] > 0) {
            --cnt[vec];
            res.push_back(vec);
        }
    }
    return res;
}

/**
 * 选择公共元素 已排好序
 * */
vector<int> select_sort_common(const vector<int> &vec1, const vector<int> &vec2) {
    vector<int> res;
    if (vec1.empty() || vec2.empty() ) {
        return res;
    }
    auto itr1 = vec1.begin();
    auto itr2 = vec2.begin();
    while (itr1 != vec1.end() && itr2 != vec2.end()) {
        if (*itr1 > *itr2) {
            ++itr2;
            continue;
        } else if (*itr1 < *itr2) {
            ++itr1;
            continue;
        } else {
            res.push_back(*itr1);
            ++itr1;
            ++itr2;
        }
    }
    return res;
}

int main() {
    vector<int> num1 {1, 2, 2, 3, 5};
    vector<int> num2 {2, 2, 3, 4};
    for (const auto &res : select_common(num1, num2)) {
        cout << res << endl;
    }

    cout << "-----------------------------" << endl;
    for (const auto &res : select_sort_common(num1, num2)) {
        cout << res << endl;
    }
}
