#include <iostream>
#include <queue>
using namespace std;

struct Process {
    char Pid;
    int arrivalTime;
    int serviceTime;
};

int main() {
    int RRq = 3;
    int N;
    cin >> N;
    queue<Process> q;
    Process proc[10];

    for(int i = 0; i < N; i++) {
        cin >> proc[i].Pid >> proc[i].arrivalTime >> proc[i].serviceTime;
    }
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1; j++) {
            if(proc[j].arrivalTime > proc[j+1].arrivalTime) {          	
                swap(proc[j], proc[j+1]);
            }
        }
    }
    Process p;
    int time = 0;
    int currProcess = 0;
    while(currProcess < N || !q.empty()) {
        while(currProcess < N && proc[currProcess].arrivalTime <= time) {
            q.push(proc[currProcess++]);
        }
        if(!q.empty()) {
            p = q.front();
            q.pop();
            if(p.serviceTime  > 0) {
                for(int i = p.serviceTime; i > p.serviceTime - RRq; i--) {
                    if(i > 0) {
                        cout << p.Pid << " : " << i << endl;
                        time++;  
                    }else {
                        break;
                    }
                }
            }
            p.serviceTime -= RRq;
            if(p.serviceTime > 0) {
                while(currProcess < N && proc[currProcess].arrivalTime <= time) {
                    q.push(proc[currProcess++]);
                }
                q.push(p);
            }else {
                continue;
            }
        }else {
            time++;
        }
	}
    return 0;
}