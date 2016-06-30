#include "Controles.h"
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
					"Juego de estructuras 2016-01 UPC!",
					"El proposito de este juego SOLO es mostrar",
					"los beneficios de los arboles AVL",
					"en la estructura de datos",
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

		if (escena_activa) {

			if (e->KeyCode == CONTROLES::SALIR) {
				Dialogo::dialogo->terminarDeEscribir();
				DesactivarEscena(this);
				ActivarEscena(ESCENAS::mapa);
				return;
			}

			if (escena_dibujada) {
				DesactivarEscena(this);
				ActivarEscena(ESCENAS::mapa);
			}
		}
	}
}