#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class heap{
public:
    vector <int> h;
    int n = 0;
    int sift_up(int i);
    int sift_down(int i);
    void add(int x);
    int get_max();
    pair <int, int> extract_max();
    int operator[](int i) const { return h[i]; }
    friend ostream& operator<<(ostream&, const heap&);
};

int heap::sift_up(int i) {
    while (i > 0 && h[i] > h[(i - 1) / 2]) {
        swap(h[i], h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return i;
}

int heap::sift_down(int i) {
    while (2 * i + 1 < n) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int nxt = l;
        if (r < n && h[r] > h[l]) {
            nxt = r;
        }
        if (h[i] >= h[nxt]) {
            break;
        }
        swap(h[i], h[nxt]);
        i = nxt;
    }
    return i;
}

void heap::add(int x) {
    h.push_back(x);
    n++;
    sift_up(n - 1);
}

int heap::get_max() {
    return h[0];
}

pair <int, int> heap::extract_max() {
    int res = h[0];
    swap(h[0], h[n - 1]);
    n--; h.pop_back();
    return {sift_down(0) + 1, res};
}

ostream &operator<<(ostream &out, const heap &a) {
    for (int i = 0; i < a.n; ++i) {
        cout << a[i] << ' ';
    }
    return out;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
