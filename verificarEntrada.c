#include "verificarEntrada.h"


bool validarArgumentos(int argc, char* argv[argc]){
    bool valido = true;
    if(argc == 1  || argc >=  7){
        return false;
    }
    
    if(strcmp(argv[1], "solve") !=0 && strcmp(argv[1], "validate") != 0 && strcmp(argv[1], "convert") != 0){
        return false;
    }else{
        if(findInput(argc, &argv[argc], &input[1024]) == 3){
            leerArchivo = true;
            if(archivoDeEntrada(&input[1024]) == false){
                return false;
            }
        }else if (findInput(argc, &argv[argc], &input[1024] ) == 2){
            return false;
        }else if (findInput(argc, &argv[argc], &input[1024] ) == 4){
            lecturaTexto = false;
            lecturaBinaria = true;
            leerArchivo = true;
            if(archivoDeEntrada(&input[1024]) == false){
                return false;
            }
        }
        if(findOutput(argc, &argv[argc], &output[1024]) == 3){
            archivoTexto = true;
            if(archivoDeSalida(&output[1024]) == false){
                return false;
            }
        }else if (findOutput(argc, &argv[argc], &output[1024]) == 2){
            return false;
        }else if (findOutput(argc, &argv[argc], &output[1024]) == 4){
            archivoBinario = true;
            if(archivoDeSalida(&output[1024]) == false){
                return false;
            }
        }
    }
    return true;
}

int findInput(int argc, char *argv[argc], char input[1024]){
    int inPut = 0;
    for(int index = 0; index < argc; index++)
    {
        if(strcmp(argv[index], "-it") == 0){
            if(strcmp(argv[index+1], "-ob") != 0 && strcmp(argv[index+1], "-ot") != 0 && strcmp(argv[index+1], "\0") != 0){
                strcat(input, argv[index+1]);
                return 3;
            }else{
                return 1;
            }
        }else if(strcmp(argv[index], "-ib") == 0){
            if(strcmp(argv[index+1], "-ob") != 0 && strcmp(argv[index+1], "-ot") != 0 && strcmp(argv[index+1], "\0") != 0){
                strcat(input, argv[index+1]);
                return 4;
            }else{
                return 2;
            }
        }else{
            inPut = 1;    
        }
    }
    return inPut;
}

int findOutput(int argc, char *argv[argc], char output[1024]){
    int outPut = 0;
    for(int index = 0; index < argc; index++){
        if(strcmp(argv[index], "-ot") == 0){
            if(strcmp(argv[index+1], "-ib") != 0 && strcmp(argv[index+1], "-it") != 0 && strcmp(argv[index+1], "\0") != 0){
                strcat(output, argv[index+1]);
                return 3;
            }else{
                return 1;
            }
        }else if(strcmp(argv[index], "-ob") == 0){
            if(strcmp(argv[index+1], "-ib") != 0 && strcmp(argv[index+1], "-it") != 0 && strcmp(argv[index+1], "\0") != 0){
                strcat(output, argv[index+1]);
                return 4;
            }else{
                return 2;
            }
        }else{
            outPut = 1;    
        }
    }
    return outPut;    
}

bool archivoDeEntrada(char input[1024]){
    char *nombreArchivo = strtok(input, ".");
    char *extencionArchivo = strtok(NULL, ".");
    if(nombreArchivo == NULL || extencionArchivo == NULL || strcmp(extencionArchivo, "txt") != 0 || strcmp(extencionArchivo, "dat")!= 0){
        return false;
    }else{
        if(strcmp(extencionArchivo, "txt") == 0 && lecturaTexto == true){
            strcat(input, nombreArchivo);
            strcat(input, ".");
            strcat(input, extencionArchivo);
        }else if(strcmp(extencionArchivo, "dat") == 0 && lecturaBinaria == true){
            strcat(input, nombreArchivo);
            strcat(input, ".");
            strcat(input, extencionArchivo);
        }else{
            return false;
        }
    }
    return true;
}

bool archivoDeSalida(char output[1024]){
    char *nombreArchivo = strtok(output, ".");
    char *extencionArchivo = strtok(NULL, ".");
    if(nombreArchivo == NULL || extencionArchivo == NULL || strcmp(extencionArchivo, "txt") != 0 || strcmp(extencionArchivo, "dat")!= 0){
        return false;
    }else{
        if(strcmp(extencionArchivo, "txt") == 0 && archivoTexto == true){
            strcat(input, nombreArchivo);
            strcat(input, ".");
            strcat(input, extencionArchivo);
        }else if(strcmp(extencionArchivo, "dat") == 0 && archivoBinario == true){
            strcat(input, nombreArchivo);
            strcat(input, ".");
            strcat(input, extencionArchivo);
        }else{
            return false;
        }
    }
    return true;
}
