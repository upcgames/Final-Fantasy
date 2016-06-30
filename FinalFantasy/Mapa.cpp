#include "Imagenes.h"
#include "Juego.h"
#include "Mapa.h"

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
				case Agua:
					imagen_terreno = IMAGENES::AGUA;
					break;
				case Arena:
					imagen_terreno = IMAGENES::ARENA;
					break;
				case Granito:
					imagen_terreno = IMAGENES::GRANITO;
					break;
				case Hielo:
					imagen_terreno = IMAGENES::HIELO;
					break;
				case Lava:
					imagen_terreno = IMAGENES::LAVA;
					break;
				case Lodo:
					imagen_terreno = IMAGENES::LODO;
					break;
				case Maceta:
					imagen_terreno = IMAGENES::MACETA;
					break;
				case Pasto:
					imagen_terreno = IMAGENES::PASTO;
					break;
				case Roca:
					imagen_terreno = IMAGENES::ROCA;
					break;
				case Tejado:
					imagen_terreno = IMAGENES::TEJADO;
					break;
				default:
					imagen_terreno = IMAGENES::TIERRA;
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

	void Mapa::mostrarPuertas(Graphics ^graphics) {
		if (!noHayONoExsite(mapa_p1))
			graphics->DrawImage(IMAGENES::PUERTA, Rectangle(puerta1->x,puerta1->y, RESOLUCION_X, RESOLUCION_Y));
		if (!noHayONoExsite(mapa_p2))
			graphics->DrawImage(IMAGENES::PUERTA, Rectangle(puerta2->x, puerta2->y, RESOLUCION_X, RESOLUCION_Y));
		if (!noHayONoExsite(mapa_p3))
			graphics->DrawImage(IMAGENES::PUERTA, Rectangle(puerta3->x, puerta3->y, RESOLUCION_X, RESOLUCION_Y));

	}

	void Mapa::mostrarTerreno(Graphics ^graphics) {
		capa_terreno->Render(graphics);
	}

	void Mapa::mostrarObjetos(Graphics ^graphics) {

		int numero_de_objetos = this->objetos->Count;

		for (int i = 0; i < numero_de_objetos; i++)
			objetos[i]->mostrar(graphics);
	}

	Mapa ^Mapa::crearMapa(Mapa^ mapa) {
		if (mapa->capa_terreno == nullptr)
			return mapa;

		if (Juego::aleatorio->Next(2)) {
			if (mapa->mapa_p2 == nullptr) {
				mapa->mapa_p2 = gcnew Mapa();
				mapa->mapa_p2->mapa_p1 = mapa;
				return mapa->mapa_p2;
			}
			return crearMapa(mapa->mapa_p2);

		}
		else {
			if (mapa->mapa_p3 == nullptr) {
				mapa->mapa_p3 = gcnew Mapa();
				mapa->mapa_p3->mapa_p1 = mapa;
				return mapa->mapa_p3;
			}
			return crearMapa(mapa->mapa_p2);

		}

	}
}