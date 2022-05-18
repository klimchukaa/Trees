#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>

using namespace std;

int it1 = -33;

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
    void print(int i);
    void printpr();
};

int heap::sift_up(int i) {
    while (i > 0 && h[i] > h[(i - 1) / 2]) {
        swap(h[i], h[(i - 1) / 2]);
        printpr();
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
        printpr();
        i = nxt;
    }
    return i;
}

void heap::add(int x) {
    h.push_back(x);
    n++;
    printpr();
    sift_up(n - 1);
}

int heap::get_max() {
    return h[0];
}

pair <int, int> heap::extract_max() {
    int res = h[0];
    swap(h[0], h[n - 1]);
    n--; h.pop_back();
    printpr();
    return {sift_down(0) + 1, res};
}

void heap::print(int i) {
    if (i != 0) cout << ", ";
    cout << h[i];
    if (2 * i + 1 < n) {
        print(2 * i + 1);
    } else {
        cout << ", nil";
    }
    if (2 * i + 2 < n) {
        print(2 * i + 2);
    } else {
        cout << ", nil";
    }
}

void heap::printpr() {
    if (it1 <= 0) {
        it1++;
        return;
    }
    cout << "\\begin{center}\n\\begin{asy}\nimport binarytree;\npicture pic;\n";
    cout << "binarytree h = binarytree(";
    print(0);
    cout << ");\n";
    cout << "draw(pic, h, condensed=true);\n";
    cout << "add(pic.fit(), (0, 0));\n\\end{asy}\n\\end{center}\n";
    it1++;
}


int main() {
    heap a;
    vector <int> arr(20);
    iota(arr.begin(), arr.end(), 1);
    for (int i = 0; i < 20; ++i) {
        swap(arr[i], arr[rand() % (i + 1)]);
    }
    for (int i = 0; i < 20; ++i) {
        a.add(arr[i]);
    }
    for (int i = 0; i < 3; ++i) {
        a.extract_max();
    }
    return 0;
}
