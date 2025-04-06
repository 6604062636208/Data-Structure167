#include <stdio.h>

int main() {
	double c0 = 0, c1 = 0, c2 = 0, fx = 0;
	double x0 = 0, fx0 = 9.81;
	double x1 = 20000, fx1 = 9.7487;
	double x2 = 40000, fx2 = 9.6879;
	double x3 = 60000, fx3 = 9.6879;
   	double x4 = 80000, fx4 = 9.5682;
    double x = 46208; 
	c0 = fx0;
	c1 = (fx1-fx0)/(x1-x0);
	c2 = (((fx2-fx1)/(x2-x1))-((fx1-fx0)/(x1-x0)))/(x2-x0);
	fx = c0 + c1*(x-x0) + c2*(x-x0)*(x-x1);

	printf("%.6lf", fx);
    return 0;
}











