#include "estrategias.h"
#include "uteis.h"

int main(int argc, char *argv[]) {
    //verifica se o numero de argumentos e correto
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <estrategia> <entrada> <saida>\n", argv[0]);
        return EXIT_FAILURE;
    }

    //armazena os argumentos 
    char estrategia = argv[1][0];
    const char *nomeEntrada = argv[2];
    const char *nomeSaida = argv[3];

    //var para medir tempo
    struct timeval start, end;
    struct rusage usage;
    double mtime;

    int *seq = NULL; //ponteiro que armazena a sequencia lida na entrada
    int n = 0; //armazena o tamanho da sequencia
    //ler entrada (uteis.c)
    lerEntrada(nomeEntrada, &seq, &n);


    //inicializa o resultado
    int resultado = 0;

    // Inicio do temporizador (uteis.c)
    MedeTempo(&start, &usage);

    //seletor de estrategia: 'D' para prog dinamica, 'A' para solucao alternativa
    if (estrategia == 'D') {
        //executa programacao_dinamica(ProgD.c)
        resultado = programacao_dinamica(n, seq);
    } else if (estrategia == 'A') {
        //executa forca_bruta(ProgA.c)
        resultado = forca_bruta(n, seq);
    } else {
        //caso a estrategia selecionada seja diferente do esperado exibe esta mensagem.
        fprintf(stderr, "Estratégia inválida: %c\n", estrategia);
        free(seq);
        return EXIT_FAILURE;
    }

    // Fim do temporizador e contador de uso (uteis.c)
    FinalMedeTempo(&start, &end, &mtime, &usage);

    //escreve o resultado na saida de texto(uteis.c)
    escreverSaida(nomeSaida, resultado);

    //libera memoria alocada para a sequencia
    free(seq);

    //retorna sucesso 
    return 0;
}