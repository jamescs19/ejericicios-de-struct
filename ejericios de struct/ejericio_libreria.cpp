#include <iostream>
#include <string>
#include <cctype>
using namespace std;





struct Libro {

string titulo;
string autor;
int anoDeP ;
char estado;

};
//condiciones del titulo
bool setTitulo(Libro &libro, string titulo){

    if (titulo.length() <1 || titulo.length() >50)
    {
        cout<<"Titulo invalido"<<endl;
        return false;

    }
        libro.titulo =titulo;
        return true;
    
}

//condiciones del autor
bool setAutor(Libro &libro, string autor){

    if (autor.length() <1 || autor.length() >30)
    {
        cout<<"ERORR"<<endl;
        return false;
    }
        libro.autor = autor;
    return true;
    
}
//condiciones del esado
bool setEstado(Libro &libro, char estado){
        estado = tolower(estado);
    if (estado != 'p' && estado != 'd')
    {
        cout<<"ERROR"<<endl;
        return false;
    }
        libro.estado = estado;
        return true;
    
    
}
//condiciones del ano de publicaicon
bool setAnoDeP(Libro &libro, int ano){

    if (ano<1900 || ano > 2025)
    {
        cout<<"ERORR"<<endl;
        return false;
    }

    libro.anoDeP = ano;
    return true;
    
}







int main(){

Libro libros [10];

int contador =0; 
int opcion;
bool menu = true; 


do
{
    cout<<"-----MENU-----"<<endl;
    cout<<"1: Registrar libro"<<endl;
    cout<<"2: Listar libros prestados"<<endl;
    cout<<"3: Salir"<<endl;

    cout<<"Elige una opcion"<<endl;
    cin >> opcion;
    



        switch (opcion)
        {
            
            case 1:
            {
            string titulo;
            string autor;
            int anoDeP;
            char estado;
            bool validar = true;

            
                if(contador <10)
                {
                cout<<"Escribe el titulo del libro"<<endl;
                cin.ignore();
                getline(cin,titulo);
                if(setTitulo(libros[contador],titulo) == false){
                    validar = false;
                }
                
                cout<<"Escribe el nombre del autor"<<endl;
                getline(cin,autor);
                if(setAutor(libros[contador],autor) == false){
                    validar = false;
                }

                cout<<"Escribe el ano de publicacion"<<endl;
                cin>>anoDeP;
                if(setAnoDeP(libros[contador],anoDeP)== false){
                    validar = false;
                }

                cout<<"Lista el libro('p' para prestado y 'd' para disponible)"<<endl;
                cin>>estado;
                if(setEstado(libros[contador],estado)== false){
                    validar = false;
                }
                
                if(validar){
                cout<<"-----LIBRO REGISTRADO CORRECTAMENTE-----"<<endl<<endl;
                cout<<"TITULO: "<<libros[contador].titulo<<endl;
                cout<<"AUTOR: "<<libros[contador].autor<<endl;
                cout<<"ANO DE PUBLICACION : "<<libros[contador].anoDeP<<endl;
                cout<<"Estado : "<<libros[contador].estado<<endl<<endl;

                contador++;
                } else{
                    cout<<"ERROR: No se pudo registrar el libro"<<endl;
                    
                }



                }else{

                cout<<"ERROR: Pasaste el limite de libros"<<endl;
                }
                
                break;
            }

            case 2:
            {
                bool hayLibrosPrestados= false;
                cout<<"-----LIBROS PRESTADOS-----"<<endl<<endl;
                for (int i=0; i<contador; i++){

                    if (libros[i].estado =='p')
                    {
                        cout<<"TITULO: "<<libros[i].titulo<<endl;
                        cout<<"AUTOR: "<<libros[i].autor<<endl;
                        cout<<"ANO DE PUBLICACION : "<<libros[i].anoDeP<<endl<<endl;
                    
                        hayLibrosPrestados = true;
                    }
                }

                if (!hayLibrosPrestados)
                {
                    cout<<"no hay libros prestados"<<endl;
                }
                
                break;
            }
                case 3:
                cout<<"SALIENDO..."<<endl;
                menu = false;
                break;

                default:
                cout<<"Elige una opcion del 1 al 3"<<endl;
                break;
            }


        }while (menu);




   return 0;

}
