#pragma once
#include "Escena.h"

namespace FinalFantasy {

	public ref class IntroduccionEscena : public Escena	{
	public:
		IntroduccionEscena();

		void timerTick(System::Object ^sender, System::EventArgs ^e);
		void teclaDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
	};
}