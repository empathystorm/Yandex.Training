//Подстрока
#include "func.h"
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<int> find_max_substring(string& s, int n, int k) {
    int maxSize = 0; vector<int> ans = {n, 1};
    map<char, int> countSymb;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && countSymb[s[r]] < k) {
            if (!countSymb.count(s[r]))
                countSymb.insert(make_pair(s[r], 0));
            countSymb[s[r]]++;
            r++;
        }
        int len = r - l;
        if (len > maxSize) {
            maxSize = len;
            ans = {len, l + 1};
        }
        countSymb[s[l]]--;
        if (countSymb[s[l]] == 0)
            countSymb.erase(s[l]);
    }
    return ans;
}

void task_h(istream& input, ostream& output) {
    int n, k; string s;
    input >> n >> k >> s;

    vector<int> ans = find_max_substring(s, n, k);
    output << ans[0] << ' ' << ans[1];
}