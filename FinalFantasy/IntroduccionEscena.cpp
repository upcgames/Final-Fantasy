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

				Dialogo::mostarMensaje(
					"Bienvenido a Final Fantasy!!!",
					"Juego de estructuras 2016 - UPC!",
					"Se hace uso de arboles mediante",
					"la recursividad!!!"
				);

				if (Dialogo::getNumeroDeParrafo() == 0) {
					IMAGENES::mostarFondo(IMAGENES::INTRODUCCION_FONDO, escena_buffer->Graphics);
				}
			}
		}
	}

	void IntroduccionEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
			DesactivarEscena(this);
			ActivarEscena(ESCENAS::mapa);
		}
	}
}