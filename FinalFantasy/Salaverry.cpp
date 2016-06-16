#include "PuertaObjeto.h"
#include "Mapas.h"

namespace FinalFantasy {

	void generarSalaverry() {
		MAPAS::salaverry->matriz_terreno = gcnew array<Terreno, 2> {
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta},
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Pasto, Pasto, Pasto, Maceta, Maceta, Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Pasto, Pasto, Maceta, Pasto, Pasto, Pasto, Maceta, Pasto, Maceta, Maceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Pasto, Maceta, Loceta, Loceta, Maceta, Maceta, Loceta, Loceta, Loceta, Maceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Maceta, Loceta, Loceta, Loceta, Maceta, Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Maceta },
			{ Maceta, Loceta, Loceta, Loceta, Loceta, Pasto, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Maceta },
			{ Maceta, Pasto, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Loceta, Pasto, Pasto, Maceta },
			{ Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta, Maceta }
		};

		MAPAS::salaverry->objetos = gcnew List<Objeto ^>();
		MAPAS::salaverry->objetos->AddRange(gcnew array<Objeto ^>{
			gcnew PuertaObjeto(Salaverry, gcnew Posicion(6, 3, true), gcnew Posicion(0, 3, true), Derecha)
		});

		MAPAS::salaverry->generarCapaTerreno();
	}
}