#include <iostream>
using namespace std;

int main(){
	float score = 0, Midterm = 0, Final = 0;
	cin >> Midterm >> Final;
	score = Midterm + Final;
	if(score >= 80){
		cout << "Score : " << score << " Grade A" << endl;
	} else if(score >= 75){
		cout << "Score : " << score << " Grade B+" << endl;
	} else if(score >= 70){
		cout << "Score : " << score << " Grade B" << endl;
	} else if(score >= 65){
		cout << "Score : " << score << " Grade C+" << endl;
	} else if(score >= 60){
		cout << "Score : " << score << " Grade C" << endl;
	} else if(score >= 55){
		cout << "Score : " << score << " Grade D+" << endl;
	} else if(score >= 40 && score <= 54){
		cout << "Score : " << score << " Grade D" << endl;
	} else {
		cout << "Score : " << score << " Grade F" << endl;
	}
	return 0;
}

