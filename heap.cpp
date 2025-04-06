#include <iostream>
#include <climits> 
using namespace std;

class Heap {
public:
    int q[1000];
    Heap() {
        q[0] = 0;  
    }
    void add(int n) {
        if (q[0] < 999) {  
            q[0] = q[0] + 1;  
            q[q[0]] = n;  

            int i = q[0];  
            while (i > 1 && q[i / 2] < q[i]) {  
                swap(q[i / 2], q[i]); 
                i = i / 2; 
            }
        }
    }
    int Remove() {
        if (q[0] > 0) { 
            int s = q[1]; 
            q[1] = q[q[0]];  
            q[0] = q[0] - 1; 
            int p = 1; 
            while (p <= q[0]) {
                int l = p * 2;  
                int r = (p * 2) + 1; 
                int largest = p;

                if (l <= q[0] && q[l] > q[largest]) {
                    largest = l;
                }
                if (r <= q[0] && q[r] > q[largest]) {
                    largest = r;
                }
                if (largest != p) {
                    swap(q[p], q[largest]);
                    p = largest;
                } else {
                    break;  
                }
            }
            return s;  
        } else {
            return INT_MIN;  
        }
    }
    void showall() {
        for (int i = 1; i <= q[0]; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    int value;
    char ch;
    while (cin >> ch) {
        if (ch == 'a') { 
            cin >> value;
            h.add(value);
        } else if (ch == 'd') { 
            int deletedValue = h.Remove();
            if (deletedValue != INT_MIN) {
                cout << deletedValue << endl;
            } else {
                cout << "Heap is empty." << endl;
            }
        } else if (ch == 'p') {  
            h.showall();
        } else if (ch == 'e') { 
            break;
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


