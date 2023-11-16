#pragma once
#include <iostream>
#include "Word.h"

class Graph {
public:
    Graph() {
        srand(time(NULL));
    }
    void init_new_map(string str) {
        words = {};
        add_to_map(str);
    }
    void add_to_map(string str) {
        string s = "";
        for (auto i : str) {
            if (i != ' ') s += i;
            else {
                if (words.count(s) == 0)
                    words[s] = Word(s);
                s = "";
            }
        }
        if (words.count(s) == 0)
            words[s] = Word(s);
        s = "";
        string last_str = "";
        for (auto i : str) {
            if (i != ' ') s += i;
            else {
                if (last_str.length() > 0)
                    words[last_str].add_to_linker(s, words[s]);
                last_str = s;
                s = "";
            }
        }
        words[last_str].add_to_linker(s, words[s]);
    }
    string get_str(string str) {
        Word result = words[str].get_popular_string();
        string result_str = str + " ";
        while (result.value.length() != 0) {
            result_str += result.value + ' ';
            Word result_ = words[result.value].get_popular_string();
            while (result_.value == str) {
                result_ = words[result.value].get_popular_string();
                if (result.value.length() == 0)
                    break;
            }
            result = result_;
        }
        return result_str;
    }

    map<string, Word> words = {};
};






