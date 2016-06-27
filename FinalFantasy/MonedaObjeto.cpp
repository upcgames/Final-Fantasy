#pragma once
#include "MonedaObjeto.h"
#include "Juego.h"
#include "Marco.h"
#include "Imagenes.h"

namespace FinalFantasy {

	MonedaObjeto::MonedaObjeto(Posicion ^posicion) : ObjetoAnimado(posicion) {
		dinero_sorpresa = (Juego::aleatorio->Next(5) + 1);

		sprite = gcnew Sprite(IMAGENES::MONEDA_SPRITE);
		sprite->indice = 0;
		sprite->subindice = 0;
		sprite->ancho = 122;
		sprite->alto = 122;
		sprite->numero_de_columnas = 7;
		sprite->numero_de_filas = 1;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
	}

	bool MonedaObjeto::interactuarConMarco() {
		Marco::marco->Detener();
		return false;
	}
}