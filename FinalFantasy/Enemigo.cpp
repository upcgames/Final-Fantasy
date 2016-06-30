#include "Enemigo.h"
#include "Imagenes.h"
#include "Juego.h"
#include "Marco.h"

namespace FinalFantasy {

	Enemigo::Enemigo() {
		sprite = gcnew Sprite(IMAGENES::ENEMIGO_SPRITE);
		sprite->indice = 0;
		sprite->ancho = 48;
		sprite->alto = 48;
		sprite->frecuencia = 2;
		sprite->numero_de_columnas = 8;
		sprite->numero_de_filas = 6;

		direccion = Direccion::Izquierda;
		velocidad = Juego::aleatorio->Next(4) * 2;
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
		velocidad = Juego::aleatorio->Next(4) * 2 + 2;
		ancho = RESOLUCION_X;
		alto = RESOLUCION_Y;
	}

	void Enemigo::avanzarUnPaso() { 

		if (posicion->y > Marco::marco->posicion->y)
			posicion->y -= velocidad;
		else if (posicion->y != Marco::marco->posicion->y)
			posicion->y += velocidad;
		
		if (posicion->x > Marco::marco->posicion->x) {
			posicion->x -= velocidad;
			direccion = Izquierda;
		}
		else if (posicion->x != Marco::marco->posicion->x) {
			posicion->x += velocidad;
			direccion = Derecha;
		}
		else {

			if (posicion->y > Marco::marco->posicion->y) {
				direccion = Arriba;
			}
			else if (posicion->y != Marco::marco->posicion->y) {
				direccion = Abajo;
			}

		}

		sprite->siguienteIndice();

	}

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

		if (!muriendo)
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

		avanzarUnPaso();

		if (muriendo && sprite->indice == 0)
			Mapa::mapa_actual->enemigos_en_mapa->Remove(this);
	}

	void Enemigo::Morir() {
		muriendo = true;
		velocidad = -1;
		sprite->frecuencia = 4;
		sprite->indice = 1;
		sprite->subindice = 5;

		if (enemigo_derecho != nullptr){
			if (direccion == Izquierda)
				enemigo_derecho->posicion = gcnew Posicion(posicion->x + RESOLUCION_X / 2, posicion->y - RESOLUCION_Y / 2);
			else if (direccion == Derecha)
				enemigo_derecho->posicion = gcnew Posicion(posicion->x - RESOLUCION_X / 2, posicion->y + RESOLUCION_Y / 2);
			else if (direccion == Arriba)
				enemigo_derecho->posicion = gcnew Posicion(posicion->x + RESOLUCION_X / 2, posicion->y + RESOLUCION_Y / 2);
			else if (direccion == Abajo)
				enemigo_derecho->posicion = gcnew Posicion(posicion->x - RESOLUCION_X / 2, posicion->y - RESOLUCION_Y / 2);

			Mapa::mapa_actual->enemigos_en_mapa->Add(enemigo_derecho);
		}
		if (enemigo_izquierdo != nullptr){
			if (direccion == Izquierda)
				enemigo_izquierdo->posicion = gcnew Posicion(posicion->x + RESOLUCION_X / 2, posicion->y + RESOLUCION_Y / 2);
			else if (direccion == Derecha)
				enemigo_izquierdo->posicion = gcnew Posicion(posicion->x - RESOLUCION_X / 2, posicion->y + RESOLUCION_Y / 2);
			else if (direccion == Arriba)
				enemigo_izquierdo->posicion = gcnew Posicion(posicion->x - RESOLUCION_X / 2, posicion->y + RESOLUCION_Y / 2);
			else if (direccion == Abajo)
				enemigo_izquierdo->posicion = gcnew Posicion(posicion->x + RESOLUCION_X / 2, posicion->y - RESOLUCION_Y / 2);

			Mapa::mapa_actual->enemigos_en_mapa->Add(enemigo_izquierdo);
		}
	}

}