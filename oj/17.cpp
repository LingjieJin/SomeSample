/**

*/
#include <stdio.h>
#include <math.h>

inline double abs(double x){return (x>0?x:-x);}

double fun(double n) {
    double x = 1.0;
    while(fabs(x*x*x - n) > 1e-9)
        x = x - ((x*x*x - n) / (3*x*x));
    return x;
}

int main() {
    int number;
    scanf("%d", &number);
    double ans = fun(number*1.0);
    printf("%.1f", ans);
    return 0;
}