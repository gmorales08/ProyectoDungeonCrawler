#ifndef PERSONAJE
#define PERSONAJE


#include <iostream>
#include <vector>
#include "habilidad.h"

// CLASE PERSONAJE
//
// Clase padre de las clases Jugador y Enemigo que contiene atributos y metodos comunes
//


// ENUMERADO ELEMENTO
//
// Se utilizara para saber el elemento del personaje
//
enum Elemento {Agua, Fuego, Hielo, Tierra, Rayo, Neutro};


// PERSONAJE
//
// Clase que va a contener toda la informacion del personaje creado
//
class Personaje {

public:

	// CONSTRUCTOR
	//
	// Contiene el nombre del Jugador o Enemigo que se va a crear
	//
	Personaje(std::string _nombre);

	// Getters
	std::string getNombre();
	int getVida();
	int getVidaMaxima();
	int getAtaqueFisico();
	int getAtaqueMagico();
	int getDefensaFisica();
	int getDefensaMagica();
	int getVelocidad();
	int getPrecision();
	int getCritico();
	Elemento getElemento();
	std::vector<Habilidad> getHabilidades();


	// GETTERS TO_STRING
	//
	// Se usaran para imprimir informacion del personaje en pantalla
	//
	std::string getElementoString();

	// Setters
	void setVida(int vida);
	void setVidaMaxima(int vida);
	void setAtaqueFisico(int ataqueFisico);
	void setAtaqueMagico(int ataqueMagico);
	void setDefensaFisica(int defensaFisica);
	void setDefensaMagica(int defensaMagica);
	void setVelocidad(int velocidad);
	void setPrecision(int precision);
	void setCritico(int critico);

	
	// GENERAR BARRA DE VIDA
	//
	// Metodo para imprimir una cadena de caracteres "█" que representan la vida del personaje.
	//
	// Imprime mas o menos caracteres dependiendo de la vida que tenga el personaje respecto a su maximo.
	// 
	// Dependiendo del numero de caracteres "█" impresos, los imprime de un determinado color:
	//     
	//     - Vida superior al 50%: entre 10 y 20 caracteres "█" de color verde
	//     - Vida entre 25% y 50%: entre 5 y 10 caracteres "█" de color amarillo
	//     - Vida inferior al 25%: hasta 5 caracteres "█" de color rojo
	//
	// Nota: cada "█" representa un 5% de la vida maxima
	//
	std::string generarBarraDeVida();

protected:

	std::string nombre;
	int vida;
	int vidaMaxima;
	int ataqueFisico;
	int ataqueMagico;
	int defensaFisica;
	int defensaMagica;
	int velocidad;
	int precision;
	int critico;
	Elemento elemento;

	std::vector<Habilidad> habilidades; // Lista de las habilidades del personaje

	// TIRAR DADO
	//
	// Metodo que simula la tirada de 1 dado y devuelve su puntuacion
	//
	int tirarDado();

	// ESCOGER DADOS
	//
	// Metodo que simula la tirada de x dados y devuelve la suma de los tres resultados mas altos.
	//
	int escogerDados(int numeroTiradas);

};

#endif //PERSONAJE
