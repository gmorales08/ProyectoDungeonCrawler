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

	// Getters
	std::string getNombre();
	int getVida();
	int getAtaqueFisico();
	int getAtaqueMagico();
	int getDefensaFisica();
	int getDefensaMagica();
	int getVelocidad();
	int getPrecision();
	int getCritico();

	// Setters
	void setVida(int vida);
	void setAtaqueFisico(int ataqueFisico);
	void setAtaqueMagico(int ataqueMagico);
	void setDefensaFisica(int defensaFisica);
	void setDefensaMagica(int defensaMagica);
	void setVelocidad(int velocidad);
	void setPrecision(int precision);
	void setCritico(int critico);

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
