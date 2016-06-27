#include "MapaArbol.h"

MapaArbol::MapaArbol()
{
	Raiz = nullptr;

}
MapaArbol::~MapaArbol()
{

}

void MapaArbol::Insertar_raiz(int ValorDelMapa){
	if (Raiz == nullptr){
		Raiz = new MapaNodo();
		Raiz->set_dato(ValorDelMapa);
	}
}

MapaNodo * MapaArbol::Devolver_Raiz()
{
	return this->Raiz;
}

MapaNodo * MapaArbol::Posicionar_MapaNodo(MapaNodo * objMapa, int ValorDelMapa){
	if (objMapa->get_dato() < ValorDelMapa && objMapa->get_der() == nullptr){
		objMapa->set_der(new MapaNodo());
		return objMapa->get_der();
	}
	else if (objMapa->get_dato() > ValorDelMapa && objMapa->get_izq() == nullptr){
		objMapa->set_izq(new MapaNodo());
		return objMapa->get_izq();
	}
	else {

		if (ValorDelMapa > objMapa->get_dato())
			return Posicionar_MapaNodo(objMapa->get_der(), ValorDelMapa);
		else
			return Posicionar_MapaNodo(objMapa->get_izq(), ValorDelMapa);
	}
}

void MapaArbol::Insertar_MapaNodo(int ValorDelMapa){
	MapaNodo * objMapa = Posicionar_MapaNodo(Raiz, ValorDelMapa);
	if (objMapa != nullptr){
		objMapa->set_dato(ValorDelMapa);
	}
}








