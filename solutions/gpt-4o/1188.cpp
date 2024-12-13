#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> compute_segments(const string& s) {
    int n = s.length();
    vector<int> segments;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        segments.push_back(j - i);
        i = j;
    }
    return segments;
}

int update_segments(vector<pair<int, int>>& segments, int idx, int len, int dir) {
    segments[idx].first += dir * len;
    if (segments[idx].first == 0) {
        swap(segments[idx], segments.back());
        segments.pop_back();
        return 1;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> changes(m);
    for (int i = 0; i < m; ++i) cin >> changes[i];

    int n = s.length();
    vector<int> lens = compute_segments(s);
    vector<pair<int, int>> segments; // (length, start index)
    for (int i = 0, sum = 0; i < lens.size(); ++i) {
        segments.push_back({ lens[i], sum });
        sum += lens[i];
    }

    for (int c : changes) {
        c--;
        int si = 0;
        for (int i = 0; i < segments.size(); ++i) {
            if (segments[i].second + segments[i].first > c) {
                si = i;
                break;
            }
        }

        if ((s[c] == '0' && (seg_start == 0 || s[seg_start - 1] == '1') && (seg_start + seg_len == n || s[seg_start + seg_len] == '1')) ||
            (s[c] == '1' && (seg_start == 0 || s[seg_start - 1] == '0') && (seg_start + seg_len == n || s[seg_start + seg_len] == '0'))) {

            update_segments(segments, si, 1, (s[c] == '0' ? -1 : 1));
            s[c] = (s[c] == '0' ? '1' : '0');

            if (si > 0 && c == segments[si - 1].second + segments[si - 1].first) {
                if (s[c] == s[c - 1]) {
                    update_segments(segments, si - 1, segments[si].first, 1);
                    segments.erase(segments.begin() + si);
                }
            }

            if (si < segments.size() && c == segments[si].second) {
                if (s[c] == s[c + 1]) {
                    update_segments(segments, si, segments[si + 1].first, 1);
                    segments.erase(segments.begin() + si + 1);
                }
            }

        }
        else {
            update_segments(segments, si, 1, -1);
            update_segments(segments, si, 1, -1);
            segments.insert(segments.begin() + si, { 1, c });
            s[c] = (s[c] == '0' ? '1' : '0');
        }

        int max_len = 0;
        for (auto& seg : segments) {
            max_len = max(max_len, seg.first);
        }
        cout << max_len << " ";
    }

    return 0;
}