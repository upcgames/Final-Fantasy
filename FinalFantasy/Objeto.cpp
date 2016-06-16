#pragma once
#include "EscenaDeMapa.h"
#include "Objeto.h"
#include "Escena.h"
#include "Mapa.h"

namespace FinalFantasy {

	Objeto::Objeto(Posicion ^posicion) {
		this->posicion = posicion;
	}

	void Objeto::mostrar(Graphics ^graphics) {
		;
	}

	bool Objeto::interactuarConMarco() {
		return false;
	}
}