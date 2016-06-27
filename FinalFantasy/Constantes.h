#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace FinalFantasy {

	extern const bool DEBUG_MODE;
	// Dimensiones del Windows Form(cuantas coordenadas tendra), en unidades
	extern const int MYFORM_WIDTH;
	extern const int MYFORM_HEIGHT;

	// Dimensiones de cada coordenada(el personaje), en pixeles
	extern const int RESOLUCION_X;
	extern const int RESOLUCION_Y;

	extern const int MYFORM_SIZE_WIDTH;
	extern const int MYFORM_SIZE_HEIGHT;

	extern const float TAMANIO_LETRAS;

	// Velocidad con la que Marco corre en pixeles
	extern const int VELOCIDAD_TIMER;

	// Enums
	public enum TipoEscena { Introduccion, Campus, Tienda };
	public enum Direccion { Arriba, Abajo, Izquierda, Derecha };
	public enum Objetos { Puerta, PuertaEscena, Moneda };
	public enum Terreno { Loceta, Agua, Arena, Granito, Hielo, Lava, Lodo, Maceta, Pasto, Roca, Tejado, Tierra };
	public enum MapaTipo { Salaverry };

	extern Terreno TERRENOS_COLISIONANTES[];
	// Funciones Utiles
	Direccion obtenerDireccionInvertida(Direccion direccion);
	bool Colisiona(Terreno terreno);
	bool noHayONoExsite(Object^ objeto);
}