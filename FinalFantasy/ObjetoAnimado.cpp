#pragma once
#include "ObjetoAnimado.h"

namespace FinalFantasy {

	ObjetoAnimado::ObjetoAnimado(Posicion ^posicion) : Objeto(posicion) {
		this->posicion = posicion;
	}

	void ObjetoAnimado::mostrar(Graphics ^graphics) {
		graphics->DrawImage(
			sprite->imagen,
			Rectangle(posicion->x, posicion->y, ancho, alto),
			Rectangle(
			sprite->indice / 2 * sprite->ancho,
			sprite->subindice * sprite->alto,
			sprite->ancho,
			sprite->alto
			),
			GraphicsUnit::Pixel);

		sprite->indice++;

		if (sprite->indice == sprite->numero_de_columnas * 2)
			sprite->indice = 0;
	}
}