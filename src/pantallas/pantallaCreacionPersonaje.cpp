#include "../../include/pantallaCreacionPersonaje.h"


std::string seleccionActual = "";
std::vector<int> seleccionActualNumerica = {0, 0, 0}; 
std::string mensajeLog = "";
bool raza = false, clase = false, subclase = false;


void menuCreacionPersonaje(std::string opcion) {

	if (opcion == "1") {
	
		if (!raza) 	{

			seleccionActual += "Humano, ";
			seleccionActualNumerica[0] = 1;
			mensajeLog = "Elija una clase (1-6)";
			raza = true;

		} else if (!clase) {

			seleccionActual += "Guerrero, ";
			seleccionActualNumerica[1] = 1;
			mensajeLog = "Elija una subclase (1-6)";
			clase = true;

		} else if (!subclase) {
			
			seleccionActual += "Herrero.";
			seleccionActualNumerica[2] = 1;
			mensajeLog = "Es correcta su seleccion? (s/n)";
			subclase = true;
		}

	} else if (opcion == "2") {

		if (!raza) 	{

			seleccionActual += "Enano, ";
			seleccionActualNumerica[0] = 2;
			mensajeLog = "Elija una clase (1-6)";
			raza = true;

		} else if (!clase) {

			seleccionActual += "Mago, ";
			seleccionActualNumerica[1] = 2;
			mensajeLog = "Elija una subclase (1-6)";
			clase = true;

		} else if (!subclase) {
			
			seleccionActual += "Alquimista.";
			seleccionActualNumerica[2] = 2;
			mensajeLog = "Es correcta su seleccion? (s/n)";
			subclase = true;
		}

	} else if (opcion == "3") {

		if (!raza) 	{

			seleccionActual += "Elfo, ";
			seleccionActualNumerica[0] = 3;
			mensajeLog = "Elija una clase (1-6)";
			raza = true;

		} else if (!clase) {

			seleccionActual += "Monje, ";
			seleccionActualNumerica[1] = 3;
			mensajeLog = "Elija una subclase (1-6)";
			clase = true;

		} else if (!subclase) {
			
			seleccionActual += "Gladiador.";
			seleccionActualNumerica[2] = 3;
			mensajeLog = "Es correcta su seleccion? (s/n)";
			subclase = true;
		}

	} else if (opcion == "4") {

		if (!raza) 	{

			seleccionActual += "Ogro, ";
			seleccionActualNumerica[0] = 4;
			mensajeLog = "Elija una clase (1-6)";
			raza = true;

		} else if (!clase) {

			seleccionActual += "Clerigo, ";
			seleccionActualNumerica[1] = 4;
			mensajeLog = "Elija una subclase (1-6)";
			clase = true;

		} else if (!subclase) {
			
			seleccionActual += "Boticario.";
			seleccionActualNumerica[2] = 4;
			mensajeLog = "Es correcta su seleccion? (s/n)";
			subclase = true;
		}

	} else if (opcion == "5") {
	
		if (!raza) 	{

			seleccionActual += "Triton, ";
			seleccionActualNumerica[0] = 5;
			mensajeLog = "Elija una clase (1-6)";
			raza = true;

		} else if (!clase) {

			seleccionActual += "Ladron, ";
			seleccionActualNumerica[1] = 5;
			mensajeLog = "Elija una subclase (1-6)";
			clase = true;

		} else if (!subclase) {
			
			seleccionActual += "Druida.";
			seleccionActualNumerica[2] = 5;
			mensajeLog = "Es correcta su seleccion? (s/n)";
			subclase = true;
		}

	} else if (opcion == "6") {

		if (!raza) 	{

			seleccionActual += "Licantropo, ";
			seleccionActualNumerica[0] = 6;
			mensajeLog = "Elija una clase (1-6)";
			raza = true;

		} else if (!clase) {

			seleccionActual += "Trovador, ";
			seleccionActualNumerica[1] = 6;
			mensajeLog = "Elija una subclase (1-6)";
			clase = true;

		} else if (!subclase) {
			
			seleccionActual += "Mercenario.";
			seleccionActualNumerica[2] = 6;
			mensajeLog = "Es correcta su seleccion? (s/n)";
			subclase = true;
		}

	}

	if (raza & clase & subclase) {
		
		if (opcion == "s" || opcion == "S") {

			std::string nombrePersonaje = cargarPantalla(canvasCreacionPersonaje, "Introduzca el nombre del personaje\n");
				
			//Pasar por parametro a otra pantalla los valores del personaje, para crearlo en la siguiente pantalla, no esta

		} else if (opcion == "n" || opcion == "N") {

			seleccionActual = "";
			mensajeLog = "";
			raza = false, clase = false, subclase = false;
			
			menuCreacionPersonaje(cargarPantalla(canvasCreacionPersonaje, opcionesCreacionPersonaje, imprimirLog(0, "Seleccion actual: ", "Selecione una raza (1-6) "),
					"Seleccion actual: \nDebe escribir un numero del 1 al 6"));

		} else {

			menuCreacionPersonaje(cargarPantalla(canvasCreacionPersonaje, {"s", "S", "n", "N"}, 
				imprimirLog(0, "Seleccion actual: " + seleccionActual, mensajeLog),
				"Seleccion actual: " + seleccionActual + "\nEs correcta su seleccion? Debe escribir s o n"));
		}	

	} else {

	menuCreacionPersonaje(cargarPantalla(canvasCreacionPersonaje, opcionesCreacionPersonaje, 
				imprimirLog(0, "Seleccion actual: " + seleccionActual, mensajeLog),
				"Seleccion actual: " + seleccionActual + "\nDebe escribir un numero del 1 al 6"));

	}
}
