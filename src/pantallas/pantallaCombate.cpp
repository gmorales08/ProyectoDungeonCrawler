#include "../../include/pantallaCombate.hpp"
#include <string>

std::string pantallaCombate(int turno, Jugador& j, Enemigo& e) {
    std::string pantalla = "";
    pantalla.append(
"┌──────────────────────────────────────────────────────────────────────────────┐\n");
    /* Nombre personajes */
    std::string nombreJugador = centrarTexto(j.getNombre(),
                                (anchoPantalla / 2) - 1, " ", " ");
    std::string nombreEnemigo = centrarTexto(e.getNombre(),
                                (anchoPantalla / 2) - 1, " ", " ");
    pantalla.append(tuberia + nombreJugador + nombreEnemigo + tuberia + "\n");
    /* Vida personajes */
    std::string vidaJugador = "    Vida:" + j.generarBarraDeVida();
    vidaJugador += alinearIzquierda(std::to_string(j.getVida()) + "/" +
        std::to_string(j.getVidaMaxima()), 10, " ", " ");
    std::string vidaEnemigo = "    Vida:" + e.generarBarraDeVida();
    vidaEnemigo += alinearIzquierda(std::to_string(e.getVida()) + "/" +
        std::to_string(e.getVidaMaxima()), 10, " ", " ");
    pantalla.append(tuberia + vidaJugador + vidaEnemigo + tuberia + "\n");
    /* Nivel y elemento */
    std::string nivelJugador = "    Nivel " + std::to_string(j.getNivel()) +
        ". Elemento: " + j.getElementoString();
    nivelJugador = alinearIzquierda(nivelJugador, (anchoPantalla / 2) + 10, "", " ");
    std::string nivelEnemigo = "    Nivel " + std::to_string(e.getNivel()) +
        ". Elemento: " + e.getElementoString();
    nivelEnemigo = alinearIzquierda(nivelEnemigo, (anchoPantalla / 2) + 10, "", " ");
    pantalla.append(tuberia + nivelJugador + nivelEnemigo + tuberia + "\n");
    /* Linea en blanco */
    pantalla.append(centrarTexto("", anchoPantalla, tuberia, tuberia + "\n"));
    /* Paneles de comandos, atributos e informacion de la batalla */
    pantalla.append(
"│┌──────────────COMANDOS───────────────┐┌──────────────ATRIBUTOS──────────────┐│\n"
    );
    std::string linea1  = ("│ (a) Atacar                          │");
    std::string linea1a = "Ataque:    ";
    if (j.getAtaqueFisico() < 10) { linea1a += " "; }
    linea1a +=std::to_string(j.getAtaqueFisico());
    linea1a = tuberia + alinearIzquierda(linea1a, 15, " ", " ");
    std::string linea1b = "Ataque magico:   ";
    if (j.getAtaqueMagico() < 10) { linea1b += " "; }
    linea1b += std::to_string(j.getAtaqueMagico());
    linea1b = alinearIzquierda(linea1b, 22, " ", " ") + tuberia;
    linea1 = tuberia + linea1 + linea1a + linea1b + tuberia + "\n";
    pantalla.append(linea1);

    std::string linea2  = ("(1) " + j.getHabilidades().at(0).getNombre());
    linea2 += ". Usos: " + std::to_string(j.getHabilidades().at(0).getUsosRestantes()) + "/" +
              std::to_string(j.getHabilidades().at(0).getUsosTotales());
    linea2 = tuberia + alinearIzquierda(linea2, 37, " ", " ") + tuberia;
    std::string linea2a = "Defensa:   ";
    if (j.getDefensaFisica() < 10) { linea2a += " "; }
    linea2a += std::to_string(j.getDefensaFisica());
    linea2a = tuberia + alinearIzquierda(linea2a, 15, " ", " ");
    std::string linea2b = "Defensa magica:  ";
    if (j.getDefensaMagica() < 10) { linea2b += " "; }
    linea2b += std::to_string(j.getDefensaMagica());
    linea2b = alinearIzquierda(linea2b, 22, " ", " ") + tuberia;
    linea2 = tuberia + linea2 + linea2a + linea2b + tuberia + "\n";
    pantalla.append(linea2);

    std::string linea3  = ("(2) " + j.getHabilidades().at(1).getNombre());
    linea3 += ". Usos: " + std::to_string(j.getHabilidades().at(1).getUsosRestantes()) + "/" +
              std::to_string(j.getHabilidades().at(1).getUsosTotales());
    linea3 = tuberia + alinearIzquierda(linea3, 37, " ", " ") + tuberia;
    std::string linea3a = "Velocidad: ";
    if (j.getVelocidad() < 10) { linea3a += " "; }
    linea3a += std::to_string(j.getVelocidad());
    linea3a = tuberia + alinearIzquierda(linea3a, 15, " ", " ");
    std::string linea3b = "Precision:      ";
    if (j.getPrecision() < 100) { linea3b += " ";}
    linea3b += (std::to_string(j.getPrecision()) + "%");
    linea3b = alinearIzquierda(linea3b, 22, " ", " ") + tuberia;
    linea3 = tuberia + linea3 + linea3a + linea3b + tuberia + "\n";
    pantalla.append(linea3);

    std::string linea4  = ("-" + j.getHabilidades().at(1).getDescripcion());
    linea4 = tuberia + alinearIzquierda(linea4, 37, " ", " ") + tuberia;
    std::string linea4a = "Evasion:   ";
    if (j.getEvasion() < 10) { linea4a += " "; }
    linea4a += (std::to_string(j.getEvasion()) + "%");
    linea4a = tuberia + alinearIzquierda(linea4a, 15, " ", " ");
    std::string linea4b = "Critico:         ";
    if (j.getCritico() < 10) { linea4b += " "; }
    linea4b += (std::to_string(j.getCritico()) + "%");
    linea4b = alinearIzquierda(linea4b, 22, "", " ") + tuberia;
    linea4 = tuberia + linea4 + linea4a + linea4b + tuberia + "\n";
    pantalla.append(linea4);

    pantalla.append(
"││                                     │└─────────────────────────────────────┘│\n"
    );

    std::string linea6 = ("(3) " + j.getHabilidades().at(2).getNombre());
    linea6 += ". Usos: " + std::to_string(j.getHabilidades().at(2).getUsosRestantes()) + "/" +
              std::to_string(j.getHabilidades().at(2).getUsosTotales());
    linea6 = tuberia + alinearIzquierda(linea6, 37, " ", " ") + tuberia;
    linea6 += "┌──────INFORMACION DE LA BATALLA──────┐";
    linea6 = tuberia + linea6 + tuberia + "\n";
    pantalla.append(linea6);

    std::string linea7 = ("-" + j.getHabilidades().at(2).getDescripcion());
    linea7 = tuberia + alinearIzquierda(linea7, 37, " ", " ") + tuberia;
    std::string linea7combate = "";
    linea7combate = tuberia + alinearIzquierda(linea7combate, 37, " ", " ") + tuberia;
    linea7 = tuberia + linea7 + linea7combate + tuberia + "\n";
    pantalla.append(linea7);

    std::string linea8 = "";
    linea8 = tuberia + alinearIzquierda(linea8, 37, " ", " ") + tuberia;
    std::string linea8combate = "";
    linea8combate = tuberia + alinearIzquierda(linea8combate, 37, " ", " ") + tuberia;
    linea8 = tuberia + linea8 + linea8combate + tuberia + "\n";
    pantalla.append(linea8);

    std::string linea9 = ("(4) " + j.getHabilidades().at(3).getNombre());
    linea9 += ". Usos: " + std::to_string(j.getHabilidades().at(3).getUsosRestantes()) + "/" +
              std::to_string(j.getHabilidades().at(3).getUsosTotales());
    linea9 = tuberia + alinearIzquierda(linea9, 37, " ", " ") + tuberia;
    std::string linea9combate = "";
    linea9combate = tuberia + alinearIzquierda(linea9combate, 37, " ", " ") + tuberia;
    linea9 = tuberia + linea9 + linea9combate + tuberia + "\n";
    pantalla.append(linea9);

    std::string linea10 = ("-" + j.getHabilidades().at(3).getDescripcion());
    linea10 = tuberia + alinearIzquierda(linea10, 37, " ", " ") + tuberia;
    std::string linea10combate = "";
    linea10combate = tuberia + alinearIzquierda(linea10combate, 37, " ", " ") + tuberia;
    linea10 = tuberia + linea10 + linea10combate + tuberia + "\n";
    pantalla.append(linea10);

    std::string linea11 = "";
    linea11 = tuberia + alinearIzquierda(linea11, 37, " ", " ") + tuberia;
    std::string linea11combate = "";
    linea11combate = tuberia + alinearIzquierda(linea11combate, 37, " ", " ") + tuberia;
    linea11 = tuberia + linea11 + linea11combate + tuberia + "\n";
    pantalla.append(linea11);

    std::string linea12 = ("(5) " + j.getHabilidades().at(4).getNombre());
    linea12 += ". Usos: " + std::to_string(j.getHabilidades().at(4).getUsosRestantes()) + "/" +
              std::to_string(j.getHabilidades().at(4).getUsosTotales());
    linea12 = tuberia + alinearIzquierda(linea12, 37, " ", " ") + tuberia;
    std::string linea12combate = "";
    linea12combate = tuberia + alinearIzquierda(linea12combate, 37, " ", " ") + tuberia;
    linea12 = tuberia + linea12 + linea12combate + tuberia + "\n";
    pantalla.append(linea12);

    std::string linea13 = ("-" + j.getHabilidades().at(4).getDescripcion());
    linea13 = tuberia + alinearIzquierda(linea13, 37, " ", " ") + tuberia;
    std::string linea13combate = "";
    linea13combate = tuberia + alinearIzquierda(linea13combate, 37, " ", " ") + tuberia;
    linea13 = tuberia + linea13 + linea13combate + tuberia + "\n";
    pantalla.append(linea13);

    pantalla.append(
"│└─────────────────────────────────────┘└─────────────────────────────────────┘│\n"
    );
    pantalla.append(
"└──────────────────────────────────────────────────────────────────────────────┘\n"
    );

    return pantalla;
}
