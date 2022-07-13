#ifndef PERSONAJE
#define PERSONAJE


#include <iostream>


// ENUMERADOS
//
// Se utilizaran para saber la raza, clase, subclase y elemento del personaje
//
enum Raza     {Humano = 1, Enano = 2, Elfo = 3, Ogro = 4, Triton = 5, Licantropo = 6};
enum Clase    {Guerrero = 1, Mago = 2, Monje = 3, Clerigo = 4, Ladron = 5, Trovador = 6};
enum Subclase {Herrero = 1, Alquimista = 2, Gladiador = 3, Boticario = 4, Druida = 5, Mercenario = 6};
enum Elemento {Agua, Fuego, Hielo, Tierra, Rayo, Neutro};

// PERSONAJE
//
// Clase que va a contener toda la informacion del personaje creado
//
class Personaje {

public:

	// CONSTRUCTOR
	//
	// Se le pasa los valores elegidos en pantallaCreacionPersonaje y genera todos los atributos del personaje nuevo.
	//
	Personaje(std::string _nombre, int _raza, int _clase, int _subclase);

private:

	std::string nombre;
	int vida;
	int ataqueFisico;
	int ataqueMagico;
	int defensaFisica;
	int defensaMagica;
	int velocidad;
	int precision;
	int critico;
	Raza raza;
	Clase clase;
	Subclase subclase;
	Elemento elemento;
};






#endif //PERSONAJE
