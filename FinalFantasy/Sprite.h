#pragma once

using namespace System::Drawing;

namespace FinalFantasy {

	public ref class Sprite {
	public:
		Image ^imagen;
		int indice;
		int subindice;
		int ancho;
		int alto;
		int numero_de_filas;
		int numero_de_columnas;

		void siguienteIndice();
		void cambiarSubindice(int subindice);

		Sprite(Image ^image);
	};
}