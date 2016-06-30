#pragma once
#include "Animado.h"

namespace FinalFantasy {

	public ref class Enemigo : public Animado {
	public:
		Enemigo ^enemigo_padre;
		Enemigo ^enemigo_derecho;
		Enemigo ^enemigo_izquierdo;
		
		void avanzarUnPaso();
		static void crearEnemigo(Enemigo^);

		Enemigo();
		Enemigo(Posicion ^p);

		void Mostrar(Graphics^ graphics);
	};
}