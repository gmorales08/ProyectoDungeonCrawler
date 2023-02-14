#ifndef ENEMIGO
#define ENEMIGO

#include <vector>
#include "personaje.hpp"
#include "habilidad.hpp"

/*
 * CLASE ENEMIGO
 *
 * Hereda de Personaje y contiene metodos y atributos de los enemigos generados
 * por la CPU.
 */
class Enemigo : public Personaje {
public:
    Enemigo(std::string nombre, int nivel, Personaje::Elemento elemento);

    std::vector<Habilidad> getHabilidades();
    void setHabilidades(std::vector<Habilidad> habilidades);

    /* 
     * Los atributos de los enemigos se generan de manera aleatoria en base a 
     * su nivel.
     * Se simula la asignacion aleatoria de atributos y la subida de x niveles 
     * como si de un jugador se tratase
     */
    void generarAtributos(int nivel);

private:
    std::vector<Habilidad> habilidades;
};

#endif // ENEMIGO
