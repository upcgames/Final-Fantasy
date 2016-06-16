#pragma once
#include "Escena.h"

namespace FinalFantasy {

	public ref class EscenaDeMapa : public Escena {
	public:
		Direccion direccion_de_regreso;
		MapaTipo pabellon_de_regreso;
		TipoEscena escena_a_mostrar;
		Posicion ^posicion_de_regreso;
	};
}