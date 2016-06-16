#pragma once
#include "Escena.h"

namespace FinalFantasy {

	public ref class MapaEscena : public Escena {
	public:
		int pabellon;
		
		void mouseClick(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		void timerTick(System::Object ^sender, System::EventArgs ^e);
		void teclaDown(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
		void teclaUp(System::Object ^sender, System::Windows::Forms::KeyEventArgs ^e);
		
		MapaEscena();
	};
}