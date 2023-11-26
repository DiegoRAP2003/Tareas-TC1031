#ifndef FUNCIONES_H
#define FUNCIONES_H

#pragma once

class Funciones{
    public:
        Funciones() {};
        int sumaIterativa(int n);
        int sumaRecursiva(int n);
        int sumaDirecta(int n);
};

int Funciones::sumaIterativa(int n){
    int acum = 0;
    for(int i = 0; i <= n; i++){
        acum += i;
    }
    return acum;
}

int Funciones::sumaRecursiva(int n){
    if(n < 1){
        return 0;
    }else{
        return n + sumaRecursiva(n -1);
    }
}

int Funciones::sumaDirecta(int n){
    return (n * (n + 1 )) / 2;;
}

#endif