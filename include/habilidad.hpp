#ifndef HABILIDAD
#define HABILIDAD

#include <iostream>

/*
 * CLASE HABILIDAD
 *
 * Clase que contiene informacion sobre las habilidades que usan los personajes
 */
class Habilidad {
public:
    Habilidad (std::string nombre, std::string descripcion, int usosTotales);

    /* Getters */
    std::string getNombre();
    std::string getDescripcion();
    int         getUsosRestantes();
    int         getUsosTotales();

    /* Setters */
    void setNombre(std::string _nombre);
    void setDescripcion(std::string _descripcion);
    void setUsosRestantes(int _usosRestantes);
    void setUsosTotales(int _usosTotales);

private:
    std::string nombre;
    std::string descripcion;
    int         usosRestantes;
    int         usosTotales;
};

#endif // HABILIDAD
