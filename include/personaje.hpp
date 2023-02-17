#ifndef PERSONAJE
#define PERSONAJE

#include <iostream>
#include <vector>

/*
 * CLASE PERSONAJE
 *
 * Clase padre de las clases Jugador y Enemigo que contiene atributos y metodos
 * comunes
 */

/*
 * PERSONAJE
 *
 * Clase que va a contener toda la informacion del personaje creado
 */
class Personaje {
public:
    /*
    * ENUMERADO ELEMENTO
    *
    * Se utiliza para saber el elemento del personaje
    */
    enum class Elemento {
        NEUTRO,
        FUEGO,
        HIELO,
        TIERRA,
        RAYO,
        AGUA
    };

    /* El constructor vacio lo creo porque en Habilidad tengo que pasar como
     * parametro un personaje todavia no creado
     */
    Personaje ();
    /* Para jugador */
    Personaje (std::string nombre);
    /* Para enemigo */
    Personaje (std::string nombre, int nivel, Elemento elemento);

    /* Getters */
    std::string getNombre();
    int getVida();
    int getVidaMaxima();
    int getAtaqueFisico();
    int getAtaqueMagico();
    int getDefensaFisica();
    int getDefensaMagica();
    int getVelocidad();
    int getEvasion();
    int getPrecision();
    int getCritico();
    int getNivel();
    Elemento getElemento();

    /* GETTERS TO_STRING
    *
    * Se usaran para imprimir informacion del personaje en pantalla
    */
    std::string getElementoString();

    /* Setters */
    void setNombre(std::string nombre);
    void setVida(int vida);
    void setVidaMaxima(int vida);
    void setAtaqueFisico(int ataqueFisico);
    void setAtaqueMagico(int ataqueMagico);
    void setDefensaFisica(int defensaFisica);
    void setDefensaMagica(int defensaMagica);
    void setVelocidad(int velocidad);
    void setEvasion(int evasion);
    void setPrecision(int precision);
    void setCritico(int critico);
    void setNivel(int nivel);
    void setElemento(Elemento elemento);

    /*
     * MODIFICAR_ATRIBUTOS
     *
     * Aumenta o disminuye los atributos del personaje
     * Para disminuir, pasar un valor negativo.
     */
    void aumentarVida(int vida);
    void aumentarVidaMaxima(int vida);
    void aumentarAtaqueFisico(int ataqueFisico);
    void aumentarAtaqueMagico(int ataqueMagico);
    void aumentarDefensaFisica(int defensaFisica);
    void aumentarDefensaMagica(int defensaMagica);
    void aumentarVelocidad(int velocidad);
    void aumentarEvasion(int evasion);
    void aumentarPrecision(int precision);
    void aumentarCritico(int critico);
    void subirDeNivel();
    /* Aumentar y disminuir atributos se van a usar para aumentar o disminuir
     * todos los atributos 0, 1 o 2 puntos. Estos metodos se usa cada vez que
     * se sube de nivel, y en determinados eventos.
     */
    void aumentarAtributos();
    void disminuirAtributos();

    /* GENERAR_BARRA_DE_VIDA
    *
    * Metodo para imprimir una cadena de caracteres "█" que representan la vida
    * del personaje.
    *
    * Imprime mas o menos caracteres dependiendo de la vida que tenga el
    * personaje respecto a su maximo.
    *
    * Dependiendo del numero de caracteres "█" impresos, los imprime de un
    * determinado color:
    *
    *     - Vida superior al 50%: entre 10 y 20 caracteres "█" de color verde
    *     - Vida entre 25% y 50%: entre 5 y 10 caracteres "█" de color amarillo
    *     - Vida inferior al 25%: hasta 5 caracteres "█" de color rojo
    *
    * Nota: cada "█" representa un 5% de la vida maxima
    */
    std::string generarBarraDeVida();

    /* TIRAR_DADO
	 *
	 * Metodo que simula la tirada de 1 dado y devuelve su puntuacion
     * Sobrecarga: se indica el numero de caras
	 */
	static int tirarDado();
    static int tirarDado(int numeroDeCaras);

    /* TIRAR_DADOS
     *
     * Tira el numero de dados pasado por parametro y devuelve la suma total
     */
    static int tirarDados(int numeroDeDados);

	/* ESCOGER_DADOS
	 *
	 * Metodo que simula la tirada de x dados y devuelve la suma de los tres
     * resultados mas altos.
     *
     * Sobrecarga: se puede indicar el numero de dados que se escogen en la
     * tirada.
	 */
	static int escogerDados(int numeroTiradas);
    static int escogerDados(int numeroTiradas, int dadosAEscoger);
    /* GENERAR_ALEATORIO
     *
     * Genera un numero aleatorio en el rango indicada
     */
    static int generarAleatorio(int inicio, int fin);

protected:
	std::string nombre;
	int vida;
	int vidaMaxima;
	int ataqueFisico;
	int ataqueMagico;
	int defensaFisica;
	int defensaMagica;
	int velocidad;
    int evasion;
	int precision;
	int critico;
    int nivel;
	Elemento elemento;
};

#endif // PERSONAJE
