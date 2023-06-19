#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000000

double uniDim(int a, int b, unsigned long int n, int op);
double multDim(unsigned long int n);

/* colocamos n = MAX pois o resultado deve convergir quando n tende a infinito */
int main(){
    int op;
    printf("Bem vinde!\n");
    printf("Por favor, informe uma integral para aproximar\n");
    printf("1. sen x \n2. x^3 \n3. e^{-x} \n4. pi(valor)\n" );
    printf("Escolha: ");
    scanf("%d", &op);

    if(op == 1)
        printf("%lf", uniDim(0, 0, MAX, 1));
    if(op == 2)
        printf("%lf", uniDim(3, 7, MAX, 2));
    if(op == 3)
        printf("%lf", uniDim(0, MAX, MAX, 3));
    if(op == 4)
        printf("%lf", multDim(MAX));

    return 0;
}

double uniDim(int a, int b, unsigned long int n, int op){
    unsigned long int i;
    double res = 0.0;
    double x, res1 = res, res2 = res;

    srand(time(NULL));

    for(i = 0; i < n; i++){
        x = (double)rand()/RAND_MAX;
        if(op == 1)
            res += sin(x);
        if(op == 2)
            res += pow(a + 0.564 * (b-a), 3);
        if(op == 3){
            res1 += exp(-x);    /* calculamos exp(-x) em [0,1]*/
            res2 += 1 / exp(1); /* calculamos 1 / exp(1), pois sua integral em [0,1] equivale à integral de e^(-x) em [1,inf) */
        }
    }
    if(op == 1)
        return res / n;

    if (op == 3){   /* somamos para obter integral de e^(-x) em [0,inf) (pois temos de 0 a 1 e de 1 a infinito) */
        res1 /= n;
        res2 /= n;
        res = res1 + res2;  
    }
         
    return (b - a) * res / n;
}

/* aproximar o valor de pi */
double multDim(unsigned long int n){
    unsigned long int i;
    double res = 0.0;
    double x, y;

    srand(time(NULL));

    for(i = 0; i < n; i++){ 
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;

        if(x * x + y * y <= 1.0)
            res++;
    }

    return (4 * (double)res/n);
}