#include <iostream>
using namespace std;
struct Nodo
{
    string nombre;
    Nodo *sig;
}*lista;

void insertarInicio();
void menu(int);
void insertarFinal(Nodo *);
void insertarFinalR(Nodo *);

/*ELiminar*/
void eliminar(Nodo *);
void eliminarR(Nodo *, Nodo *, string);

void mostar(Nodo *);

Nodo *crearELemento();

int main()
{
    lista = NULL;
    /*insertarFinal(lista,"Sofi");
    insertarFinal(lista,"Cortez");
    insertarFinal(lista,"Silvia");
    insertarFinal(lista,"Fabi");
    insertarFinal(lista,"Pedro");*/
    /*insertarFinal(lista);
    insertarFinal(lista);
    insertarFinal(lista);
    insertarFinal(lista);
    mostar(lista);*/
    menu(0);
    return 0;
}

void menu(int op)
{
    cout << "1. Insertar Persona "<< endl;
    cout << "2. Buscar una persona "<< endl;
    cout << "3. Mostrar Personas"<< endl;
    cout << "4. Eliminar Persona"<< endl;
    cin >> op;
    switch(op)
    {
        case 1:
            insertarFinal(lista);
            menu(op);
        break;
        case 2:
            cout << "en procesp" << endl;
            menu(op);
        break;
        case 3:
        cout << "*********Personas en la lista **********" << endl;
            mostar(lista);
            cout << "***************************************"<< endl;
            menu(op);
        break;
        case 4:
            cout << "Eliminar" << endl;
            eliminar(lista);
            menu(op);
        break;
        default:
            cout << "Adios" << endl;
        break;
    }
}

Nodo *crearELemento()
{
    Nodo *nuevo = new Nodo;
    cout << "Ingrese el nombre: ";
    cin >> nuevo->nombre;
    return nuevo;
}

void insertarInicio()
{
    Nodo *nuevo = crearELemento();
   /* nuevo->nombre = nombre;*/
    nuevo->sig = lista;
    lista = nuevo;
}

void mostar(Nodo *aux)
{
    if(aux)
    {
        cout << aux->nombre << endl;
        mostar(aux->sig);
    }
}

void insertarFinal(Nodo *aux)
{
    if(!aux)
    {
        insertarInicio();
    }
    else
    {
        insertarFinalR(aux);
    }
}

void insertarFinalR(Nodo *aux)
{
    //cout << "entro0" << endl;
    if(aux->sig)
    {
        insertarFinalR(aux->sig);
    }
    else
    {
        Nodo *nuevo = crearELemento();
        /*nuevo->nombre=nombre;*/

        aux->sig = nuevo;
        nuevo->sig = NULL;
    }
  
}

/*ELiminar*/
void eliminar(Nodo *p)
{
    string nombre;
    cout << "Escriba el nombre: ";
    cin >> nombre;
    
    if(!lista)
    {
        cout << "Lista vacia"<< endl;
    }
    else if(lista->nombre == nombre)
    {
        lista = lista->sig;
        p->sig = NULL;
        delete(p);
        cout << "Eliminado con exito"<< endl;
    }
    else{
        eliminarR(p, NULL, nombre);
    }
}
void eliminarR(Nodo *p, Nodo *q, string nombre)
{
    if(p && p->nombre != nombre)
    {
        eliminarR(p->sig,p,nombre);
    }
    else
    {
        q->sig = p->sig;
        p->sig = NULL;
        delete(p);
        cout << "Eliminado con exito"<< endl;
    }
}