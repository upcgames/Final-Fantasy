#pragma once
#include "Animado.h"

namespace FinalFantasy {

	public ref class Marco : public Animado {
	public:
		static bool debe_avanzar;

		Direccion direccion_arma = Izquierda;
		void intentarAvanzar(Direccion direccion);
		void avanzarUnPaso();
		void Detener();

		Marco(Posicion ^p);

		static void mostrarloEn(Graphics ^graphics);
		static Marco ^marco;
	};
}