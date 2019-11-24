File *file; 
file = fopen(input, r)

void leerArchivo(File *file){
    char removeSpace;
    int counter = 0;
    while(counter<4){
        fgets(generalInfo[counter], 1 ,stdin);
        counter++;
    }

    filas = generalInfo[0];
    columnas = generalInfo[1];
    entradas = generalInfo[2];
    salidas = generalInfo[3];

    fgets(removeSpace, 1, stdin);

    int dimensionCounter = 0;
    while (dimensionCounter<entradas+salidas){
        fgets(leakage[dimensionCounter].row, 1 ,stdin);
        fgets(leakage[dimensionCounter].column, 1 ,stdin);
        fgets(leakage[dimensionCounter].cardinal, 1 ,stdin);
        dimensionCounter++;
    }

    fgets(removeSpace, 1, stdin);

    //memory allocation
    matriz = (char**)malloc(sizeof(char*)*filas+2);
    for (int filaCounter=0; filaCounter<filas+2; filaCounter++){
        matriz[filaCounter] = (char*)malloc(sizeof(char)*columnas+2);
    }
    // llena el rededor con -1
    for (int filaCounter= 0; filaCounter< filas+2; filaCounter++ ){
        for (int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
            if(filaCounter ==0 ||columnaCounter ==0 ||filaCounter ==filas+1 || columnaCounter==columnas+1){
                matriz[filaCounter][columnaCounter] = -1;
            }else{
                fgets(matriz[filaCounter][columnaCounter], 1, stdin);
            }   
        }
    }
}

