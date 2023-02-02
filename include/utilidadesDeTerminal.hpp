#ifndef UTILIDADES_DE_TERMINAL
#define UTILIDADES_DE_TERMINAL

#include <string>
#include <chrono> // Para pausar()
#include <thread> // Para pausar()


/*#ifdef __WIN32 // Para que funcionen los codigos de colores ANSI en Windows
system("");
system("prompt $S"); // Oculta el prompt
#endif        // _WIN32*/

/* LIMPIAR_PANTALLA
 *
 * Limpia la pantalla
 *
 * Tambien cambia el color a blanco sobre negro, por si la terminal estuviese
 * configurada en otro color, y oculta el prompt de la terminal
 */
void limpiarPantalla();

/* PAUSAR
 *
 * Pausa la ejecucion del programa x segundos
 *
 * El numero de segundo se pasa por paramentro
 * El de tipo float para poder pasar valores decimales
 * Como luego se va a convertir a milisegundos en float, el maximo de decimales
 * es 3
 * Este metodo hace uso de <thread> y <chrono> para funcionar
 */
void pausar(float segundos);

/* IMPRIMIR_COLORES
 *
 * Funciones para imprimir el texto pasado por parametro en un determinado color
 * Imprime el texto en un color, y tras imprimirlo vuelve a poner el color
 * blanco para las siguientes lineas
 *
 * Tabla de codigos de colores:
 *
 *  +--COLOR-------HEX-------ANSI_CODE-----CMD_COLOR--+
 *  | BLACK    - #000000 -     030     -      0       |
 *  | BLACK_BG - #000000 -     040     -      0       |
 *  | BLUE     - #0000FF -     094     -      1       |
 *  | GREEN    - #00FF00 -     092     -      A       |
 *  | CYAN     - #00FFFF -     096     -      B       |
 *  | RED      - #FF0000 -     091     -      4       |
 *  | MAGENTA  - #FF00FF -     095     -      D       |
 *  | YELLOW   - #FFFF00 -     093     -      6       |
 *  | WHITE    - #FFFFFF -     097     -      F       |
 *  +-------------------------------------------------+
 */
std::string imprimirAzul(std::string texto);
std::string imprimirVerde(std::string texto);
std::string imprimirCyan(std::string texto);
std::string imprimirRojo(std::string texto);
std::string imprimirMagenta(std::string texto);
std::string imprimirAmarillo(std::string texto);
std::string imprimirBlanco(std::string texto);

#endif //UTILIDADES_DE_TERMINAL
