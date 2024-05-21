#include <stdio.h>
#include <string.h>

#define NUMERO_VOOS 12

typedef struct {
    char numero[10];
    char origem[30];
    char destino[30];
    int lugaresDisponiveis;
} Voo;

void consultarVoo(Voo voos[], int totalDeVoos) {
    int opcao;
    printf("Consultar por:\n");
    printf("1. Número do voo\n");
    printf("2. Destino\n");
    scanf("%d", &opcao);
    if (opcao == 1) {
        char numero[10];
        printf("Informe o número do voo: ");
        scanf("%s", numero);
        int Vencontrado = 0;
        for (int i = 0; i < totalDeVoos; i++) {
            if (strcmp(voos[i].numero, numero) == 0) {
                printf("Voo encontrado: %s de %s para %s com %d lugares disponíveis.\n", voos[i].numero, voos[i].origem, voos[i].destino, voos[i].lugaresDisponiveis);
                Vencontrado = 1;
                break;
            }
        }
        if (!Vencontrado) {
            printf("Voo não encontrado.\n");
        }
    } else if (opcao == 2) {
        char destino[30];
        printf("Informe o destino: ");
        scanf("%s", destino);
        int Vencontrado = 0;
        for (int i = 0; i < totalDeVoos; i++) {
            if (strcmp(voos[i].destino, destino) == 0) {
                printf("Voo encontrado: %s de %s para %s com %d lugares disponíveis.\n", voos[i].numero, voos[i].origem, voos[i].destino, voos[i].lugaresDisponiveis);
                Vencontrado = 1;
            }
        }
        if (!Vencontrado) {
            printf("Nenhum voo encontrado para o destino informado.\n");
        }
    }
}

void efetuarReserva(Voo voos[], int totalDeVoos) {
    char numero[10];
    printf("Informe o número do voo para reserva: ");
    scanf("%s", numero);
    int Vencontrado = 0;
    for (int i = 0; i < totalDeVoos; i++) {
        if (strcmp(voos[i].numero, numero) == 0) {
            Vencontrado = 1;
            if (voos[i].lugaresDisponiveis > 0) {
                voos[i].lugaresDisponiveis--;
                printf("Reserva confirmada. Lugares restantes: %d\n", voos[i].lugaresDisponiveis);
            } else {
                printf("Voo lotado.\n");
            }
            break;
        }
    }
    if (!Vencontrado) {
        printf("Voo inexistente.\n");
    }
}

int main() {
    Voo voos[NUMERO_VOOS];
    int totalDeVoos = NUMERO_VOOS;

    // Leitura dos dados dos voos
    for (int i = 0; i < NUMERO_VOOS; i++) {
        printf("Informe os dados do voo %d (numero, origem, destino, lugares disponíveis):\n", i + 1);
        scanf("%s %s %s %d", voos[i].numero, voos[i].origem, voos[i].destino, &voos[i].lugaresDisponiveis);
    }

    while (1) {
        int opcao;
        printf("Menu:\n");
        printf("1. Consultar\n");
        printf("2. Efetuar reserva\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            consultarVoo(voos, totalDeVoos);
        } else if (opcao == 2) {
            efetuarReserva(voos, totalDeVoos);
        } else if (opcao == 3) {
            printf("Saindo do programa...\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
