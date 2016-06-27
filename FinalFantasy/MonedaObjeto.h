#pragma once
#include "ObjetoAnimado.h"

namespace FinalFantasy {

	public ref class MonedaObjeto : public ObjetoAnimado {
	public:
		int dinero_sorpresa;

		virtual bool interactuarConMarco() override;

		MonedaObjeto(Posicion ^posicion);
	};

}