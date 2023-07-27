//Счёт в гипершашках
#include "func.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long count_possible_scores(map<long, int>& cardCount, vector<long>& cardKeys, long k) {
    long count = 0, duplicates = 0; int r = 0;
    for (int l = 0; l < cardKeys.size(); l++) {
        while (r < cardKeys.size() && cardKeys[l] * k >= cardKeys[r]) {
            if (cardCount[cardKeys[r]] >= 2) duplicates++;
            r++;
        }
        long rangeLen = r - l;
        if (cardCount[cardKeys[l]] >= 2)
            count += (rangeLen - 1) * 3;
        if (cardCount[cardKeys[l]] >= 3)
            count += 1;
        count += (rangeLen - 1) * (rangeLen - 2) * 3;
        if (cardCount[cardKeys[l]] >= 2)
            duplicates--;
        count += duplicates * 3;
    }
    return count;
}

void task_g(istream& input, ostream& output) {
    int n; long k;
    input >> n >> k;
    map<long, int> cardCount;
    vector<long> cardKeys;
    for (int i = 0; i < n; i++) {
        long card;
        input >> card;
        if (!cardCount.count(card)) {
            cardCount.insert(make_pair(card, 0));
            cardKeys.push_back(card);
        }
        cardCount[card]++;
    }
    sort(cardKeys.begin(), cardKeys.end());

    output << count_possible_scores(cardCount, cardKeys, k);
}