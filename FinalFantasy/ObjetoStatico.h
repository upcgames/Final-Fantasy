#pragma once
#include "Objeto.h"

namespace FinalFantasy {
	public ref class ObjetoStatico : public Objeto {
	public:
		ObjetoStatico(Posicion ^posicion);
	};
}