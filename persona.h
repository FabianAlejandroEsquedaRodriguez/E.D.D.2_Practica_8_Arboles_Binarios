#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string.h>
#include "ArbolBinario.h"
using namespace std;

/* Definición de la clase Persona. */
class Persona
{
    private:
        int AnioNac, Vive;
        char NomPers[20], LugNac[20];

    public:
        Persona();
        Persona(int, int, char[], char[]);
        friend istream & operator>> (istream & , Persona & );
        friend ostream & operator<< (ostream & , Persona & );
};

/* Declaración del método constructor por omisión. */
Persona::Persona()
{

}

/* Declaración del método constructor con parámetros. */
Persona::Persona(int ANac, int Vi, char NomP[], char LugN[])
{
    AnioNac= ANac;
    Vive= Vi;
    strcpy(NomPers, NomP);
    strcpy(LugNac, LugN);
}

/* Sobrecarga del operador >> para permitir la lectura de objetos tipo
Persona de manera directa. */
istream & operator>>(istream & Lee, Persona & ObjPers)
{
    cout<<"\n\nIngrese nombre de la Persona: ";
    Lee>> ObjPers.NomPers; 
    cout<<"\nIngrese año de nacimiento: ";
    Lee>> ObjPers.AnioNac; 
    cout<<"\nIngrese lugar de nacimiento: ";
    Lee>> ObjPers.LugNac; 
    cout<<"\nEsta viva (0/1)?: ";
    Lee>> ObjPers.Vive;

    return Lee;
}

/* Sobrecarga del operador << para permitir la escritura de objetos tipo
Persona de manera directa. */
ostream & operator<< (ostream & Escribe, Persona & ObjPers)
{
    Escribe<<"Datos de la Persona\n";
    Escribe<<"\nNombre: "<<ObjPers.NomPers;
    Escribe<<"\nLugar de nacimiento: "<<ObjPers.LugNac;
    Escribe<<"\nAño de nacimiento: "<<ObjPers.AnioNac;
    
    if (ObjPers.Vive == 1)
        Escribe<<"\nEsta viva.\n\n";
    else
        Escribe<<"\nNo esta viva.\n\n";
    
    return Escribe;
}

#endif