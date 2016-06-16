#pragma once
#include "Figura.h"
#include "Sprite.h"

namespace FinalFantasy {

	public ref class Objeto : public Figura {
	public:
		Objetos tipo;

		Objeto(Posicion ^posicion);

		virtual void mostrar(Graphics ^graphics);
		virtual bool interactuarConMarco();
	};
}