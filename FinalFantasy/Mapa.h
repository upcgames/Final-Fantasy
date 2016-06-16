#pragma once
#include "Posicion.h"
#include "Objeto.h"

using namespace System::Collections::Generic;

namespace FinalFantasy {

	public ref class Mapa {
	protected:
		void generarCapaTerreno();
	public:
		array<Terreno, 2> ^matriz_terreno;
		List<Objeto ^> ^objetos;
		BufferedGraphics ^capa_terreno;

		Objeto ^getObjeto(Posicion ^posicion);

		Terreno getTerrenoEnCoordenada(Posicion ^posicion);

		void mostrarTerreno(Graphics ^graphics);
		void mostrarObjetos(Graphics ^graphics);

		Mapa();

		static Mapa ^obtenerMapa(MapaTipo pabellon);
		static Mapa ^mapa_actual;
	};
}