#include "MapaNodo.h"

MapaNodo::MapaNodo()
{
	izq = nullptr;
	der = nullptr;
	padre = nullptr;
	dato = 0;
}
MapaNodo::~MapaNodo(){

}

void MapaNodo::set_izq(MapaNodo* izq){

	this->izq = izq;
}
void MapaNodo::set_der(MapaNodo* der){

	this->der = der;
}
void MapaNodo::set_padre(MapaNodo* padre){

	this->padre = padre;
}
void MapaNodo::set_dato(int dato){

	this->dato = dato;
}

MapaNodo* MapaNodo::get_izq(){
	return this->izq;
}
MapaNodo* MapaNodo::get_der(){
	return this->der;
}
MapaNodo* MapaNodo::get_padre(){
	return this->padre;
}
int MapaNodo::get_dato(){
	return this->dato;
}