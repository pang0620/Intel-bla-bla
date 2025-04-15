#include <stdio.h>

int main() {
    int price = 12*10000;
    double rate = 0.1;

    printf("%.0lf\n", price - price * rate );

    return 0;
}