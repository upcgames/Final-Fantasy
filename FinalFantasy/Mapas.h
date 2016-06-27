#pragma once
#include "Mapa.h"

using namespace System::Collections::Generic;

namespace FinalFantasy {

	public ref class MAPAS abstract sealed {
	public:
		static List <Mapa ^> ^lista;
	};

}