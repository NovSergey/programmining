#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

//class Point
//{
//public:
//    Point(int x=0, int y = 0, int z = 0, int width = 4) {
//        this->x = x;
//        this->y = y;
//        this->z = z;
//        this->width = width;
//    }
//    void move(int delta_x=0, int delta_y=0, int delta_z = 0) {
//        this->x += delta_x;
//        this->y += delta_y;
//        this->z += delta_z;
//    }
//    void print() {
//        cout << "X: " << x << " | Y: " << y << " | Z: " << z << " | Width: " << width << endl;
//    }
//    void set_x(int value) {
//        if (is_valid(value)) x = value;
//        else {
//            cout << "Valis is not valid. Value can exist in range -100<value<100" << endl;
//        }
//    }
//    int get_x() { return x; }
//    Point* add(Point other) {
//        x += other.x;
//        y += other.y;
//        return this;
//    }
//
//
//private:
//    int x, y, z;
//    int width;
//
//    bool is_valid(int value) {
//        return value > -100 and value < 100;
//    }
//};



//class Restaurant 
//{
//public:
//    Restaurant(int count_tables) {
//        for (int i = 0; i < count_tables; i++)
//            book_tables.push_back(0);
//    }
//    void add_item_to_menu() {
//        string value;
//        int cost;
//        cout << "Введите пункт меню: ";
//        getline(cin, value);
//        cout << "Введите цену: ";
//        cin >> cost;
//        menu_items.push_back({value, cost});
//    }
//    
//    void book_table() {
//        int value;
//        do {
//            cout << "Введите стол для резервации: ";
//            cin >> value;
//            if (book_tables[value-1] != 1) {
//                book_tables[value - 1] = 1;
//                break;
//            }
//            cout << "Столик уже зарезервирован!" << endl;
//        } while (true);
//    }
//
//    void customer_order() {
//        int value;
//        vector<string> order;
//        book_table();
//        cout << "Меню: " << endl;
//        show_menu();
//        do {
//            cout << "Введите номер пункта: ";
//            cin >> value;
//            if (value == 0) break;
//            order.push_back(menu_items[value - 1].first);
//        } while (true);
//        customer_orders.push_back(order);
//        cout << "Заказ успешно добавлен!" << endl;
//    }
//
//    void show_menu() {
//        for (int i = 1; i < menu_items.size() + 1; i++) {
//            cout << i << " " << menu_items[i - 1].first << menu_items[i - 1].second << endl;
//        }
//    }
//
//    void show_book_tables() {
//        for (int i = 1; i < book_tables.size() + 1; i++) {
//            cout << i << " " << book_tables[i - 1]  << endl;
//        }
//    }
//
//    void show_customer_orders() {
//        for (int i = 1; i < customer_orders.size() + 1; i++) {
//            cout << "Заказ: " << i << ':' << endl;
//            for (auto j : customer_orders[i - 1])
//                cout << j << endl;
//            cout << endl;
//        }
//    }
//
//
//private:
//    vector<pair<string, int>> menu_items;
//    vector<int> book_tables;
//    vector<vector<string>> customer_orders;
//};
//
//
//class Invetory {
//public:
//    map<int, Item> items;
//    
//    void add_item(int item_id, Item item) {
//        items[item_id]=item;
//    }
//    void update_item(int item_id, string criterion, int value) {
//        items[item_id].information[criterion] = to_string(value);
//    }
//    void update_item(int item_id, string criterion, string value) {
//        items[item_id].information[criterion] = value;
//    }
//    void check_item_detailes(int item_id) {
//        for (auto p : items[item_id].information) {
//            cout << p.first << ": " << p.second << endl;
//        }
//        cout << endl;
//    }
//};
//
//class Item {
//public:
//    Item(){}
//    Item(int item_id, string item_name, int stock_count, int price) {
//        information["item_id"] = to_string(item_id);
//        information["item_name"] = item_name;
//        information["stock_count"] = to_string(stock_count);
//        information["price"] = to_string(price);
//    }
//    map<string, string> information;
//};

class BankAccount {
public:
    BankAccount(string customer_name) {
        this->customer_name = customer_name;
        this->balance = 0;
        this->account_number = (char)(rand() % 23 + 65) + to_string(rand() % 9000 + 1000);

        time_t now = time(0);
        tm* ltm = localtime(&now);
        this->date_of_opening = to_string(ltm->tm_mday) + "/" + to_string((ltm->tm_mon + 1)) + "/" + to_string((ltm->tm_year + 1900));
    }
    void deposit(int value) {
        this->balance += value;
    }
    void withdraw(int value) {
        if (this->balance - value > -1){
            this->balance -= value;
        }
        else {
            cout << "Недостаточно средств!" << endl;
        }
    }
    void check_balance() {
        cout << this->balance << endl;
    }
    void print_account_details() {
        cout << "Number: " << account_number << " | date_of_opening: " << date_of_opening << " | customer_name: " << customer_name << " | balance: " << balance << endl;
    }
private:
    int balance;
    string account_number, date_of_opening,customer_name;
};


class Employee {
public:
    Employee(string emp_name, string emp_department, int salary_for_hour) {
        this->emp_id = (char)(rand()%23+65) + to_string(rand() % 9000 + 1000);
        this->emp_name = emp_name; 
        this->emp_department = emp_department;
        this->salary_for_hour = salary_for_hour;
    }
    void emp_assign_department(string value) {
        this->emp_department = value;
    }
    void print_employee_details() {
        int hours;
        cout << "How much hours employee working? ";
        cin >> hours;
        cout << "Id: " << emp_id << " | Name: " << emp_name << " | Salary: " << calculate_emp_salary(hours) << " | Department: " << emp_department << endl;
    }
private:
    string emp_id, emp_name, emp_department;
    int salary_for_hour;

    int calculate_emp_salary(int hours) {
        return hours > 50 ? salary_for_hour / 50 * (hours - 50) + 50 * salary_for_hour : salary_for_hour * hours;
    }
};

int func(int ar[], int size, int index=0, int min_sum=0, int min_index=0) {
    if (index > size - 10) {
        return min_index;
    }
    if (index == 0) {
        for (int i = index; i < index + 10; i++) {
            min_sum += ar[i];
        }
        return func(ar, size, index + 1, min_sum, min_index);
    }
    int sum=0;
    for (int i = index; i < index + 10; i++) {
        sum += ar[i];
    }
    if (sum < min_sum) {
        min_index = index;
        min_sum = sum;
    }
    cout << sum << ' ' << index << endl;
    return func(ar, size, index + 1, min_sum, min_index);

}


class Stack {
public:
    int top = -1;

    void push(int value) {
        data.push_back(value);
        top++;
    }
    int pop() {
        auto res = *(data.end() - 1);
        data.pop_back();
        top--;
        return res;
    }
    bool Empty() {
        return top == -1;
    }

    void print() {
        for (int i = data.size()-1; i > -1; i--) {
            cout << data[i] << endl;
        }
    }
private:
    vector<int> data;

};


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    //Employee emp("АДАМС", "БУХГАЛТЕРИЯ", 450);
    //emp.print_employee_details();
    //emp.emp_assign_department("ИССЛЕДОВАНИЯ");
    //emp.print_employee_details();
    //BankAccount ac("Sergey");
    //ac.deposit(1000);
    //ac.withdraw(100);
    //ac.check_balance();
    //ac.print_account_details();
    
    //int array[15];
    //for (int i = 0; i < size(array); i++) {
    //    array[i] = rand() % 10;
    //    cout << array[i] << " ";
    //}
    //cout << endl;
    //cout << func(array, 15);

    auto stack = Stack();
    stack.push(1);
    stack.push(5);
    stack.push(2);
    stack.print();
    stack.pop();
    stack.print();
}
