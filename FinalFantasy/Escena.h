#pragma once
#include "Constantes.h"
#include "Posicion.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;

namespace FinalFantasy {

	public ref class Escena	{
	public:
		int contador_timer;
		bool escena_activa;
		bool escena_dibujada;
		
		BufferedGraphics ^escena_buffer;
		
		KeyEventHandler ^onKeyDown;
		KeyEventHandler ^onKeyUp;
		MouseEventHandler ^onMouseClick;
		EventHandler ^onTimerTick;
		
		Escena();

		static Escena ^getEscenaActual();
		static Escena ^getEscenaTipo(TipoEscena tipo);
		static void CambiarEscena(Escena ^escena);
		static void EmpezarConEscena(Escena ^escena);
		static void ActivarEscena(Escena ^escena);
		static void DesactivarEscena(Escena ^escena);
	};
}