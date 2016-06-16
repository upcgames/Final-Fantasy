#pragma once
#include "Figura.h"
#include "Sprite.h"

namespace FinalFantasy {

	public ref class Animado : Figura {
	public:
		Sprite ^sprite;

		//Ideal para verificar colisiones cuando algun personaje se esta moviendo
		bool colisionaConMapaActual(Posicion ^posicion, Direccion direccion);
	};
}