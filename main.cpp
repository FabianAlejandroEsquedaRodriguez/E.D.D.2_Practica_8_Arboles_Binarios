/*
Equipo #3:

-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/

#include "persona.h"

/* Función principal. Crea el árbol genealógico de un individuo y
➥posteriormente imprime los datos de todos sus ascendientes femeninos. */
int main()
{
    system("color F4");
    system("cls");

    size_t op, i;
    ArbolBinario<Persona> Genealogico;
    Persona Individuo;
    NodoArbol<Persona> *Ap;
    fstream arbol_entrada;

//     if(arbol_entrada.is_open()){
//     cout<<"\tarchivos recuperados"<<endl;
//     while(!arbol_entrada.eof()){
//         arbol_entrada.seekg((i)* sizeof(Persona));
//         arbol_entrada.read(reinterpret_cast <char*>(&Individuo), sizeof(Persona));
//         if(Genealogico.RegresaRaiz() != 0){
//             Genealogico.CreaArbol(Ap);
//             cout<<Individuo;
//             i++;
//         }
//         arbol_entrada.peek();//Consulta y devuelve el siguiente caracter o eof()
//     }
//         cout<<endl;
// }
//     arbol_entrada.close();

    do
    {
        cout<<"\t\t\tMENU DE OPCIONES"<<endl<<endl;
        cout<<"(1) CREAR ARBOL"<<endl;
        cout<<"(2) IMPRIMIR ASCENDIENTES FEMENINOS"<<endl;
        cout<<"(3) IMPRIMIR ASCENDIENTES MASCULINOS"<<endl;
        cout<<"(4) SALIR"<<endl;

        cout<<endl<<"DIGITA UNA OPCION: ";
        cin>>op;

        system("cls");

        switch(op)
        {
            case 1: cout<<"\t\t\tCREAR ARBOL"<<endl;
                    Ap = Genealogico.RegresaRaiz();//Al inicio esta en NULL
                    //Ir generando arbol
                    Genealogico.CreaArbol(Ap);
                    Ap = Genealogico.RegresaRaiz();//Ahora la raiz apunta hacia el siguente nodo

                    cout<<"\n\n";system("pause");
                    system("cls");
                    break;

            case 2: cout<<"\t\tIMPRIMIR ASCENDENTES FEMENINOS"<<endl;
                    /* Se recupera la información del individuo. */
                    Individuo = Ap->RegresaInfo();
                        cout<<"\n----------------------------------------\n\n";
                    cout<<"Los ascendientes femeninos de: \n"<<Individuo;
                    cout<<"-------------------------------------------\n";
                    
                    Genealogico.ImprimeIzq(Ap);

                    cout<<"\n\n";system("pause");
                    system("cls");
                    break;

            case 3: cout<<"\t\tIMPRIMIR ASCENDENTES MASCULINOS"<<endl;
                    //Se recupera la informacion del individuo
                    Individuo = Ap->RegresaInfo();

                    cout<<"\n----------------------------------------\n\n";
                    cout<<"Los ascendientes masculinos de: \n"<<Individuo;
                    cout<<"-------------------------------------------\n";

                    Genealogico.ImprimeDer(Ap);

                    cout<<"\n\n";system("pause");
                    system("cls");
                    break;

            case 4: cout<<"\t\t\tSALIENDO..."<<endl<<endl;
                    cout<<"\t\tRESPALDANDO LA INFORMACION EN UN ARCHIVO"<<endl<<endl;

                    fstream salidaFem("ascendientes_femeninos.txt", ios::out | ios::binary);
                    fstream salidaMasc("ascendientes_masculinos.txt", ios::out | ios::binary);

                    Genealogico.GuardarFemeninos(Genealogico.RegresaRaiz(), salidaFem);
                    Genealogico.GuardarMasculinos(Genealogico.RegresaRaiz(), salidaMasc);

                    salidaFem.close();
                    salidaMasc.close();
            
                    break;
                    
        }

    }while(op != 4);

    return 0;
}