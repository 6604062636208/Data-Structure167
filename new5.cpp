#include <iostream>
#include <stack>
using namespace std;

struct Process {
	int pid;
	int arrivalTime;
	int serviceTime;
};

int main(){
	int n;
	cin >> n;
	stack<Process>s;
	Process processes[10];
	Process p;
	
	for(int i=0; i<n; ++i){
		cin >> processes[i].pid >> processes[i].arrivalTime >> processes[i].serviceTime;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(processes[j].arrivalTime > processes[j+1].arrivalTime){
				int temp = processes[j].arrivalTime;
				processes[j].arrivalTime = processes[j+1].arrivalTime;
				processes[j+1].arrivalTime = temp;
			}
		}
	}
	int time = 0;
	int currentprocess = 0;
	while(currentprocess < n || !s.empty()){
		while(currentprocess < n && processes[currentprocess].arrivalTime <= time){
			s.push(processes[currentprocess]);
			currentprocess++;
		}
		if(!s.empty()){
			p = s.top();
			s.pop();
			for(int i = p.serviceTime; i>0; i--){
				cout << p.pid << " : " << i;
				cout << endl;
				time++;
			}
		} else {
			time++;
		}
	}
	return 0;
}
//#include <iostream>
//#include <stack>
//using namespace std;
//
//struct Process {
//	int pid;
//	int arrivaltime;
//	int servicetime;
//};
//
//int main(){
//	int n;
//	cin >> n;
//	stack<Process>s;
//	Process processes[10];
//	Process p;
//	
//	for(int i=0;i<n;++i){
//		cin >> processes[i].pid >> processes[i].arrivaltime >> processes[i].servicetime;
//	}
//	for(int i=0;i<n-1;i++){
//		for(int j=0;j<n-1;j++){
//			if(processes[j].arrivaltime > processes[j+1].arrivaltime){
//				int temp = processes[j].arrivaltime;
//				processes[j].arrivaltime = processes[j+1].arrivaltime;
//				processes[j+1].arrivaltime = temp;
//			}
//		}
//	}
//	int currentprocess = 0;
//	int time = 0;
//	while(currentprocess < n || !s.empty()){
//		while(currentprocess < n && processes[currentprocess].arrivaltime <=time){
//			s.push(processes[currentprocess]);
//			currentprocess++;
//		}
//		if(!s.empty()){
//			p = s.top();
//			s.pop();
//			for(int i=p.servicetime; i>0; i--){
//				cout << p.pid << " : " << i;
//				cout << endl;
//				time++;
//			}
//		} else {
//			time++;
//		}
//	}
//	return 0;
//}