#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class Word {
public:
    Word() {};
    Word(string value_) : value{ value_ } {}
    map<string, pair<Word, int>> linker{};
    string value;

    void add_to_linker(string key, Word value_) {
        linker[key].first = value_;
        linker[key].second++;
    }    
    Word get_popular_string() {
        int max = 0;
        vector<pair<Word, int>> most = {};
        for (auto p : linker) {
            if (p.second.second >= max)
                max = p.second.second;
        }
        for (auto p : linker) {
            if (p.second.second == max) {
                most.push_back({ p.second.first, p.second.second });
            }
        }
        return most.size() > 0 ? most[rand() % most.size()].first : Word();
    }
};