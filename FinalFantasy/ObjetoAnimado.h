#pragma once
#include "Objeto.h"

namespace FinalFantasy {
	public ref class ObjetoAnimado : public Objeto {
	public:
		Sprite ^sprite;

		ObjetoAnimado(Posicion ^posicion);

		virtual void mostrar(Graphics ^graphics) override;

	};
}