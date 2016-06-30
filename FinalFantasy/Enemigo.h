#pragma once
#include "Animado.h"

namespace FinalFantasy {

	public ref class Enemigo : public Animado {
	public:
		Enemigo ^enemigo_padre;
		Enemigo ^enemigo_derecho;
		Enemigo ^enemigo_izquierdo;
		
		bool muriendo = false;
		int vida = 5;
		
		void avanzarUnPaso();
		static void crearEnemigo(Enemigo^);
		void Morir();

		Enemigo();
		Enemigo(Posicion ^p);

		void Mostrar(Graphics^ graphics);
	};
}