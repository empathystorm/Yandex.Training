#include <iostream>
#include <fstream>
#include <map>
#define ID (i->first).first
#define TIME (i->first).second
#define STATUS i->second

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    multimap<pair<int, int>, char> events;

    for (int i = 0; i < n; i++) {
        int d, h, m, id; char status;
        fin >> d >> h >> m >> id >> status;
        if (status != 'B')
            events.insert({{id, d*24*60 + h*60 + m}, status});
    }

    map<int, int> res;
    for (auto i = events.begin(); i != events.end(); ++i) {
        if (!res.count(ID))
            res.insert({ID, 0});
        if (STATUS == 'A')
            res[ID] -= TIME;
        if (STATUS == 'S' || STATUS == 'C')
            res[ID] += TIME;
    }

    for (auto i = res.begin(); i != res.end(); ++i) {
        fout << i->second << ' ';
    }
}