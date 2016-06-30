#include "Enemigo.h"
#include "Imagenes.h"
#include "Juego.h"

namespace FinalFantasy {

	Enemigo::Enemigo() {
		sprite = gcnew Sprite(IMAGENES::ENEMIGO_SPRITE);
		sprite->indice = 0;
		sprite->ancho = 48;
		sprite->alto = 48;
		sprite->frecuencia = 2;
		sprite->numero_de_columnas = 8;
		sprite->numero_de_filas = 6;

		direccion = Direccion::Abajo;
		velocidad = 8;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
	}
	Enemigo::Enemigo(Posicion ^p) {
		posicion = p;
		sprite = gcnew Sprite(IMAGENES::ENEMIGO_SPRITE);
		sprite->indice = 0;
		sprite->ancho = 48;
		sprite->alto = 48;
		sprite->frecuencia = 2;
		sprite->numero_de_columnas = 8;
		sprite->numero_de_filas = 6;

		direccion = Direccion::Abajo;
		velocidad = 8;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
	}

	void Enemigo::avanzarUnPaso() { ; }

	void Enemigo::crearEnemigo(Enemigo^ enemigo) {

		if (Juego::aleatorio->Next(2)) {
			if (enemigo->enemigo_derecho == nullptr) {
				enemigo->enemigo_derecho = gcnew Enemigo();
				enemigo->enemigo_derecho->enemigo_padre = enemigo;
				return;
			}
			crearEnemigo(enemigo->enemigo_derecho);
		}
		else {
			if (enemigo->enemigo_izquierdo == nullptr) {
				enemigo->enemigo_izquierdo = gcnew Enemigo();
				enemigo->enemigo_izquierdo->enemigo_padre = enemigo;
				return;
			}
			crearEnemigo(enemigo->enemigo_izquierdo);
		}
	}

	void Enemigo::Mostrar(Graphics^ graphics) {

		sprite->cambiarSubindice((int)direccion);

		graphics->DrawImage(
			sprite->imagen,
			Rectangle(
			sprite->ancho - sprite->ancho + posicion->x,
			alto - sprite->alto + posicion->y,
			sprite->ancho,
			sprite->alto
			),
			Rectangle(
			sprite->indice / sprite->frecuencia * sprite->ancho,
			sprite->subindice * sprite->alto,
			sprite->ancho - 1, // Normalemnte no se deberia quitar uno
			sprite->alto - 1 // Pero, se pinta un pixel mas
			),
			GraphicsUnit::Pixel
			);
	}

}