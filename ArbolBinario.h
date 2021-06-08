#include <iostream>
#include <fstream>
using namespace std;

/* Prototipo de la plantilla de la clase ArbolBinario. Así, en la clase
NodoArbol se podrá hacer referencia a ella. */
template <class T>
class ArbolBinario;

/* Declaración de la clase NodoArbol. Cada nodo almacena la información
que es la razón de ser de la estructura tipo árbol y las direcciones de
su hijo izquierdo y de su hijo derecho. */
template <class T>
class NodoArbol
{
    private:
        T Info;
        NodoArbol<T> *HijoIzq;
        NodoArbol<T> *HijoDer;
    public:
        NodoArbol();
        T RegresaInfo();
        void ActualizaInfo(T);
        friend class ArbolBinario<T>;
};

/* Declaración del método constructor por omisión. Inicializa
las ligas a los subárboles con el valor de NULL. Indica nodo sin
descendientes. */
template <class T>
NodoArbol<T>::NodoArbol()
{
    HijoIzq = NULL;
    HijoDer = NULL;
}

/* Método que regresa la información almacenada en el nodo. */
template <class T>
T NodoArbol<T>::RegresaInfo()
{
    return Info;
}

/* Método para actualizar la información almacenada en el nodo. */
template <class T>
void NodoArbol<T>::ActualizaInfo(T Dato)
{
    Info = Dato ;
}

/* Declaración de la clase ArbolBinario. Tiene un puntero al nodo
raíz. */
template <class T>
class ArbolBinario
{
    private:
        NodoArbol<T> *Raiz;
    public:
        ArbolBinario ();
        NodoArbol<T> *RegresaRaiz();
        void CreaArbol(NodoArbol<T> *);
        void ImprimeIzq(NodoArbol<T> *);
        void ImprimeDer(NodoArbol<T> *);

        void GuardarFemeninos(NodoArbol<T> *, fstream &);
        void GuardarMasculinos(NodoArbol<T> *, fstream &);
};

/* Declaración del método constructor. Inicializa el puntero a la raíz
➥con el valor NULL. Indica que el árbol está vacío. */
template <class T>
ArbolBinario<T>::ArbolBinario()
{
    Raiz = NULL;
}

/* Método que regresa el valor del apuntador a la raíz del árbol. */
template <class T>
NodoArbol<T> *ArbolBinario<T>::RegresaRaiz()
{
    return Raiz;
}

/* Método que crea un árbol binario. */
template <class T>
void ArbolBinario<T>::CreaArbol(NodoArbol<T> *Apunt)
{
    char Resp;
    Apunt= new NodoArbol<T>;

    cout<<"\n\nIngrese la informacion a almacenar: ";
    cin>>Apunt->Info;//sobrecarga

    cout<<"\n\n"<<Apunt->Info<<"Tiene hijo izquierdo (S/N)? ";
    cin>>Resp;

    if (Resp == 's')
    {
        CreaArbol(Apunt->HijoIzq);
        Apunt->HijoIzq = Raiz;
    }

    cout<<"\n\n"<<Apunt->Info<<"Tiene hijo derecho (S/N)? ";
    cin>>Resp;

    if (Resp == 's')
    {
        CreaArbol(Apunt->HijoDer);
        Apunt->HijoDer = Raiz;
    }
    Raiz = Apunt;
}

/* Método que imprime la información almacenada en las raíces de todos
➥los subárboles izquierdos. La primera vez recibe como dato la raíz del
➥árbol. */
template <class T>
void ArbolBinario<T>::ImprimeIzq(NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        if (Apunt->HijoIzq)
        {
            cout<<Apunt->HijoIzq->Info;
            ImprimeIzq(Apunt->HijoIzq);
        }
        ImprimeIzq(Apunt->HijoDer);
    }
}

/* Método que imprime la información almacenada en las raíces de todos
➥los subárboles derechos. La primera vez recibe como dato la raíz del
➥árbol. */
template <class T>
void ArbolBinario<T>::ImprimeDer(NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        if (Apunt->HijoDer)
        {
            cout<<Apunt->HijoDer->Info;
            ImprimeDer(Apunt->HijoDer);
        }
        ImprimeDer(Apunt->HijoIzq);
    }
}

template <class T>
void ArbolBinario<T>::GuardarFemeninos(NodoArbol<T> *ap, fstream &out)
{
    if(ap)
    {
        if(ap->HijoIzq)
        {
            //out.write(reinterpret_cast<const char *>(&ap->HijoIzq->Info), sizeof(ap));
            out<<ap->HijoIzq->Info;
            cout<<endl;
            
            GuardarFemeninos(ap->HijoIzq, out);
        }
        GuardarFemeninos(ap->HijoDer, out);
    }
}

template <class T>
void ArbolBinario<T>::GuardarMasculinos(NodoArbol<T> *ap, fstream &out)
{
    if(ap)
    {
        if(ap->HijoDer)
        {
            out<<ap->HijoDer->Info;
            cout<<endl;
            
            GuardarMasculinos(ap->HijoDer, out);
        }
        GuardarMasculinos(ap->HijoIzq, out);
    }
}