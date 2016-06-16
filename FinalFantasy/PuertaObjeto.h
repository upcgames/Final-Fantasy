#pragma once
#include "ObjetoStatico.h"

namespace FinalFantasy {

	public ref class PuertaObjeto : public ObjetoStatico {
	public:
		Direccion direccion_de_salida;
		MapaTipo pabellon_de_salida;
		Posicion ^posicion_de_salida;

		PuertaObjeto(
			MapaTipo pabellon_de_salida,
			Posicion  ^posicion,
			Posicion ^posicion_de_salida,
			Direccion direccion_de_salida
		);

		virtual bool interactuarConMarco() override;
	};

}