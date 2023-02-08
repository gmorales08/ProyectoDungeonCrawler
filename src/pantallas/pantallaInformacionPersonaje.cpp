#include <algorithm>
#include "../../include/pantallaInformacionPersonaje.hpp"


std::string pantallaInformacion(Jugador& jugador) {
    std::string pantallaInformacion = "";
    pantallaInformacion.append(
    "┌─────────────────────────────────────────────────────────────────────────────┐\n");
    pantallaInformacion.append(centrarTexto("INFORMACION DEL PERSONAJE",
                                            anchoPantalla) + "\n");
    pantallaInformacion.append(centrarTexto("", anchoPantalla) + "\n");
    std::string infoJugador = jugador.getNombre() + ". " +
        jugador.getRazaString() + ", " + jugador.getClaseString() + ", " +
        jugador.getSubclaseString() + ".";
    std::transform(infoJugador.begin(), infoJugador.end(), infoJugador.begin(),
        ::toupper);
    pantallaInformacion.append(centrarTexto(infoJugador, anchoPantalla) +
        "\n");
    pantallaInformacion.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaInformacion.append(centrarTexto("Arma: " + jugador.getArmaString()
        + ", Elemento: " + jugador.getElementoString(), anchoPantalla + 10) +
        "\n");
    /* Se anade 22 espacios al ancho de pantalla para que calcule correctamente
     * el ancho al anadir informacion del color a la cadena de texto (metodo
     * imprimirColor de utlidadesTerminal)
     */
    pantallaInformacion.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaInformacion.append(centrarTexto("Atributos: ",
                                            (anchoPantalla + 1) / 2,
                                            tuberia, " "));
    pantallaInformacion.append(centrarTexto("Habilidades: ",
                                            (anchoPantalla + 1) / 2,
                                            "", tuberia) + "\n");
    pantallaInformacion.append(centrarTexto("", anchoPantalla) + "\n");

    pantallaInformacion.append(centrarTexto("Vida: " +
        std::to_string(jugador.getVida()) + "/" +
        std::to_string(jugador.getVidaMaxima()),
                                            (anchoPantalla + 1) / 2,
                                            tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(0).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(0).getUsosRestantes()) + "/"
        + std::to_string(jugador.getHabilidades().at(0).getUsosTotales()) +
        ") ",
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Ataque: " + std::to_string(jugador.getAtaqueFisico()),
        (anchoPantalla + 1) / 2,
        tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(1).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(1).getUsosRestantes()) + "/"
        + std::to_string(jugador.getHabilidades().at(1).getUsosTotales()) +
        ") ",
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Ataque magico: " + std::to_string(jugador.getAtaqueMagico()),
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(1).getDescripcion() + " " ,
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Defensa: " + std::to_string(jugador.getDefensaFisica()),
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(2).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(2).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(2).getUsosTotales()) +
        ") ",
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Defensa magica: " + std::to_string(jugador.getDefensaMagica()),
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(2).getDescripcion() + " " ,
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Velocidad: " + std::to_string(jugador.getVelocidad()),
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(3).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(3).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(3).getUsosTotales()) +
        ") ",
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Evasion: " + std::to_string(jugador.getEvasion()) + "%",
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(3).getDescripcion() + " " ,
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Precision: " + std::to_string(jugador.getPrecision()) + "%",
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(4).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(4).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(4).getUsosTotales()) +
        ") ",
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");

    pantallaInformacion.append(centrarTexto(
        "Critico: " + std::to_string(jugador.getCritico()) + "%",
        (anchoPantalla + 1) / 2, tuberia, " "));
    pantallaInformacion.append(centrarTexto(
        jugador.getHabilidades().at(4).getDescripcion() + " " ,
        (anchoPantalla + 1) / 2, "", tuberia) + "\n");
    pantallaInformacion.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaInformacion.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaInformacion.append(
    "└─────────────────────────────────────────────────────────────────────────────┘\n");

    return pantallaInformacion;
}
