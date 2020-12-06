/*
 * problema1.c
 *
 *  Created on: 4 de dez. de 2020
 *      Author: doniz
 */

#include "problema1.h"

#define ff fflush(stdin)
#define cc system("cls")

#include <stdio.h>
#include <stdlib.h>

Candidato *candidatos[100] = { };

void preencheGabarito(char *gabarito) {
	cc;
	printf("Digite o gabarito oficial:");
	ff;
	gets(gabarito);
}

Candidato* preencheCandidato() {
	Candidato *candidato = malloc(sizeof(Candidato));

	candidato->pontos = 0;

	puts("Digite o número do candidato: ");
	ff;
	scanf("%d", &candidato->matricula);

	puts("Digite a resposta do candidato: ");
	ff;
	gets(candidato->resposta);

	return candidato;
}

void colocaCandidato() {
	cc;
	static int posicao = 0;
	if (posicao >= 100) {
		puts(
				"O número máximo de candidatos foi atingido, reinicie o programa...");
		return;
	}
	candidatos[posicao++] = preencheCandidato();
}

int gerarPontos(char *gabarito, char *resposta) {
	int pontos = 0;
	for (int i = 0; i < 50; i++) {

		char gab = gabarito[i];
		char rep = resposta[i];

		if (gab == '\0' || rep == '\0') {
			break;
		} else if (gab == rep) {
			pontos++;
		}
	}
	return pontos;
}

void calcularRespostas(char *gabarito) {
	for (int i = 0; i < 100; i++) {
		Candidato *candidato = candidatos[i];

		if (candidato == 0) {
			continue;
		}

		candidato->pontos = gerarPontos(gabarito, candidato->resposta);
	}
}
int compara(const void *c1, const void *c2) {
	Candidato* candidato1 = (*(Candidato**) c1);
	Candidato* candidato2 = (*(Candidato**) c2);

	if(candidato1 == 0){
		return -1;
	}

	if(candidato2 == 0){
		return 1;
	}

	if (candidato1->pontos < candidato2->pontos) {
		return 1;
	} else if (candidato1->pontos > candidato2->pontos) {
		return -1;
	}
	return 0;
}

void listarCandidatos(){
	puts("Candidatos em ordem crescente");
	puts("----------------------------------");

	for(int i = 0; i < 100; i++){
		Candidato *candidato = candidatos[i];
		if (candidato == 0) {
			continue;
		}
		printf("%d %d\n", candidato->matricula, candidato->pontos);
	}

	puts("----------------------------------");

	ff;
	puts("Digite algo para continuar...");
	getchar();
}

void ordenarCandidatos(char* gabarito) {
	cc;
	calcularRespostas(gabarito);
	qsort(candidatos, 100, sizeof(Candidato*), &compara);
	listarCandidatos();
}

void problema1() {
	char gabarito[51] = { '\0' };

	do {
		cc;
		int opc = 0;
		puts("Digite a opção: ");
		puts("1-> Digitar gabarito oficial");
		puts("2-> Digitar candidato");
		puts("3-> Ordenar candidatos");

		fflush(stdin);
		scanf("%d", &opc);

		switch (opc) {
		case 1:
			preencheGabarito(gabarito);
			continue;
		case 2:
			colocaCandidato();
			continue;
		case 3:
			ordenarCandidatos(gabarito);
			continue;
		}

		break;
	} while (1);
}

