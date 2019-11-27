#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool lecturaTexto = true;
bool lecturaBinaria = false;
bool salidaTexto = true;
bool salidaBinaria = false;
bool leerArchivo = false;
bool archivoTexto = false;
bool archivoBinario = false;
char input[1024];
char output[1024];

bool validarArgumentos(int argc, char* argv[argc]);
int findInput(int argc, char *argv[argc], char input[1024]);
int findOutput(int argc, char *argv[argc], char output[1024]);
bool archivoDeEntrada(char input[1024]);
bool archivoDeSalida(char output[1024]);
