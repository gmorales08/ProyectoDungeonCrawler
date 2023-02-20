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
    std::vector<int>       getProbabilidades();
    void setHabilidades(std::vector<Habilidad> habilidades);
    void setProbabilidades(std::vector<int> probabilidades);

    /*
     * Los atributos de los enemigos se generan de manera aleatoria en base a
     * su nivel.
     * Se simula la asignacion aleatoria de atributos y la subida de x niveles
     * como si de un jugador se tratase
     */
    void generarAtributos(int nivel);

    /*
     * ELEGIR_ACCION
     *
     * Determina que accion realizara el Enemigo en base a su vector de
     * probabilidades
     */
    void elegirAccion();

    /*
     * ATACAR
     *
     * Implementacion del metodo polimorfico de la clase Personaje.
     * Sobrecarga:
     *   -Se le indica el valor de ataque. Se usa para habilidades.
     */
    std::string atacar(Personaje& p);
    std::string atacar(Personaje& p, int ataqueFisico);

private:
    std::vector<Habilidad> habilidades;
    /* Probabilidad_Habilidades es un vector que contiene el % de probabilidad
     * que tiene cada habilidad del vector habilidades de ser usada.
     * El primer valor siempre se corresponde con el % de ataque del Enemigo.
     * Ejemplo: probabilidadHabilidades = { 25, 50, 25 }
     *          habilidades             = { h1, h2 }
     *   - Atacar     -> 25%
     *   - Habilidad1 -> 50%
     *   - Habilidad2 -> 25%
     * Para determinar que accion realiza un Enemigo, se tira un dado de 100
     * caras y se determina entre que valor esta comprendido.
     */
    std::vector<int> probabilidadHabilidades;
};

#endif // ENEMIGO
