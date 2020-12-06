/*
 * problema2.h
 *
 *  Created on: 5 de dez. de 2020
 *      Author: doniz
 */

#ifndef PROBLEMA2_PROBLEMA2_H_
#define PROBLEMA2_PROBLEMA2_H_

struct Produto {
	int codigo;
	char desc[256];
	float preco;
	struct Produto* proximo;
};

struct Carrinho {
	int codigo;
	float precoTotal;
	int totalProdutos;
	struct Produto* produtos;
};

void problema2();

#endif /* PROBLEMA2_PROBLEMA2_H_ */
