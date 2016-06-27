#pragma once
#include "MapaNodo.h"

using namespace std;

class MapaArbol
{
private:
	MapaNodo * Raiz;

public:

	MapaArbol();
	~MapaArbol();

	void Insertar_raiz(int ValorDelMapaNodo);
	MapaNodo * Devolver_Raiz();
	MapaNodo * Posicionar_MapaNodo(MapaNodo * objMapaNodo, int ValorDelMapaNodo);

	void Insertar_MapaNodo(int ValorDelMapaNodo);

};