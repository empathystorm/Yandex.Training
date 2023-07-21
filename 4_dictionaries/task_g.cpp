#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void deposit(map<string, int>& clients, string& name, int sum) {
    if (!clients.count(name))
        clients.insert(make_pair(name, 0));
    clients[name] += sum;
}

void withdraw(map<string, int>& clients, string& name, int sum) {
    deposit(clients, name, -sum);
}

void transfer(map<string, int>& clients, string& name1, string& name2, int sum) {
    withdraw(clients, name1, sum);
    deposit(clients, name2, sum);
}

void income(map<string, int>& clients, int p) {
    for (auto& client : clients) {
        if (client.second > 0)
            client.second += client.second * p / 100;
    }
}

void task_g() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    map<string, int> clients;

    string operation;
    while (input >> operation) {
        if (operation == "DEPOSIT") {
            string name; int sum;
            input >> name >> sum;
            deposit(clients, name, sum);
        } else if (operation == "WITHDRAW") {
            string name; int sum;
            input >> name >> sum;
            withdraw(clients, name, sum);
        } else if (operation == "TRANSFER") {
            string name1, name2; int sum;
            input >> name1 >> name2 >> sum;
            transfer(clients, name1, name2, sum);
        } else if (operation == "INCOME") {
            int p;
            input >> p;
            income(clients, p);
        } else { // BALANCE
            string name;
            input >> name;
            if (!clients.count(name)) output << "ERROR\n";
            else output << clients[name] << '\n';
        }
    }
}