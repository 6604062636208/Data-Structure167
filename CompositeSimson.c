#include <stdio.h>
#include <math.h>

float f(float x) {
    return pow(x, 7) + 2 * pow(x, 3) - 1;
}

float exact_integral() {
    float b = (pow(2, 8) / 8.0) + (pow(2, 4) / 2.0) - 2.0;
    float a = (pow(-1, 8) / 8.0) + (pow(-1, 4) / 2.0) - (-1.0);
    return b - a;
}
float composite_simpson_rule(float a, float b, int n) {
    float h = (b - a) / n;
    float sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);  
        } else {
            sum += 4 * f(x);  
        }
    }
    return (h / 3.0) * sum;
}
int main() {
    float a = -1.0;  
    float b = 2.0;  
    float exact = exact_integral();
    for (int n  = 4; n <= 12; n += 4) {
        float result_composite = composite_simpson_rule(a, b, n);
        float error_composite = fabs(exact - result_composite)/(exact)*100;
        printf("Composite Simpson's Rule (n=%d): %lf (Error: %lf)\n", n, result_composite, error_composite);
    }
    return 0;
}



