#include "../../include/habilidad.h"


Habilidad::Habilidad(std::string nombre, std::string descripcion, int usosTotales) {

	setNombre(nombre);
	setDescripcion(descripcion);
	setUsosRestantes(usosTotales);
	setUsosTotales(usosTotales);
}

// Getters
std::string Habilidad::getNombre()        { return nombre; }
std::string Habilidad::getDescripcion()   { return descripcion; }
int         Habilidad::getUsosRestantes() { return usosRestantes; }
int         Habilidad::getUsosTotales()   { return usosTotales; }

// Setters
void Habilidad::setNombre(std::string _nombre)           { nombre = _nombre; }
void Habilidad::setDescripcion(std::string _descripcion) { descripcion = _descripcion; }
void Habilidad::setUsosRestantes(int _usosRestantes)     { usosRestantes = _usosRestantes; }
void Habilidad::setUsosTotales(int _usosTotales)         { usosTotales = _usosTotales; }

