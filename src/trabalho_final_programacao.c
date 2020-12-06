/*
 ============================================================================
 Name        : trabalho_final_programacao.c
 Author      : DonizeteVida
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "problema1/problema1.h"
#include "problema2/problema2.h"

typedef void(*Problema)(void);

int main(void) {
	setlocale(LC_ALL, "");

	do {
		int opc = 0;
		puts("Escolha um problema: ");
		scanf("%d", &opc);

		Problema problema[] = {
				&problema1,
				&problema2
		};

		switch (opc) {
		case 1:
		case 2:
			problema[opc - 1]();
			continue;
		}
	} while (1);
	return EXIT_SUCCESS;
}
