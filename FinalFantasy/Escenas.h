#pragma once
#include "IntroduccionEscena.h"
#include "MapaEscena.h"

namespace FinalFantasy {

	public ref class ESCENAS abstract sealed {
	public:
		static IntroduccionEscena ^introduccion;
		static MapaEscena ^mapa;
	};
}