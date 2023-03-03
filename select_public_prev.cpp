#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 选择公共前缀
 * */
string get_common_prex(const vector<string> &datas) {
    if (datas.empty()) {
        return "";
    }
    string result = "";
    auto iter = datas.begin();
    string tmp = *iter;
    while (++iter != datas.end()) {
        result.clear();
        int len = std::min((*iter).size(), tmp.size());
        for (auto idx = 0; idx < len; ++idx) {
            if (tmp.at(idx) == (*iter).at(idx)) {
                result += tmp.at(idx);
            } else {
                break;
            }
        }
        if (result.empty()) {
            break;
        }
        tmp = result;
    }
    return result;
}

int main() {
    vector<string> datas;
    datas.push_back("flower");
    datas.push_back("flow");
    datas.push_back("flight");
    cout << get_common_prex(datas) << endl;
    return 0;
}
