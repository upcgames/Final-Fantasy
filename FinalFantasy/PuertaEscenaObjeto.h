#pragma once
#include "ObjetoStatico.h"

namespace FinalFantasy {

	public ref class PuertaEscenaObjeto : public ObjetoStatico {
	public:
		Direccion direccion_de_regreso;
		MapaTipo pabellon_de_regreso;
		TipoEscena escena_a_mostrar;
		Posicion ^posicion_de_regreso;

		PuertaEscenaObjeto(
			TipoEscena escena_a_mostrar,
			Posicion ^posicion,
			MapaTipo pabellon_de_regreso,
			Posicion ^posicion_de_regreso,
			Direccion direccion_de_regreso
			);

		virtual bool interactuarConMarco() override;
	};
}