#pragma once
#include "Posicion.h"

namespace FinalFantasy {

	public ref class Figura {
	public:
		Image ^imagen;
		Posicion ^posicion;
		
		int alto;
		int ancho;
		
		Rectangle getCuerpo();

		Figura();

		static Rectangle crearCuerpo(int x, int y, int ancho, int alto);
	};
}