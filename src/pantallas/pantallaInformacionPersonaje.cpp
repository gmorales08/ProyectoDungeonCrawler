#include "../../include/pantallaInformacionPersonaje.h"


std::string pantallaInformacion(Jugador jugador) {

	std::string pantallaInformacion = "";

	pantallaInformacion.append("┌─────────────────────────────────────────────────────────────────────────────┐\n");
	pantallaInformacion.append(centrarTexto("INFORMACION DEL PERSONAJE", ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto("", ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto(jugador.getNombre(), ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto("", ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto(jugador.getRazaString() + ", " + jugador.getClaseString() + ", " + jugador.getSubClaseString(), ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto("", ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto("Arma: " + jugador.getArmaString() + ", Elemento: " + jugador.getElementoString() , ANCHOPANTALLA + 22) + "\n"); //Se anade 22 espacios al ancho de pantalla para que calcule correctamente el ancho al anadir informacion del color a la cadena de texto (metodo imprimirColor de utlidadesTerminal)
	pantallaInformacion.append(centrarTexto("", ANCHOPANTALLA) + "\n");
	pantallaInformacion.append(centrarTexto("Atributos: ", (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto("Habilidades: ", (ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");
	pantallaInformacion.append(centrarTexto("", ANCHOPANTALLA) + "\n");
	
	pantallaInformacion.append(centrarTexto("Vida: " + std::to_string(jugador.getVida()) + "/" + std::to_string(jugador.getVidaMaxima()), (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(
				jugador.getHabilidades().at(0).getNombre() + 
				". Usos (" + std::to_string(jugador.getHabilidades().at(0).getUsosRestantes()) + "/" + 
				std::to_string(jugador.getHabilidades().at(0).getUsosTotales()) + ") ", 
				(ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");
	
	pantallaInformacion.append(centrarTexto("Ataque: " + std::to_string(jugador.getAtaqueFisico()), (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(
				jugador.getHabilidades().at(1).getNombre() + 
				". Usos (" + std::to_string(jugador.getHabilidades().at(1).getUsosRestantes()) + "/" + 
				std::to_string(jugador.getHabilidades().at(1).getUsosTotales()) + ") ", 
				(ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("Ataque magico: " + std::to_string(jugador.getAtaqueMagico()), (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(jugador.getHabilidades().at(1).getDescripcion() + " " , (ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("Defensa: " + std::to_string(jugador.getDefensaFisica()), (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(
				jugador.getHabilidades().at(2).getNombre() + 
				". Usos (" + std::to_string(jugador.getHabilidades().at(2).getUsosRestantes()) + "/" + 
				std::to_string(jugador.getHabilidades().at(2).getUsosTotales()) + ") ", 
				(ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("Defensa magica: " + std::to_string(jugador.getDefensaMagica()), (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(jugador.getHabilidades().at(2).getDescripcion() + " " , (ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("Precision: " + std::to_string(jugador.getPrecision()) + "%", (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(
				jugador.getHabilidades().at(3).getNombre() + 
				". Usos (" + std::to_string(jugador.getHabilidades().at(3).getUsosRestantes()) + "/" + 
				std::to_string(jugador.getHabilidades().at(3).getUsosTotales()) + ") ", 
				(ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("Critico: " + std::to_string(jugador.getCritico()) + "%", (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(jugador.getHabilidades().at(3).getDescripcion() + " " , (ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("", (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(
				jugador.getHabilidades().at(4).getNombre() + 
				". Usos (" + std::to_string(jugador.getHabilidades().at(4).getUsosRestantes()) + "/" + 
				std::to_string(jugador.getHabilidades().at(4).getUsosTotales()) + ") ", 
				(ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("", (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(jugador.getHabilidades().at(4).getDescripcion() + " " , (ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append(centrarTexto("", (ANCHOPANTALLA + 1) / 2, TUBERIA, " "));
	pantallaInformacion.append(centrarTexto(
				jugador.getHabilidades().at(5).getNombre() + 
				". Usos (" + std::to_string(jugador.getHabilidades().at(5).getUsosRestantes()) + "/" + 
				std::to_string(jugador.getHabilidades().at(5).getUsosTotales()) + ") ", 
				(ANCHOPANTALLA + 1) / 2, "", TUBERIA) + "\n");

	pantallaInformacion.append("└─────────────────────────────────────────────────────────────────────────────┘\n");


	return pantallaInformacion;
}
