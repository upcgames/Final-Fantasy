#pragma once

#include "Controles.h"
#include "MapaEscena.h"
#include "Marco.h"
#include "Mapa.h"
#include "Juego.h"

namespace FinalFantasy {

	MapaEscena::MapaEscena() {
		Marco::marco = gcnew Marco(gcnew Posicion(0, 0));
		onTimerTick = gcnew EventHandler(this, &MapaEscena::timerTick);
		onKeyDown = gcnew KeyEventHandler(this, &MapaEscena::teclaDown);
		onKeyUp = gcnew KeyEventHandler(this, &MapaEscena::teclaUp);
		onMouseClick = gcnew MouseEventHandler(this, &MapaEscena::mouseClick);
		onMouseMove = gcnew MouseEventHandler(this, &MapaEscena::mouseMove);

		Marco::marco = gcnew Marco(gcnew Posicion(9, 7, true));

		Mapa::mapa_actual = Juego::cabeza;
	}

	void MapaEscena::timerTick(System::Object^  sender, System::EventArgs^  e) {
		if (escena_activa) {
			contador_timer++;

			if (Marco::marco->debe_avanzar)
				Marco::marco->intentarAvanzar(Marco::marco->direccion);

			Mapa::mapa_actual->mostrarTerreno(escena_buffer->Graphics);
			Mapa::mapa_actual->mostrarObjetos(escena_buffer->Graphics);
			Mapa::mapa_actual->mostrarPuertas(escena_buffer->Graphics);
			Mapa::mapa_actual->mostrarEnemigos(escena_buffer->Graphics);
			Marco::mostrarloEn(escena_buffer->Graphics);
			void mostrarPuertas(Graphics ^graphics);

			escena_buffer->Render(Juego::graphics);
			escena_dibujada = true;
		}
	}

	void MapaEscena::teclaDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (escena_activa && escena_dibujada) {
			if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Arriba;
			}
			else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Abajo;
			}
			else if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Izquierda;
			}
			else if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
				Marco::marco->debe_avanzar = true;
				Marco::marco->direccion = Derecha;
			}
		}
	}

	void MapaEscena::teclaUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if ((e->KeyCode == CONTROLES::MOVER_ARRIBA_1 || e->KeyCode == CONTROLES::MOVER_ARRIBA_2) && Marco::marco->direccion == Arriba)
			Marco::marco->Detener();
		else if ((e->KeyCode == CONTROLES::MOVER_ABAJO_1 || e->KeyCode == CONTROLES::MOVER_ABAJO_2) && Marco::marco->direccion == Abajo)
			Marco::marco->Detener();
		else if ((e->KeyCode == CONTROLES::MOVER_IZQUIERDA_1 || e->KeyCode == CONTROLES::MOVER_IZQUIERDA_2) && Marco::marco->direccion == Izquierda)
			Marco::marco->Detener();
		else if ((e->KeyCode == CONTROLES::MOVER_DERECHA_1 || e->KeyCode == CONTROLES::MOVER_DERECHA_2) && Marco::marco->direccion == Derecha)
			Marco::marco->Detener();
	}

	void MapaEscena::mouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Posicion ^posicion_mouse = gcnew Posicion(e->X, e->Y);

		for (int i = 0; i < Mapa::mapa_actual->enemigos_en_mapa->Count; i++) {
			Enemigo ^enemigo = Mapa::mapa_actual->enemigos_en_mapa[i];
			
			if (posicion_mouse->chocaCon(enemigo->posicion->getCuerpo())) {
				enemigo->vida -= 1;
				if (enemigo->vida == 0)
					enemigo->Morir();
				return;
			}
		}
				

		if (e->Button == MouseButtons::Right) {
			Marco::marco->posicion->x = (posicion_mouse->x / RESOLUCION_X) * RESOLUCION_X;;
			Marco::marco->posicion->y = (posicion_mouse->y / RESOLUCION_Y) * RESOLUCION_Y;;
		}

	}

	void MapaEscena::mouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int x = e->X - Marco::marco->posicion->x;
		int y = e->Y - Marco::marco->posicion->y;

		float m = x != 0 ? (Math::Abs((float)y / x)) : 2;

		if (x >= 0 && y > 0) {
			if (m < 1)
				Marco::marco->direccion_arma = Derecha;
			else
				Marco::marco->direccion_arma = Abajo;
		}
		else if (x < 0 && y >= 0) {
			if (m < 1)
				Marco::marco->direccion_arma = Izquierda;
			else
				Marco::marco->direccion_arma = Abajo;
		}
		else if (x <= 0 && y < 0) {
			if (m < 1)
				Marco::marco->direccion_arma = Izquierda;
			else
				Marco::marco->direccion_arma = Arriba;
		}
		else {
			if (m < 1)
				Marco::marco->direccion_arma = Derecha;
			else
				Marco::marco->direccion_arma = Arriba;
		}


	}
}