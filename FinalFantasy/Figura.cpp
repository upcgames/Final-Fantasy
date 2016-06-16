#pragma once
#include "Figura.h"

namespace FinalFantasy {

	Figura::Figura() { ; }

	Rectangle Figura::getCuerpo() {
		return Rectangle(posicion->x, posicion->y, ancho, alto);
	}

	Rectangle Figura::crearCuerpo(int x, int y, int ancho, int alto) {
		return Rectangle(x, y, ancho, alto);
	}
}