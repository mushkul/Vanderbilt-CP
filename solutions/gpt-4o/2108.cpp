#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int ALPHABET_SIZE = 26;

struct SuffixArray {
    int n;
    vector<int> suffix_array;
    vector<int> lcp;
    
    SuffixArray(const string &s) {
        n = s.size();
        suffix_array.resize(n);
        vector<int> classes(n), c(n), cnt(max(ALPHABET_SIZE, n), 0), pn(n);
        for (int i = 0; i < n; ++i) {
            c[i] = s[i] - 'a';
            ++cnt[c[i]];
        }
        for (int i = 1; i < ALPHABET_SIZE; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            suffix_array[--cnt[c[i]]] = i;
        }
        classes[suffix_array[0]] = 0;
        int classes_num = 1;
        for (int i = 1; i < n; ++i) {
            if (c[suffix_array[i]] != c[suffix_array[i - 1]]) ++classes_num;
            classes[suffix_array[i]] = classes_num - 1;
        }
        
        pn = c;
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; ++i) {
                pn[i] = suffix_array[i] - (1 << h);
                if (pn[i] < 0) pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes_num, 0);
            for (int i = 0; i < n; ++i) {
                ++cnt[classes[pn[i]]];
            }
            for (int i = 1; i < classes_num; ++i) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; --i) {
                suffix_array[--cnt[classes[pn[i]]]] = pn[i];
            }
            c[suffix_array[0]] = 0;
            classes_num = 1;
            for (int i = 1; i < n; ++i) {
                int mid1 = (suffix_array[i] + (1 << h)) % n;
                int mid2 = (suffix_array[i - 1] + (1 << h)) % n;
                if (classes[suffix_array[i]] != classes[suffix_array[i - 1]]
                    || classes[mid1] != classes[mid2]) ++classes_num;
                c[suffix_array[i]] = classes_num - 1;
            }
            classes = c;
        }
        
        lcp.resize(n);
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (classes[i] > 0) {
                int j = suffix_array[classes[i] - 1];
                while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
                lcp[classes[i]] = h;
                if (h > 0) --h;
            }
        }
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    SuffixArray sa(s);
    int n = s.size();
    
    set<string> substrings;
    for (int i = 0; i < n; ++i) {
        for (int len = sa.lcp[i] + 1; len <= n - sa.suffix_array[i]; ++len) {
            substrings.insert(s.substr(sa.suffix_array[i], len));
            if (substrings.size() == k) {
                cout << *substrings.rbegin() << endl;
                return 0;
            }
        }
    }

    return 0;
}