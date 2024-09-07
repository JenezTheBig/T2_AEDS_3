#ifndef UTEIS_H
#define UTEIS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

void lerEntrada(const char *nomeArquivo, int **seq, int *n);
void escreverSaida(const char *nomeArquivo, int resultado);
int max(int a, int b);
void MedeTempo(struct timeval *start, struct rusage *usage);
void FinalMedeTempo(const struct timeval *start, struct timeval *end, double *mtime, struct rusage *usage);
#endif