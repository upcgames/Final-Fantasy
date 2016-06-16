#pragma once
#include "Sprite.h"

namespace FinalFantasy {

	Sprite::Sprite(Image ^imagen) {
		this->imagen = imagen;
	}

	void Sprite::siguienteIndice() {
		indice++;

		if (indice == numero_de_columnas)
			indice = 0;
	}

	void Sprite::cambiarSubindice(int subindice) {
		this->subindice = subindice;
	}
}