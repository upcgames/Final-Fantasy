#pragma once
#include "PuertaObjeto.h"
#include "Marco.h"
#include "Mapa.h"

namespace FinalFantasy {

	PuertaObjeto::PuertaObjeto(
		MapaTipo pabellon_de_salida,
		Posicion ^posicion,
		Posicion ^posicion_de_salida,
		Direccion direccion_de_salida
		) : ObjetoStatico(posicion) {

		tipo = Puerta;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
		this->pabellon_de_salida = pabellon_de_salida;
		this->posicion_de_salida = posicion_de_salida;
		this->direccion_de_salida = direccion_de_salida;
	}

	bool PuertaObjeto::interactuarConMarco() {
		Marco::marco->posicion->igualarA(this->posicion_de_salida);
		Marco::marco->direccion = this->direccion_de_salida;
		Mapa::mapa_actual = Mapa::obtenerMapa(pabellon_de_salida);
		return false;
	}
}