#pragma once
#include "Imagenes.h"
#include "Mapas.h"
#include "Juego.h"

namespace FinalFantasy {

	Mapa::Mapa() {
		capa_terreno = Juego::context->Allocate(Juego::graphics, Juego::myform->ClientRectangle);
	}

	void Mapa::generarCapaTerreno() {
		for (int y = 0; y < MYFORM_HEIGHT; y++) {
			for (int x = 0; x < MYFORM_WIDTH; x++) {

				Image ^imagen_terreno;
				int coordenada_x = x * RESOLUCION_X;
				int coordenada_y = y * RESOLUCION_Y;

				switch (matriz_terreno[y, x]) {
				case Loceta:
					imagen_terreno = IMAGENES::LOCETA;
					break;
				case Pasto:
					imagen_terreno = IMAGENES::PASTO;
					break;
				case Maceta:
					imagen_terreno = IMAGENES::MACETA;
					break;
				}

				capa_terreno->Graphics->DrawImage(imagen_terreno, Rectangle(coordenada_x, coordenada_y, RESOLUCION_X, RESOLUCION_Y));

				if (DEBUG_MODE)
					capa_terreno->Graphics->DrawString(
						coordenada_x + "," + coordenada_y,
						gcnew Font("Arial", 8.0f),
						gcnew SolidBrush(Color::Black),
						(float)coordenada_x,
						(float)coordenada_y
					);
			}
		}
	}

	Objeto ^Mapa::getObjeto(Posicion ^posicion) {

		int numero_de_objetos = this->objetos->Count;

		for (int i = 0; i < numero_de_objetos; i++) {
			if (objetos[i]->getCuerpo().IntersectsWith(posicion->getCuerpo())) {
				return objetos[i];
			}
		}

		return nullptr;
	}

	Terreno Mapa::getTerrenoEnCoordenada(Posicion ^posicion) {

		// Se invierte, porque los mapas se guardan en forma x,y
		int y = posicion->y;
		int	x = posicion->x;

		if (x < 0 || x >= matriz_terreno->GetLength(1))
			return (Terreno)0;
		if (y < 0 || y >= matriz_terreno->GetLength(0))
			return Terreno(0);

		return matriz_terreno[y, x];
	}

	void Mapa::mostrarTerreno(Graphics ^graphics) {
		capa_terreno->Render(graphics);
	}

	void Mapa::mostrarObjetos(Graphics ^graphics) {

		int numero_de_objetos = this->objetos->Count;

		for (int i = 0; i < numero_de_objetos; i++)
			objetos[i]->mostrar(graphics);
	}

	Mapa ^Mapa::obtenerMapa(MapaTipo pabellon) {

		switch (pabellon)
		{
		case Salaverry:
			return MAPAS::salaverry;
			break;
		default:
			return nullptr;
		}
	}
}