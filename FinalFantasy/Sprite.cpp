#pragma once
#include "Sprite.h"

namespace FinalFantasy {

	Sprite::Sprite(Image ^imagen) {
		this->imagen = imagen;
		frecuencia = 1;
	}

	void Sprite::siguienteIndice() {
		indice++;

		if (indice == numero_de_columnas * frecuencia)
			indice = 0;
	}

	void Sprite::cambiarSubindice(int subindice) {
		this->subindice = subindice;
	}
}