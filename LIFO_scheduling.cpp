#include <iostream>
#include <stack>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int serviceTime;
};

int main() {
    int n;
    cin >> n;
    
    stack<Process> s;
    Process processes[10]; 
    Process p;

    for (int i = 0; i < n; ++i) {
        cin >> processes[i].pid >> processes[i].arrivalTime >> processes[i].serviceTime;
    }
    //bubble sort the arrivalTime
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime){
            		int temp = processes[j].arrivalTime;
            		processes[j].arrivalTime = processes[j+1].arrivalTime;
            		processes[j+1].arrivalTime = temp;
            }
        }
    }
    int time = 0;
    int currProcess = 0;
    while(currProcess < n || !s.empty()) {  
        while(currProcess < n && processes[currProcess].arrivalTime <= time) {
            s.push(processes[currProcess]);
            currProcess++;
        }
        if(!s.empty()) {
            p = s.top();
            s.pop();
            for(int i = p.serviceTime; i > 0; i--) {
                cout << p.pid << " : " << i;
                cout << endl;
                time++;
            }
        }else {
            time++;
        }      
    }
    return 0;
}
/*

2   
3010
0
4
3005
2
3

3010 : 4
3010 : 3
3010 : 2
3010 : 1
3005 : 3
3005 : 2
3005 : 1

3
1010
0
3
2002
1
4
3030
3
5

1010 : 3
1010 : 2
1010 : 1
3030 : 5
3030 : 4
3030 : 3
3030 : 2
3030 : 1
2002 : 4
2002 : 3
2002 : 2
2002 : 1

4
1010
0
2
2002
2
3
3030
3
2
4040
4
4

1010 : 2
1010 : 1
2002 : 3
2002 : 2
2002 : 1
4040 : 4
4040 : 3
4040 : 2
4040 : 1
3030 : 2
3030 : 1

5
1010
0
2
2002
2
3
3030
3
3
4040
4
4
5050
5
5

1010 : 2
1010 : 1
2002 : 3
2002 : 2
2002 : 1
5050 : 5
5050 : 4
5050 : 3
5050 : 2
5050 : 1
4040 : 4
4040 : 3
4040 : 2
4040 : 1
3030 : 3
3030 : 2
3030 : 1

4
1010
2
3
2020
0
4
3030
4
3
4040
3
2

2020 : 4
2020 : 3
2020 : 2
2020 : 1
3030 : 3
3030 : 2
3030 : 1
4040 : 2
4040 : 1
1010 : 3
1010 : 2
1010 : 1

*/