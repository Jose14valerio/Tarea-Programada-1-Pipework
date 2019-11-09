#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    if(argc > 5  || argc < 2){
        printf("no ingreso la cantidad de argumentos necesarios\n");
        return -1;
    }
    
    if(argv[1] == "validate") {
        if(argc == 3 && argv[2] != "-it" || argv[2] != "-ib"){
            //variables para guardar el nombre del archivo y su extension
            char *nombreArchivo = strtok(argv[2], ".");
            char *extencionArchivo = strtok(NULL, ".");
            //Si no mete una extension valida(.dat o .txt) el programa advierte y se cierra
            if(strcmp(extencionArchivo, "txt") != 0 && strcmp(extencionArchivo, "dat") != 0){
                printf("No ingresò una extension valida para el archivo\nEl programa se va a cerrar\n");
                return -1;
            }
        }else if(argc == 3 && argv[2] == "-it" || argv[2] == "-ib"){
        
        }else if(argc == 4){
            
        }
    }else if(argv[1] == "solve") {
        if(argc == 3 && argv[2] != "-it" || argv[2] != "-ib"){
            //variables para guardar el nombre del archivo y su extension
            char *nombreArchivo = strtok(argv[2], ".");
            char *extencionArchivo = strtok(NULL, ".");
            //Si no mete una extension valida(.dat o .txt) el programa advierte y se cierra
            if(strcmp(extencionArchivo, "txt") != 0 && strcmp(extencionArchivo, "dat") != 0){
                printf("No ingresò una extension valida para el archivo\nEl programa se va a cerrar\n");
                return -1;
            }
            //Crea una cadena donde se va a guardar el nombre del archivo con su extension
            char nombre[1024] = "";
            strcat(nombre, nombreArchivo);
            strcat(nombre, ".");
            strcat(nombre, extencionArchivo);   
        }else if(argc == 3 && argv[2] == "-it" || argv[2] == "-ib"){
            
        }else if(argc == 4){
            
        }
    }else if(argv[1] == "convert"){
        if(argc < 5){
            printf("no ingreso la cantidad de argumentos necesarios\n");
            return -1;
        }else{
            if(argv[2] == "-ib"){
                //variables para guardar el nombre del archivo y su extension
                char *nombreArchivo = strtok(argv[3], ".");
                char *extencionArchivo = strtok(NULL, ".");
                //Si no mete una extension valida(.dat o .txt) el programa advierte y se cierra
                if(strcmp(extencionArchivo, "dat") != 0){
                    printf("No ingresò una extension valida para el archivo\nEl programa se va a cerrar\n");
                    return -1;
                }
                //Crea una cadena donde se va a guardar el nombre del archivo con su extension
                char nombre[1024] = "";
                strcat(nombre, nombreArchivo);
                strcat(nombre, ".");
                strcat(nombre, extencionArchivo);

                //variables para guardar el nombre del archivo y su extension
                char *nombreArchivo2 = strtok(argv[4], ".");
                char *extencionArchivo2 = strtok(NULL, ".");
                //Si no mete una extension valida(.dat o .txt) el programa advierte y se cierra
                if(strcmp(extencionArchivo, "txt") != 0){
                    printf("No ingresò una extension valida para el archivo\nEl programa se va a cerrar\n");
                    return -1;
                }
                //Crea una cadena donde se va a guardar el nombre del archivo con su extension
                char nombre2[1024] = "";
                strcat(nombre, nombreArchivo2);
                strcat(nombre, ".");
                strcat(nombre, extencionArchivo2);
            }else if(argv[2] == "-it"){
                //variables para guardar el nombre del archivo y su extension
                char *nombreArchivo = strtok(argv[3], ".");
                char *extencionArchivo = strtok(NULL, ".");
                //Si no mete una extension valida(.dat o .txt) el programa advierte y se cierra
                if(strcmp(extencionArchivo, "txt") != 0){
                    printf("No ingresò una extension valida para el archivo\nEl programa se va a cerrar\n");
                    return -1;
                }
                //Crea una cadena donde se va a guardar el nombre del archivo con su extension
                char nombre[1024] = "";
                strcat(nombre, nombreArchivo);
                strcat(nombre, ".");
                strcat(nombre, extencionArchivo);

                //variables para guardar el nombre del archivo y su extension
                char *nombreArchivo2 = strtok(argv[4], ".");
                char *extencionArchivo2 = strtok(NULL, ".");
                //Si no mete una extension valida(.dat o .txt) el programa advierte y se cierra
                if(strcmp(extencionArchivo, "dat") != 0){
                    printf("No ingresò una extension valida para el archivo\nEl programa se va a cerrar\n");
                    return -1;
                }
                //Crea una cadena donde se va a guardar el nombre del archivo con su extension
                char nombre2[1024] = "";
                strcat(nombre, nombreArchivo2);
                strcat(nombre, ".");
                strcat(nombre, extencionArchivo2);
            }
        }
    }
   
    return 0;
} 
