#pragma once

class MapaNodo
{
private:
	MapaNodo* izq;
	MapaNodo* der;
	MapaNodo* padre;
	int dato;

public:
	MapaNodo();
	~MapaNodo();

	void set_izq(MapaNodo* izq);
	void set_der(MapaNodo* der);
	void set_padre(MapaNodo* padre);
	void set_dato(int dato);

	MapaNodo* get_izq();
	MapaNodo* get_der();
	MapaNodo* get_padre();
	int get_dato();

};