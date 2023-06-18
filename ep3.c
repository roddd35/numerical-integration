#include <stdio.h>

void atribuiFX(double v[]);
void atribuiPontosX(int v[], int h);
/*  
    adicionar o vetor de pontos nessas funcoes 
    retornar o vetor com os valores de F interpolados???
*/
void interpolaLagrange(double v[]);
void trapezioC(double v[], double a, double b, double h);
void simpsomC(double v[], double a, double b, double h);

int main(){
    int h = 5, i;
    double a, b;
    double pontosF[7]; 
    int pontosX[7];
    
    atribuiPontosX(pontosX, h);
    atribuiFX(pontosF);

    a = pontosX[0]; b = pontosX[6];

    return 0;
}

void atribuiPontosX(int v[], int h){
    int i;
    for(i = 0; i < 7; i++){
        if(i == 0)
            v[i] = 0;
        else
            v[i] = v[i - 1] + h;
    }
}

void atribuiFX(double v[]){
    v[0] = 0.0000; 
    v[1] = 1.5297;
    v[2] = 9.5120;
    v[3] = 8.7025;
    v[4] = 2.8087;
    v[5] = 1.0881;
    v[6] = 0.3537;
}

void interpolaLagrange(double v[]){

}