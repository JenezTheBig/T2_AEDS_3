# Trabalho Prático 2 de AEDS3

## Remoção de Elementos e Vizinhos para Maximização de Pontuação

### OBJETIVO
- Determinar a pontuação máxima possível removendo elementos de uma sequência de inteiros, considerando que a remoção inclui também seus vizinhos.
- **Tema**: Utilização de **Programação Dinâmica** e **Força Bruta** para resolver o problema de otimização de pontuação máxima.
- **Base Teórica**: Algoritmos de programação dinâmica e força bruta aplicados à otimização de somas.

### Mecânica do Algoritmo
- **Programação Dinâmica**: Divide o problema em subproblemas menores, armazena os resultados intermediários e evita cálculos redundantes para melhorar a eficiência.
- **Força Bruta**: Explora todas as combinações possíveis para encontrar a solução ótima, testando cada possível subsequência de remoção de elementos.

### Estratégias de Implementação
- **Programação Dinâmica**: Utiliza um array auxiliar para armazenar a soma máxima em cada fase, evitando recalcular subproblemas e assegurando uma complexidade linear.
- **Força Bruta**: Para cada elemento da sequência, testa a remoção dele e de seus vizinhos, recalculando a pontuação a cada iteração. Isso resulta em uma complexidade exponencial, tornando-o inadequado para grandes entradas.
