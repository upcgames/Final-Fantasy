#pragma once
#include "ObjetoStatico.h"

namespace FinalFantasy {

	ObjetoStatico::ObjetoStatico(Posicion ^posicion) : Objeto(posicion) {
		this->posicion = posicion;
	}
}