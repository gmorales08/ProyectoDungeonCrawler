#ifndef PERSONAJE
#define PERSONAJE


#include <iostream>


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

protected:

	std::string nombre;
	int vida;
	int ataqueFisico;
	int ataqueMagico;
	int defensaFisica;
	int defensaMagica;
	int velocidad;
	int precision;
	int critico;
	Elemento elemento;
	

	// TIRAR DADOS
	//
	// Metodo que simula la tirada de x dados y suma su puntuacion
	// El numero de dados se pasa por parametro
	//
	int tirarDados(int numeroDeDados);
};

#endif //PERSONAJE
