#ifndef HABILIDAD
#define HABILIDAD

#include "personaje.hpp"
#include <iostream>

/*
 * CLASE HABILIDAD
 *
 * Clase que contiene informacion sobre las habilidades que usan los personajes
 */
class Habilidad {
public:

    enum class Tipo {
        OFENSIVA,
        BUFF,
        DEBUFF,
        CURATIVA,
        MAGIA
    };

    enum class Atributo {
        ATAQUE,
        ATAQUE_MAGICO,
        ATAQUES,  // Ataque y ataque magico
        DEFENSAS, // Defensa y defensa magica
        VELOCIDAD_Y_EVASION,
        PRECISION_Y_CRITICO
    };

    /*
     * CONTRUCTOR
     *
     * Se le indica el nombre, la descripcion y el tipo.
     * Tambien se le indica el valor de ataque/curacion/buff/debuff.
     * Este constructor se usa para habilidades curativas.
     */
    Habilidad (std::string nombre, std::string descripcion, Tipo tipo,
               int valor);
    /*
     * Constructor alternativo para habilidades tipo ofensivas y buff/debuff
     * donde se le indica el atributo que se esta modificando o si se esta
     * usando ataque fisico o magico
     */
    Habilidad (std::string nombre, std::string descripcion, Tipo tipo,
               Atributo atributo, int valor);
    /*
     * Constructor alternativo para crear las magias
     * Se indica el elemento de la magia como parametro adicional
     */
    Habilidad (std::string nombre, std::string descripcion, Tipo tipo,
               Personaje::Elemento elemento);

    /* Getters */
    std::string getNombre();
    std::string getDescripcion();
    Personaje::Elemento getElemento();
    int         getUsosRestantes();
    int         getUsosTotales();

    /* Setters */
    void setNombre(std::string _nombre);
    void setDescripcion(std::string _descripcion);
    void setUsosRestantes(int _usosRestantes);
    void setUsosTotales(int _usosTotales);

    /*
     * USAR
     *
     * Activa el efecto de la habilidad y devuelve un mensaje que se podra
     * imprimir como log.
     * Ej: cura a personaje, potencia a personaje o ataca a personaje.
     */
    std::string usar();

private:
    std::string nombre;
    std::string descripcion;
    Tipo        tipo;
    Atributo    atributo;
    /*
     * VALOR
     * Dependiendo del tipo de habilidad se usara de manera diferente.
     * Indica el numero de dados tirados para determinar el valor:
     *  - Ofensiva. Posibles valores:
     *    - 2 : se tiran 2 dados y se ataca con el mejor * 5.
     *    - 3 : se tiran 3 dados y se ataca con los dos mejores * 5;
     *  - Buff/Debuff. Posibles valores:
     *    - 2 : se tiran 2 dados y se mejora el mejor al atributo.
     *    - 3 : se tiran 3 dados y se mejora los 2 mejores al atributo.
     *  - Curativa. Posibles valores:
     *    - 2 : se tiran 2 dados y se cura el mejor * 10.
     *    - 3 : se tiran 3 dados y se curan los dos mejores * 10.
     */
    Personaje::Elemento elemento;
    int         valor;
    Personaje   objetivo;
    int         usosRestantes;
    int         usosTotales;

    /* Getters privados
     * Los voy a utilizar para el metodo usar();
     */
    Tipo        getTipo();
    Atributo    getAtributo();
    int         getValor();
    Personaje   getObjetivo();
    /* Setters privados */
    void        setTipo(Tipo tipo);
    void        setAtributo(Atributo atributo);
    void        setElemento(Personaje::Elemento elemento);
    void        setValor(int valor);
    void        setObjetivo(Personaje& objetivo);
};

#endif // HABILIDAD
