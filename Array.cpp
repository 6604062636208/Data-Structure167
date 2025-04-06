//#include <iostream>
//using namespace std;
//
//int main(){
//	string cars[5] = {"Volvo", "BMW", "Toyota", "Ford", "Tesla"};
//	for(int i=0; i < 5; i++){
//		cout << i << " = " << cars[i] << endl;
//	}
//	int mynumber[5] = {10,20,30,40,50};
//	for(int i=0; i < 5; i++){
//		cout << mynumber[i] << endl;
//	}
////	int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
////	float avg, sum = 0;
////	int length = sizeof(ages) / sizeof(ages[0]);
////	for (int i=0 ; i < length; i++) {
////	  sum = sum + ages[i];
////	}
////	avg = sum / length;
////	cout << "The average age is: " << avg << "\n";
//	int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};
//	int length1 = sizeof(ages) / sizeof(ages[0]);
//	int MaxAge = ages[0];
//	for (int i = 0; i < length1; i++) {
//	  if (MaxAge < ages[i]) {
//	    MaxAge = ages[i];
//	  }
//	}
//	cout << "The lowest age is: " << MaxAge << "\n";
//	return 0;
//} 

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(){
//	int arr = 5;
//	int arr1[arr];
//	for(int i=1; i <= 5; i++){
//		cout << "Enter Number To Array" << "(" << i << ")" << " : ";
//		cin >> arr1[i];
//	}
//	cout << "Data In Array" << endl;
//	for(int i=1; i <= 5; i++){
//		if(arr1[i] % 2 == 0){
//			cout << "E";
//		} else {
//			cout << "O";
//		}
//	cout << ",";
//	}
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(){
//	int arr[5];
//	for(int i=1; i <= 5; i++){
//		cout << "Enter Number To Array" << "(" << i << ")" << " : ";
//		cin >> arr[i];
//	}
//	cout << "Data In Array" << endl;
//	for(int i=1; i <= 5; i++){
//		cout << arr[i] << ",";
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(){
//	int arr = 5;
//	int arr1[arr];
//	int arr2[arr];
//	int arr3[arr];
//	char arr4[arr];
//	cout << "Input Data Array : 1" << endl;
//	for(int i=1; i <= 5; i++){
//		cout << "Enter Number To Array" << "(" << i << ")" << " : ";
//		cin >> arr1[i];
//	}
//	cout << endl;
//	cout << "Input Data Array : 2" << endl;
//	for(int i=1; i <= 5; i++){
//		cout << "Enter Number To Array" << "(" << i << ")" << " : ";
//		cin >> arr2[i];
//	}
//	cout << endl;
//	cout << "Report" << endl;
//	for(int i=1; i <= arr; i++){
//		arr3[i] = arr1[i] + arr2[i];
//		cout << arr1[i] << " + " << arr2[i] << " = " << arr3[i];
//		if(arr3[i] % 2 == 0){
//			cout << "(E)";
//		} else {
//			cout << "(O)";
//		}	
//		cout << endl;
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    float arr1[10];
//    float arr2[10] = {0};
//    for (int i = 0; i < 10; i++) {
//        cout << "Enter Celcius(" << i + 1 << ") : ";
//        cin >> arr1[i];
//    }
//    cout << endl;
//    for (int i = 0; i < 10; i++) {
//        arr2[i] = (arr1[i] * 9.0f / 5) + 32;
//        cout << arr1[i] << "C" << " -> " << arr2[i] << "F" << endl;
//    }
//
//    return 0;
//}

#include <iostream>
using namespace std;

int main() {
    int arr1[10];
    cout << "Calculate Grade Program" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Enter Score Student " << i << " : ";
        cin >> arr1[i];
    }
    cout << endl;
    cout << "Show Student Grade" << endl;
    for (int i = 1; i <= 5; i++) {
    	cout << "Student " << i << endl;
    	if(arr1[i] >= 90 && arr1[i] <= 100){
    		cout << "Score " << arr1[i] << " Grade A" << endl;
		}
		else if(arr1[i] >= 80 && arr1[i] <= 89){
			cout << "Score " << arr1[i] << " Grade B" << endl;
		}
		else if(arr1[i] >= 70 && arr1[i] <= 79){
			cout << "Score " << arr1[i] << " Grade C" << endl;
		}
		else if(arr1[i] >= 50 && arr1[i] <= 69){
			cout << "Score " << arr1[i] << " Grade D" << endl;
		} 
		else {
			cout << "Score " << arr1[i] << " Grade F" << endl;
		} 
    }

    return 0;
}
