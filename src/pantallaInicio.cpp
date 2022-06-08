#include <cstdio>
#include "utilidadesDeTerminal.h"
#include "pantallaInicio.h"


void imprimirPantallaInicio() {

	system("PS1=''");
	limpiarPantalla();

	printf("┌─────────────────────────────────────────────────────────────────────────────┐\n");
 	printf("│                                                                             │\n");
	printf("│                                                                             │\n");
 	printf("│                   ___                                                       │\n");
 	printf("│                  |  _ \\ _   _ _ __   __ _  ___  ___  _ __                   │\n");
 	printf("│                  | | | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\                  │\n");
 	printf("│                  | |_| | |_| | | | | (_| |  __/ (_) | | | |                 │\n");
 	printf("│                  |____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|                 │\n");
 	printf("│                                     |___/                                   │\n");
 	printf("│                    ____                    _                                │\n");
 	printf("│                   / ___|_ __ __ ___      _| | ___ _ __                      │\n");
 	printf("│                  | |   | '__/ _` \\ \\ /\\ / / |/ _ \\ '__|                     │\n");
 	printf("│                  | |___| | | (_| |\\ V  V /| |  __/ |                        │\n");
 	printf("│                   \\____|_|  \\__,_| \\_/\\_/ |_|\\___|_|                        │\n");
 	printf("│                                                                             │\n");
 	printf("│                                                                             │\n");
 	printf("│                                 1. JUGAR                                    │\n");
 	printf("│                                                                             │\n");
 	printf("│                            2. ¿COMO SE JUEGA?                               │\n");
 	printf("│                                                                             │\n");
 	printf("│                                 3. SALIR                                    │\n");
 	printf("│                                                                             │\n");
 	printf("└─────────────────────────────────────────────────────────────────────────────┘\n");
	printf("Opcion: ");
}
