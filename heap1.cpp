#include <iostream>
using namespace std;

class heap {
public:
    int q[1000];
    heap() {
        q[0] = 0; // Initialize heap size
    }
    void insert(int n) {
        if (q[0] < 999) {
            q[0] = q[0] + 1;
            q[q[0]] = n;
            int i = q[0];
            while (i > 1 && q[i / 2] < q[i]) {
                // Swap with parent if the current value is greater
                int t = q[i / 2];
                q[i / 2] = q[i];
                q[i] = t;
                i = i / 2;
            }
        }
    }
    int Delete() {
        if (q[0] > 0) {
            int s = q[1];
            q[1] = q[q[0]];
            q[0] = q[0] - 1;
            int p = 1;
            while (p <= q[0]) {
                int l = p * 2;
                int r = (p * 2) + 1;
                if (l <= q[0] && q[l] > q[p] && (r > q[0] || q[l] >= q[r])) {
                    // Swap with left child
                    int t = q[l];
                    q[l] = q[p];
                    q[p] = t;
                    p = l;
                }
                else if (r <= q[0] && q[r] > q[p] && (l > q[0] || q[r] > q[l])) {
                    // Swap with right child
                    int t = q[r];
                    q[r] = q[p];
                    q[p] = t;
                    p = r;
                }
                else {
                    break;
                }
            }
            return s;
        }
        else {
            return -1; // Use -1 to indicate empty heap
        }
    }
    void print() {
        for (int i = 1; i <= q[0]; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    heap h;
    char ch = ' '; // Initialize ch
    int value;
    while (ch != 'e') {
        cin >> ch;
        if (ch == 'a') {
            cin >> value;
            h.insert(value);
        } else if (ch == 'd') {
            int deletedValue = h.Delete();
            if (deletedValue != -1) {
                cout << deletedValue << endl;
            } else {
                cout << "Heap is empty" << endl;
            }
        } else if (ch == 'p') {
            h.print();
        } else if (ch != 'e') {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}

// a 12 
// a 13 
// a 20  
// p 20 12 13 
// d 20 
// p 13 12 
// e

// a   18
// a   19
// a   2
// a   10
// p   19 18 2 10
// a   258
// a   95
// p   258 19 95 10 18 2
// a   102
// a   36
// a   98
// p   258 98 102 36 18 2 95 10 19
// p   258 98 102 36 18 2 95 10 19
// a   71
// p   258 98 102 36 71 2 95 10 19 18
// a   11
// p   258 98 102 36 71 2 95 10 19 18 11
// a   71
// p   258 98 102 36 71 71 95 10 19 18 11 2
// d   258
// d   102
// a   150
// p   150 98 95 36 71 71 2 10 19 11 18
// d   150
// d   98
// d   95
// d   71
// p   71 36 11 19 18 10 2
// e