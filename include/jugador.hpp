#ifndef JUGADOR
#define JUGADOR

#include "personaje.hpp"
#include "habilidad.hpp"

/*
 * CLASE JUGADOR
 *
 * Hereda de la clase personaje y contiene los atributos y metodos del jugador
 * creado
 */
class Jugador : public Personaje {
public:
    Jugador(); // Constructor por defecto para la clase Partida
    Jugador(std::string _nombre, int _raza, int _clase, int _subclase, 
            int _arma);

    /*
     * ENUMERADOS
     *
     * Contienen informacion de la raza, clase, subclase y arma del personaje
     */
    enum class Raza {
        HUMANO = 1,
        ENANO  = 2,
        ELFO   = 3,
        OGRO   = 4,
        TRITON = 5,
        BESTIA = 6
    };

    enum class Clase {
        GUERRERO = 1,
        MAGO     = 2,
        MONJE    = 3,
        CLERIGO  = 4,
        LADRON   = 5,
        TROVADOR = 6
    };

    enum class Subclase {
        HERRERO    = 1,
        ALQUIMISTA = 2,
        GLADIADOR  = 3,
        BOTICARIO  = 4,
        DRUIDA     = 5,
        MERCENARIO = 6
    };

    enum class Arma {
        ESPADA   = 1,
        ESTOQUE  = 2,
        DAGA     = 3,
        MANDOBLE = 4,
        BACULO   = 5,
        HACHA    = 6,
        LANZA    = 7,
        ARCO     = 8,
        MARTILLO = 9,
        GARRAS   = 10
    };

    /* Getters */
    Raza        getRaza();
    Clase       getClase();
    Subclase    getSubclase();
    Arma        getArma();
    std::string getAfinidades();
    std::vector<Habilidad> getHabilidades();
    
    /*
     * GETTER_TO_STRING
     *
     * Se usaran para imprimir informacion del personaje en pantalla
     */
    std::string getRazaString();
    std::string getClaseString();
    std::string getSubclaseString();
    std::string getArmaString();

    /*
     * JUGADOR_LOG
     *
     * Metodo para imprimir en consola la informacion del Jugador
     * Usado para comprobaciones y pruebas
     */
    void jugadorLog();

private:
    Raza        raza;
    Clase       clase;
    Subclase    subclase;
    Arma        arma;
	std::vector<Habilidad> habilidades; // Lista de habilidades del personaje
    std::string afinidades; /* Lista de las armas con las que tiene afinidad
                             * el jugador. Es informativa, para mostrar en la
                             * pantalla de Informacion del Jugador */
    /*
     * OBTENER_ELEMENTO
     *
     * Metodo para obtener el elemento correspondiente a la raza del jugador
     */
    Elemento obtenerElemento();

    /*
     * OBTENER_AFINIDADES
     *
     * Metodo para obtener las armas con las que tiene afinidad el jugador.
     * Devuelve un string con la lista de armas.
     * Se usa en la pantalla Informacion del Jugador.
     */
    std::string obtenerAfinidades(Raza raza, Clase clase, Subclase subclase);

    /*
     * GENERAR_ATRIBUTOS
     *
     * Primero determina el numero de dados que lanzara por cada atributo.
     * Luego tira los dados y asigna el valor a cada atributo.
     * Establce la precision y el porcentaje de critico en base al arma pasada
     * como parametro.
     */
    void generarAtributos(Clase clase, Subclase subclase, Arma arma);

    /*
     * GENERAR_HABILIDADES
     *
     * Genera las habilidades del jugador en base a su raza, clase y subclase.
     */
    void generarHabilidades();
};

#endif // JUGADOR
