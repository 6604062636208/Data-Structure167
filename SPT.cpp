#include <iostream>
#include <queue>

using namespace std;

struct Process {
    char Pid;
    int arrivalTime;
    int serviceTime;
    int iter;
};

int main() { // Shortest Remaining Time;

    int N;
    cin >> N;

    queue<Process> q;
    Process processes[N];

    for (int i = 0; i < N; ++i) {
        cin >> processes[i].Pid >> processes[i].arrivalTime >> processes[i].serviceTime;
    }

    //sort
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1; j++) {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime) {
                swap(processes[j], processes[j+1]);
            }
            
        }
    }

    Process p,temp;
    int time = 0;
    int currProcess = 0;
    while (currProcess < N || !q.empty()) {
        while(currProcess < N && processes[currProcess].arrivalTime <= time) {
            q.push(processes[currProcess++]);
        }

        if(!q.empty()) {
            p = q.front();
            q.pop();

            for(int i = 0; i < q.size(); i++) {
                temp = q.front();
                q.pop();

                if(p.serviceTime > temp.serviceTime || (temp.serviceTime == p.serviceTime && temp.arrivalTime < p.arrivalTime)) {
                    q.push(p);
                    p = temp;
                }else {
                    q.push(temp);
                }
            }

            for(int i = p.serviceTime; i > 0; i--) {
                if(processes[currProcess].arrivalTime <= time && processes[currProcess].serviceTime < p.serviceTime) {
                    q.push(p);
                    break;
                }else {
                    cout << p.Pid << " : " << i << endl;
                    p.serviceTime--;
                    time++;
                }
            }
        }else {
            time++;
        }

    }
    

    return 0;
}