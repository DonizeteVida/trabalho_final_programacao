/*
 * problema2.c
 *
 *  Created on: 5 de dez. de 2020
 *      Author: doniz
 */
#include "problema2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ff fflush(stdin)
#define cc system("cls")

struct Carrinho* abrirCarrinho() {
	static int codigo = 0;

	struct Carrinho *carrinho = malloc(sizeof(struct Carrinho));
	carrinho->codigo = ++codigo;
	carrinho->precoTotal = 0;
	carrinho->produtos = 0;
	carrinho->totalProdutos = 0;
	printf("Seu carrinho %d foi aberto\n", codigo);
	puts("Digite algo para continuar");
	ff;
	getchar();

	return carrinho;
}

struct Produto* copia(struct Produto *vindo) {
	struct Produto *indo = malloc(sizeof(struct Produto));
	strcpy(indo->desc, vindo->desc);
	indo->codigo = vindo->codigo;
	indo->preco = vindo->preco;
	indo->proximo = 0;
	return indo;
}

void inserirProduto(struct Carrinho *carrinhoAberto) {
	if (carrinhoAberto == 0) {
		puts("Você precisa abrir um carrinho primeiro...");
		ff;
		getchar();
		return;
	}
	struct Produto produtos[] = {
			{ .codigo = 1, .desc = "COCA COLA", .preco = 5.98 },
			{ .codigo = 2, .desc = "FANTA 2LT", .preco = 5.23 },
			{ .codigo = 3, .desc = "SKOL LATINHA", .preco = 2.98 },
			{ .codigo = 4, .desc = "SKOL GARRAFA", .preco = 3.11 },
			{ .codigo = 5, .desc = "ARROZ", .preco = 6.28 },
			{ .codigo = 6, .desc = "FEIJAO", .preco = 7.32 },
			{ .codigo = 7, .desc = "SUCO", .preco = 1.4 }
	};
	cc;
	puts("Escolha um produto:\n");

	for (int i = 0; i < 7; i++) {
		struct Produto *produto = produtos + i;

		printf("%d %s R$ %.2f\n", produto->codigo, produto->desc,
				produto->preco);
	}
	puts("");
	int prodCod;
	puts("Digite o código do produto: ");
	scanf("%d", &prodCod);
	struct Produto *p = carrinhoAberto->produtos;
	struct Produto *novo = copia(produtos + (prodCod - 1));
	carrinhoAberto->precoTotal += novo->preco;
	carrinhoAberto->totalProdutos += 1;
	if (p == 0) {
		carrinhoAberto->produtos = novo;
	} else {
		while (p->proximo != 0) {
			p = p->proximo;
		}
		p->proximo = novo;
	}
}

void listarProdutos(struct Carrinho *carrinhoAberto) {
	if (carrinhoAberto == 0) {
		puts("Você precisa abrir um carrinho primeiro...");
		ff;
		getchar();
		return;
	}
	cc;
	puts("Seus produtos: ");
	puts("-----------------------------");
	for (struct Produto *p = carrinhoAberto->produtos; p != 0; p = p->proximo) {
		printf("%d %s R$ %.2f\n", p->codigo, p->desc, p->preco);
	}
	puts("------------------------------");
	printf("Total produtos: %d\nPreço total: %.2f\n",
			carrinhoAberto->totalProdutos, carrinhoAberto->precoTotal);
	ff;
	puts("Digite algo para continuar...");
	getchar();
}

void problema2() {
	struct Carrinho *carrinhoAberto = 0;

	do {
		cc;
		int opc = 0;
		puts("Digite a opção: ");
		puts("1-> Abrir carrinho");
		puts("2-> Inserir um produto");
		puts("3-> Listar produtos no carrinho");

		fflush(stdin);
		scanf("%d", &opc);

		switch (opc) {
		case 1:
			carrinhoAberto = abrirCarrinho();
			continue;
		case 2:
			inserirProduto(carrinhoAberto);
			continue;
		case 3:
			listarProdutos(carrinhoAberto);
			continue;
		}

		break;
	} while (1);
}

