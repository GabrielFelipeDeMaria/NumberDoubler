#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    int numeros[10];
    int i;

    arquivoEntrada = fopen("entrada.txt", "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        fscanf(arquivoEntrada, "%d", &numeros[i]);
    }
    fclose(arquivoEntrada);

    for (i = 0; i < 10; i++) {
        numeros[i] *= 2;
    }

    arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao criar o arquivo de saída!\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        fprintf(arquivoSaida, "%d ", numeros[i]);
    }
    fprintf(arquivoSaida, "\n");
    fclose(arquivoSaida);

    printf("Processamento concluído com sucesso!\n");
    return 0;
}
