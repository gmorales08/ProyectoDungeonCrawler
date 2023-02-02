#ifndef PANTALLAS
#define PANTALLAS

#include <iostream>
#include <vector>

/* CABECERA DONDE SE VAN A INCLUIR FUNCIONES QUE SE UTILICEN EN TODAS LAS PANTALLAS */


/* CONSTANTE ANCHO_PANTALLA
 *
 * El ancho que mide el layout del programa
 */
const int anchoPantalla = 79;

/* CONSTANTES CARACTERES
 *
 * Algunos caracteres especiales que se imprimiran en pantalla
 */
const std::string tuberia = "│";
const std::string bloque  = "█";


/* LIMPIAR_BUFFER_ENTRADA
 *
 * Limpia el buffer de entrada cin para evitar problemas de entrada de datos
 */
void limpiarBufferEntrada();

/* IMPRIMIR_LOG
 *
 * Funcion para imprimir un "Mensaje del Sistema" en la parte inferior de la
 * pantalla
 * Se usara para controlar errores e imprimir informacion relacionada con la
 * entrada de datos
 *
 * El primer parametro "tipoDeMensaje" sirve para saber el color del mensaje a
 * imprimir:
 *
 *     0: aviso -> imprime un mensaje amarillo
 *     1: error -> imprime un mensaje rojo
 *
 *
 * La segunda variante de imprimirLog, sirve para imprimir dos lineas de texto
 * El mensaje que ira en la segunda linea, se le pasa como tercer parametro.
 */
std::string imprimirLog(int tipoDeMensaje, std::string mensaje);
std::string imprimirLog(int tipoDeMensaje, std::string mensaje1,
                        std::string mensaje2);

/* VALIDAR_OPCION
 *
 * Comprueba si la opcion pasada como parametro es valida para el menu actual
 *
 * Se pasa como parametro la opcion a validar y la constante con las opciones
 * validas
 */
bool validarOpcion(std::string opcion, std::vector<std::string> opcionesMenu);

/* CARGAR_PANTALLA
 *
 * Carga la pantalla en cuestion y ejecuta su menu
 * Ademas devuelve la opcion seleccionada para luego pasarla al menu como
 * parametro
 *
 * Se pasa por parametro:
 *
 *     canvasPantalla: string constante de la pantalla a imprimir
 *
 *     opcionesMenu: opciones validas para el menu de la pantalla
 *
 *     log: mensaje para imprimir en el log en caso de que sea necesario
 *
 *
 * Alternativa: Tambien se le puede pasar un cuarto parametro para especificar
 * el mensaje de error que se mostrara:
 *
 *     logError: string con el error a mostrar en el log
 *
 *
 * Alternativa: Si se le pasa solo el canvas y el mensaje de log, leera la
 * entrada de datos sin hacer comprobaciones
 *
 *     Se va a usar para leer cadenas de texto, como por ejemplo, el nombre del
 *     personaje.
 */
std::string cargarPantalla(std::string canvasPantalla,
                           std::vector<std::string> opcionesMenu,
                           std::string log);
std::string cargarPantalla(std::string canvasPantalla,
                           std::vector<std::string> opcionesMenu,
                           std::string log, std::string logError);
std::string cargarPantalla(std::string canvasPantalla, std::string log);

/* IMPRIMIR_PANTALLA_ESTATICA
 *
 * Imprime una pantalla donde no haya que seleccionar ninguna opcion
 *
 * Se para por parametro el canvas de la pantalla
 *
 * Sobrecarga: se le puede pasar uno o dos mensaje de log para que los imprima
 */
void imprimirPantallaEstatica(std::string canvasPantalla);
void imprimirPantallaEstatica(std::string canvasPantalla, std::string log);
void imprimirPantallaEstatica(std::string canvasPantalla, std::string log1,
                              std::string log2);

/* CENTRAR_TEXTO
 *
 * Centra el texto pasado por parametro en una linea cuya longitud tambien se
 * pasa por parametro. Devuelve un string con el texto centrado.
 * Ademas, imprime antes y despues de la linea los caracteres de borde "|"
 *
 * Se pasa por parametro:
 *
 *     texto: el string que queremos ubicar en el centro de la linea
 *
 *     longitudLinea: el tamano de la linea donde se centra el texto
 *
 * Ejemplo: centrarTexto("texto", 10);
 *
 *     $ | texto  |
 *     Nº12345678910 -> en total son 10 caracteres incluyendo los bordes "|",
 *                      espacios y el texto.
 *
 * Nota: si el numero de espacios a distribuir a los laterales del texto es
 * impar, el texto siempre se situara mas cerca de la izquierda (ver ejemplo
 * anterior).
 *
 * Nota: se hara uso de la constante anchoPantalla para indicar la longitud de
 * la linea en caso de querer ocupar todo el layout.
 *
 *
 * Alternativa: tambien se le puede indicar cual es el caracter inicial y final
 * que queremos que imprima, en vez de |
 */
std::string centrarTexto(std::string texto, int longitudLinea);
std::string centrarTexto(std::string texto, int longitudLinea,
                         std::string caracterInicial,
                         std::string caracterFinal);

#endif // PANTALLAS
