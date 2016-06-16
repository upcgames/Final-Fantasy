#pragma once
#include "Constantes.h"

namespace FinalFantasy {

	public ref class Posicion {
	public:
		int x;
		int y;

		void igualarA(Posicion ^p);
		void igualarA(int x, int y);
		void Aumentar(Direccion direccion, int velocidad);

		Posicion ^toZero();
		Posicion ^toCoordenadas();

		Rectangle getCuerpo();
		Rectangle getCuerpo(int ancho, int alto);
		Posicion ^getSiguientePosicion(Direccion direccion, int velocidad);
		Posicion ^getPieIzquierdo(Direccion direccion);
		Posicion ^getPieDerecho(Direccion direccion);

		bool chocaCon(Rectangle cuerpo);

		Posicion(int x, int y);
		Posicion(int x, int y, bool multiplicar_automaticamente);

		static bool	operator == (const Posicion ^p1, const Posicion ^p2);
	};
}