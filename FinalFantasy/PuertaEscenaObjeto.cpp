#pragma once
#include "PuertaEscenaObjeto.h"
#include "EscenaDeMapa.h"

namespace FinalFantasy {

	PuertaEscenaObjeto::PuertaEscenaObjeto(
		TipoEscena escena_a_mostrar,
		Posicion ^posicion,
		MapaTipo pabellon_de_regreso,
		Posicion ^posicion_de_regreso,
		Direccion direccion_de_regreso
		) : ObjetoStatico(posicion) {

		tipo = PuertaEscena;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
		this->escena_a_mostrar = escena_a_mostrar;
		this->pabellon_de_regreso = pabellon_de_regreso;
		this->posicion_de_regreso = posicion_de_regreso;
		this->direccion_de_regreso = direccion_de_regreso;
	}

	bool PuertaEscenaObjeto::interactuarConMarco() {
		Escena::CambiarEscena(Escena::getEscenaTipo(escena_a_mostrar));
		Escena ^escena = Escena::getEscenaTipo(escena_a_mostrar);
		EscenaDeMapa ^escena_de_mapa = dynamic_cast<EscenaDeMapa ^>(escena);

		escena_de_mapa->escena_a_mostrar = escena_a_mostrar;
		escena_de_mapa->pabellon_de_regreso = pabellon_de_regreso;
		escena_de_mapa->posicion_de_regreso = posicion_de_regreso;
		escena_de_mapa->direccion_de_regreso = direccion_de_regreso;

		return false;
	}
}