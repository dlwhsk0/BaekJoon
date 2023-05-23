#include <stdio.h>
#include <math.h>

int main()

{

    double a, b;

    int n, count = 0;

    scanf("%d", &n);



    for (int i = 1; i <= 500; i++) {

        for (int j = 1; j <= i; j++) {

            a = pow(i, 2);

            b = pow(j, 2);



            if (a == (b + n)) {

                count++;

            }

        }

    }



    printf("%d", count);

    return 0;

}