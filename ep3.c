#include <stdio.h>
#include <math.h>

double interpolaLagrange(double x);
double calculaWJ(int j);
double trapezioC(int r);
double simpsonC(int r);

int pontosX[] = {0, 5, 10, 15, 20, 25, 30};
double pontosFX[] = {0.0000, 1.5297, 9.5120, 8.7025, 2.8087, 1.0881, 0.3537};

int main(){
    int r = 5;

    printf("%lf\n", trapezioC(r));

    return 0;
}

/* i. interpolacao por lagrange */
double interpolaLagrange(double x){
    int i;
    double wj;
    double px = 0.0;
    double phi = 1;
    for(i = 0; i < 7; i++){
        if(x == pontosX[i])
            return pontosFX[i];
        phi *= x - pontosX[i];
    }
    
    for(i = 0; i < 7; i++){
        px += (calculaWJ(i) * pontosFX[i]) / (x - pontosX[i]);
    }
    px *= phi;

    return px;
}

double calculaWJ(int j){
    int i;
    double div = 1;
    for(i = 0; i < 7; i++){
        if(i != j)
            div *= pontosX[j] - pontosX[i];
    }
    return (1 / div);
}

/* ii. calculo da integral pela regra do trapezio composta */
double trapezioC(int r){
    int i;
    double h = 30.0 / r;
    double res = 0.0;
    
    for(i = 1; i <= r; i++)
        res += interpolaLagrange(i * h);

    res *= 2;
    res += interpolaLagrange(0.0) + interpolaLagrange(30.0);
    res *= h / 2;

    return res;
}

/* iii. calculo da integral pela regra de simpson composta */
double simpsonC(int r){
    int i;
    double h = 30.0 / r;
    double res = 0.0;
    double res1 = res, res2 = res;

    if(!(r % 2))
        r++;

    for(i = 1; i <= r / 2 - 1; i++)
        res1 += interpolaLagrange(i * 2 * h);
    res1 *= 2;

    for(i = 1; i <= r / 2; i++)
        res2 += interpolaLagrange(i * 2 * h - 1);
    res2 *= 4;

    res += interpolaLagrange(0.0) + interpolaLagrange(30.0) + res1 + res2;
    res *= h / 3;

    return res;
}