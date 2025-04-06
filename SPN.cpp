#include <iostream>
#include <queue>

using namespace std;

struct Process {
    char Pid;
    int arrivalTime;
    int serviceTime;
    int iter;
};

int main() { // Shortest Process Next;

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

    Process shortest,temp;
    int time = 0;
    int currProcess = 0;
    while (currProcess < N || !q.empty()) {
        while(currProcess < N && processes[currProcess].arrivalTime <= time) {
            q.push(processes[currProcess++]);
        }

        if(!q.empty()) {
            shortest = q.front();
            q.pop();

            for(int i = 0; i < q.size(); i++) {
                temp = q.front();
                q.pop();

                if(shortest.serviceTime > temp.serviceTime) {
                    q.push(shortest);
                    shortest = temp;
                }else {
                    q.push(temp);
                }
            }

            for(int i = shortest.serviceTime; i > 0; i--) {
                cout << shortest.Pid << " : " << i << endl;
                time++;
            }
        }else {
            time++;
        }

    }
    

    return 0;
}