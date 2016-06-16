#pragma once
#include "Imagenes.h"
#include "Dialogo.h"
#include "Escenas.h"
#include "Escena.h"
#include "Juego.h"

namespace FinalFantasy {

	IntroduccionEscena::IntroduccionEscena() {
		onTimerTick = gcnew EventHandler(this, &IntroduccionEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &IntroduccionEscena::teclaDown);
	}

	void IntroduccionEscena::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (escena_activa) {
			if (!escena_dibujada) {
				IMAGENES::mostarFondo(IMAGENES::INTRODUCCION_FONDO, escena_buffer->Graphics);
				escena_buffer->Render(Juego::graphics);

				Dialogo::mostarMensaje(
					"lorem ipsum ",
					"esta es una prueba"
					);

				escena_dibujada = true;
			}
		}
	}

	void IntroduccionEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
			DesactivarEscena(this);
			ActivarEscena(ESCENAS::introduccion);
		}
	}
}