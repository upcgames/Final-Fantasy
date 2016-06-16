#pragma once

using namespace System::Drawing;

namespace FinalFantasy {

	public ref class IMAGENES abstract sealed {
	public:
		static void mostarFondo(Image ^imagen, Graphics ^graphics);

		static Image^ MARCO_SPRITE;

		static Image ^LOCETA;
		static Image ^MACETA;
		static Image ^PASTO;

		static Image^ INTRODUCCION_FONDO;
	};
}