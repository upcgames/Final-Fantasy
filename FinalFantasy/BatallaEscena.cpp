#include "BatallaEscena.h"
#include "Juego.h"
#include "Imagenes.h"

namespace FinalFantasy {

	BatallaEscena::BatallaEscena() {
		onTimerTick = gcnew EventHandler(this, &BatallaEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &BatallaEscena::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &BatallaEscena::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &BatallaEscena::mouseClick);
	}

	void BatallaEscena::timerTick(System::Object^  sender, System::EventArgs^  e)
	{
		if (escena_activa) {
			contador_timer++;
			IMAGENES::mostarFondo(IMAGENES::BATALLA_FONDO, escena_buffer->Graphics);

			escena_buffer->Render(Juego::graphics);
			escena_dibujada = true;
		}
	}

	void BatallaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (escena_activa && escena_dibujada) {
			;
		}
	}

	void BatallaEscena::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (escena_activa && escena_dibujada) {
			;
		}
	}

	void BatallaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (escena_activa && escena_dibujada) {
			;
		}
	}
}