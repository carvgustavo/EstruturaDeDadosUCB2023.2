/*Questão 2 - Crie uma struct chamada "Tipo" que possa armazenar um valor do tipo inteiro, um valor do tipo ponto
flutuante e uma letra. Escreva um programa que demonstre o uso da struct, atribuindo valores de diferentes tipos e
imprimindo-os.*/

struct Tipo
{
    int numInteiro;
    float pontoFlutuante;
    char letra;
};

int main(){

    struct Tipo t;

    t.numInteiro = 20;
    t.pontoFlutuante = 1.80;
    t.letra = 'g';

    printf("Numero inteiro: %d\n", t.numInteiro);
    printf("Ponto flutuante: %.2f\n", t.pontoFlutuante);
    printf("Char: %c\n", t.letra);

    return 0;
}
