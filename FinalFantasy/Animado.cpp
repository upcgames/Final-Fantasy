#pragma once
#include "Animado.h"
#include "Mapa.h"

namespace FinalFantasy {

	//Ideal para verificar colisiones cuando algun personaje se esta moviendo
	bool Animado::colisionaConMapaActual(Posicion ^posicion, Direccion direccion) {
		Posicion ^coordenada_pie_izquierdo = posicion->getPieIzquierdo(direccion)->toCoordenadas();
		Posicion ^coordenada_pie_derecho = posicion->getPieDerecho(direccion)->toCoordenadas();

		Terreno terreno1 = Mapa::mapa_actual->getTerrenoEnCoordenada(coordenada_pie_izquierdo);
		Terreno terreno2 = Mapa::mapa_actual->getTerrenoEnCoordenada(coordenada_pie_derecho);

		if (Colisiona(terreno1) || Colisiona(terreno2))
			return true;
		else
			return false;
	}
}