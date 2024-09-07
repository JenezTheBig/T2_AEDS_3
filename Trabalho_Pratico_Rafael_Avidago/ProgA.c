#include "estrategias.h"
#include "uteis.h"


int forca_bruta(int n, int *array) {

    //verificacao do tamanho do array, caso seja igual a 0 retorna 0 e se for igual a 1 retorna o unico numero do arraay
    if (n <= 0){
        return 0;
    }

    if (n == 1){
        return array[0];
    }

    //inicializa a variavel
    int max_pontos = 0;

    for (int i = 0; i < n; i++) {
        //armazena o valor do elemento atual
        int pontos = array[i];
        
        //inicializa a variavel de tamanho do novo array reduzido
        int novo_n = 0;

        //aloca dinamicamente um novo array para armazenar os elementos otimos
        int *novo_array = (int *)malloc(n * sizeof(int));
        if (novo_array == NULL) {
            perror("Nao foi possivel alocar memoria");
            exit(EXIT_FAILURE);
        }

        //Faz um novo array excluindo o elemento atual e os adjacentes
        for (int j = 0; j < n; j++) {
            if (j != i && j != i - 1 && j != i + 1) {
                novo_array[novo_n++] = array[j];
            }
        }

        //chama de maneira recursiva a funcao novamente com o novo array e soma a pontuacao retornada
        pontos += forca_bruta(novo_n, novo_array);

        //atualiza a pontuacao maxima caso a atual seja maior
        max_pontos = max(max_pontos, pontos);

        //libera a memoria alocada
        free(novo_array);
    }
    return max_pontos;
}