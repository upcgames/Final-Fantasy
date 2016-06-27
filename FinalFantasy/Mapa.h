#pragma once
#include "Posicion.h"
#include "Objeto.h"

using namespace System::Collections::Generic;

namespace FinalFantasy {

	public ref class Mapa {
	public:
		array<Terreno, 2> ^matriz_terreno;
		List<Objeto ^> ^objetos;
		BufferedGraphics ^capa_terreno;

		static Posicion ^puerta1;
		static Posicion ^puerta2;
		static Posicion ^puerta3;
		Mapa ^mapa_p1, ^mapa_p2, ^mapa_p3;

		Objeto ^getObjeto(Posicion ^posicion);

		Terreno getTerrenoEnCoordenada(Posicion ^posicion);

		void mostrarPuertas(Graphics ^graphics);
		void mostrarTerreno(Graphics ^graphics);
		void generarCapaTerreno();
		void mostrarObjetos(Graphics ^graphics);

		void cambiarPuertas(Mapa^ mapa_p1, Mapa ^mapa_p2, Mapa ^mapa_p3);
		Mapa(Mapa^ mapa_p1, Mapa ^mapa_p2, Mapa ^mapa_p3);

		static Mapa ^obtenerMapa(MapaTipo pabellon);
		static Mapa ^mapa_actual;
	};

}