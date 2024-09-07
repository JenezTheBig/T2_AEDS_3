#include "uteis.h"

// Função para ler a entrada do arquivo
void lerEntrada(const char *nomeArquivo, int **seq, int *n) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Nao foi possivel abrir o arquivo de entrada");
        exit(EXIT_FAILURE);
    }
    if (fscanf(arquivo, "%d", n) != 1) {
        perror("Nao foi possivel ler o número de elementos");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }
    *seq = (int *)malloc(*n * sizeof(int));
    if (*seq == NULL) {
        perror("Nao foi possivel alocar memória");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < *n; ++i) {
        if (fscanf(arquivo, "%d", &(*seq)[i]) != 1) {
            perror("Erro ao ler os elementos da sequência");
            fclose(arquivo);
            free(*seq);
            exit(EXIT_FAILURE);
        }
    }
    fclose(arquivo);
}


void escreverSaida(const char *nomeArquivo, int resultado) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Nao foi possivel abrir o arquivo de saída");
        exit(EXIT_FAILURE);
    }
    fprintf(arquivo, "%d\n", resultado);
    fclose(arquivo);
}

// Função para retornar o maior valor entre dois inteiros. Utilizada em forca bruta e em prog dinamica
int max(int a, int b) {
    return (a > b) ? a : b;
}

void MedeTempo(struct timeval *start, struct rusage *usage){
    getrusage(RUSAGE_SELF, usage);
    gettimeofday(start, NULL);
}

// Finaliza as execuções anteriores e imprime os resultados
void FinalMedeTempo(const struct timeval *start, struct timeval *end, double *mtime, struct rusage *usage){
    long seconds, useconds;
    gettimeofday(end, NULL);
    seconds  = end->tv_sec  - start->tv_sec;
    useconds = end->tv_usec - start->tv_usec;
    *mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    getrusage(RUSAGE_SELF, usage);

    printf("Tempo decorrido: %.2f ms\n", *mtime);
    printf("  Tempo de CPU no usuário: %ld.%06ld segundos\n", usage->ru_utime.tv_sec, usage->ru_utime.tv_usec);
    printf("  Tempo de CPU no sistema: %ld.%06ld segundos\n", usage->ru_stime.tv_sec, usage->ru_stime.tv_usec);
}
