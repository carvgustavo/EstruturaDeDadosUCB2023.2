/*Questão 9 - Crie uma struct chamada "Funcionario" com campos para nome, cargo, salário e data de admissão.
Implemente funções para dar um aumento de salário e calcular quanto tempo um funcionário está na empresa.*/

#include <stdio.h>
#include <time.h>

struct Funcionario {
    char nome[30];
    char cargo[30];
    float salario;
    struct tm dataAdmissao;
};

void AumentoSalario(struct Funcionario* funcionario, float percentual) {
    funcionario->salario *= (1 + percentual/100);
}

int TempoEmpresa(struct Funcionario* funcionario) {
    time_t agora;
    time(&agora);
    struct tm* dataAtual = localtime(&agora);
    int anos = dataAtual->tm_year - funcionario->dataAdmissao.tm_year;
    int meses = dataAtual->tm_mon - funcionario->dataAdmissao.tm_mon;
    if (meses < 0) {
        anos--;
        meses += 12;
    }
    return anos;
}

int main() {
    struct Funcionario funcionario;

    printf("Digite o nome do funcionario: ");
    fgets(funcionario.nome, 50, stdin);

    printf("Digite o cargo do funcionario: ");
    fgets(funcionario.cargo, 50, stdin);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    printf("Digite a data de admissao do funcionario (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &funcionario.dataAdmissao.tm_mday, &funcionario.dataAdmissao.tm_mon, &funcionario.dataAdmissao.tm_year);

    AumentoSalario(&funcionario, 10);
    printf("O novo salario do funcionario eh: %.2f\n", funcionario.salario);

    int anosEmpresa = TempoEmpresa(&funcionario);
    printf("O funcionario esta na empresa ha %d anos.\n", anosEmpresa);

    return 0;
}
