#pragma once
#include "Escena.h"

namespace FinalFantasy {

	public ref class Dialogo : public Escena {
	private:
		array<String^> ^mensajes;
		String ^oracion_actual;
		Font ^fuente;

		int posicion_oracion;
		bool esperando_confirmacion;
		bool pausar_anterior_escena;

		float punto_de_comienzo;
		int numero_de_caracteres;
		int numero_de_oraciones;
	public:
		Escena ^escena_anterior;
		int posicion_parrafo;

		static Dialogo ^dialogo;

		void timerTick(System::Object ^ sender, System::EventArgs ^e);
		void teclaDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^e);
		void mouseClick(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^e);

		void empezarAEscribir();
		void escribirCaracter();
		void terminarDeEscribir();

		Dialogo(... array<String^> ^mensajes);

		static void mostarMensaje(... array<String^> ^mensajes);
		static void pausarYMostarMensaje(... array<String ^> ^mensajes);
		static int getNumeroDeParrafo();
	};
}