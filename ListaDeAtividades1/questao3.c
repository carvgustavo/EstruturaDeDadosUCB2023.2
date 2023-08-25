/*Questão 3 - Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y.
Em seguida, implemente funções para calcular a distância entre dois pontos e a inclinação da reta que os conecta.*/

#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

float distancia(struct Ponto p1, struct Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

float inclinacao(struct Ponto p1, struct Ponto p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return dy / dx;
}

int main() {
    struct Ponto ponto1 = { 0.0, 0.0 };
    struct Ponto ponto2 = { 3.0, 4.0 };
    
    printf("A distancia entre os pontos e de: %f\n", distancia(ponto1, ponto2));
    printf("A inclinacao da reta que conecta os pontos e de: %f\n", inclinacao(ponto1, ponto2));
    
    return 0;
}