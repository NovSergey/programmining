#pragma once
#include "Map.h"
#include "Player.h"
#include "Computer.h"
#include <thread>
#include <chrono>
struct Game {
	Game() {
        generate_ships_player();
        cout << "Загрузка.." << endl;
        generate_ships_computer();
        update_state_game();
        while (!is_end_game()) {
            battle_player();
            battle_comp();
        }
        if (score_player > score_computer)
            cout << "Победил игрок!" << endl;
        else if(score_player < score_computer)
            cout << "Победил компьютер!" << endl; 
	}
public:
    void update_state_game() {
        system("cls");
        cout << "Player: " << score_player << " | " << "Computer: " << score_computer << endl << endl;
        map_player.show();
        map_computer.show(); 
    }
    void battle_comp() {
        bool win = 1;
        while (win) {
            bool is_equal = 0;
            pair<char, int> target_point;
            do {
                target_point = { rand() % 10 + 65,rand() % 10 + 1 };

            } while (count(computer.buffer_points.begin(), computer.buffer_points.end(), target_point)>0);
            computer.buffer_points.push_back(target_point);
            for (auto &s : player.ships) {
                if (s.position.count(target_point)>0) {
                    s.position[target_point] = '0';
                    map_player.field[target_point] = '0';
                    if (check_destroyed_ship(s.position, '0'))
                        score_computer += 1;
                    is_equal = 1;
                    break;
                }
            }
            if (!is_equal) {
                map_player.field[target_point] = 'x';
                win = 0;
            }
        }
        update_state_game();
        cout << "Ход компьютера завершён! " << endl;
    }
    void battle_player() {
        bool win = 1;
        while (win) {
            bool is_equal = 0;
            string coord;
            cout << "Введите точку выстрела: ";
            cin >> coord;
            pair<char, int> target_point = { coord[0], coord.length() < 3 ? (int)coord[1] - 48 : 10 };
            for (auto &s : computer.ships) {
                if (s.position.count(target_point)) {
                    s.position[target_point] = '1';
                    map_computer.field[target_point] = '1';
                    is_equal = 1;
                    update_state_game();
                    if (check_destroyed_ship(s.position, '1')) {
                        cout << "Корабль противника полностью уничтожен!" << endl;
                        score_player += 1;
                    }
                    else {
                        cout << "Попадание!" << endl;
                    }
                    break;
                }
            }
            if (!is_equal) {
                map_computer.field[target_point] = 'x';
                cout << "Промах!" << endl;     
                win = 0;
            }
            this_thread::sleep_for(chrono::seconds(2));
            update_state_game();
        }
    }
private:
    int score_player=0, score_computer = 0;
    Map map_computer, map_player;
    Computer computer;
    Player player;    
    bool is_end_game() {
        return score_player == size(computer.ships) or score_computer == size(player.ships);
    }

    bool check_destroyed_ship(map<pair<char, int>, char> points_ship, char view) {
        for (auto p : points_ship) {
            if (p.second != view) return false;
        }
        return true;
    }

    void generate_ships_computer() {
        map_computer = Map(true);
        computer = Computer('0');
        int size = 4;
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < i; j++) {
                computer.createShip(&map_computer, size);
            }
            size--;
        }
    }
	void generate_ships_player() {
        map_player = Map(true);
        char v;
        cout << "Как будут отображаться ваши корабли: ";
        cin >> v;
        player = Player(v);
        int count_ship;
        cout << "Сколько кораблей вы хотите поставить?" << endl;
        cin >> count_ship;
        for (int i = 0; i < count_ship; i++) {

            int size = 0;
            do {
                cout << "Введите размер корабля: ";
                cin >> size;
                if (size < 11 and size > 0) {
                    break;
                }
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                cout << "Размер не правильный" << endl;
            } while (true);
            player.createShip(&map_player, size);
        }
	}
};