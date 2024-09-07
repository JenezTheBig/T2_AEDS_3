#include "estrategias.h"
#include "uteis.h"

int programacao_dinamica(int n, int *array){
    //verificacao do tamanho do array, caso seja igual a 0 retorna 0 e se for igual a 1 retorna o unico numero do arraay
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return array[0];
    }

    //alocacao dinamica para um array de inteiros do tamanho n+1 que servira para armazenar os resultados parciais
    int *pd = (int *)malloc((n + 1) * sizeof(int));
    if (pd == NULL) {
        perror("Nao foi possivel alocar memoria");
        exit(EXIT_FAILURE);
    }

    //inicializacao dos dois primeiros numeros do array
    pd[0] = 0;
    pd[1] = array[0];

    //preenche pd com valores otimos de maneira iterativa. e dividido em duas possibilidades, nao incluir o elemento atual (pd[i-1] ou incluir o elemento atual(pd[i-1] + array[i -1]) pd[i] e o maior valor entre as duas opcoes)
    for(int i = 2; i <= n; i++) {
        pd[i] = max(pd[i - 1], pd[i - 2] + array[i - 1]);
    }

    //armazena o resultado, libera a memoria alocada e retorna o resultado otimo.
    int resultado = pd[n];

    free(pd);

    return resultado;

}