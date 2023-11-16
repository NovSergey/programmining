#include <fstream>
#include "Functional.h"
#include <stdlib.h>
#include <Windows.h>

void getProgressBar(int count_files) {
    int one_part = 0;
    int counter = 0;
    string str = "";
    double procent = 0;
    while (counter <= count_files) {
        if (one_part == count_files / 10) {            
            str += 219;
            one_part = 0;
        }
        if (counter == count_files) system("cls");
        procent = double(counter) / double(count_files) * double(100);
        cout << "\r[" << str << "] " << procent << "% " << counter << '/' << count_files << "";
        counter++;
        one_part++;
    }
}


int main()
{
    Graph graph = Graph();
    graph.init_new_map("pfdsfkskf s fksdl; fk;lsdfdskf;lsdk;l adfaf pfdsfkskf fdsfds pfdsfkskf");
    cout << graph.get_str("pfdsfkskf");
    //getProgressBar(10240);

}

