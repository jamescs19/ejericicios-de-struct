#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Vehiculo{
string placa;
string marca;
int anioDeFabricacion;
char estado;
};

bool setPlaca(Vehiculo &vehiculo, string placa)
{
    
    if(placa.length() >=1 && placa.length()<=10)
    {
        vehiculo.placa = placa;
        return true;
    }
    cout<<"La placa debe tener minimo 1 y maximo 10 caracteres"<<endl;
    return false;
}

bool setMarca(Vehiculo &vehiculo, string marca)
{
        if(marca.length()>=1 && marca.length() <=20)
        {
            vehiculo.marca = marca;
            return true;
        }
        return false;
}



bool setAnoDeF(Vehiculo &vehiculo, int ano)
{
    if(ano<1990 ||ano> 2025 )
    {
        cout<<"ERORR"<<endl;
        return false;
    }
    vehiculo.anioDeFabricacion = ano;
    return true;

}

bool setEstado(Vehiculo &vehiculo, char estado)
    {
        estado = toupper(estado);
            if(estado == 'R' || estado =='D')
        {
            vehiculo.estado = estado;
            return true;
         }
             cout<<"ERROR: El estado debe ser 'R' o 'D'"<<endl;
            return false;
    }




int main (){

    Vehiculo vehiculos [10];
    int contador = 0;
    int opcion;
    bool menu = true;


    do
    {
        cout<<"1: Registrar vehiculo"<<endl;
        cout<<"2: Listar vehiculos prestados"<<endl;
        cout<<"3: Mostrar vehiculos disponibles"<<endl;
        cout<<"4: Salir"<<endl;

        cout<<"Elige una opcion"<<endl;
        cin>>opcion;

        switch (opcion)
        {
            case 1:
               { 
                string placa;
                string marca;
                int anioDeFabricacion;
                char estado;
                bool validar= true;
                
                if(contador >= 10){
                    cout<<"ERORR: No hay mas espacio para guardar vehiculos"<<endl;
                }else{
                     
                    cin.ignore();
                    cout<<"Escribe la placa del vehiculo"<<endl;
                    getline(cin,placa);
                    if(setPlaca(vehiculos[contador],placa)== false)
                    {
                        validar = false;
                    }

                     cout<<"Escribe la marca del vehiculo"<<endl;
                     getline(cin,marca);
                     if(setMarca(vehiculos[contador],marca)== false)
                     {
                        validar =false;
                        
                     }

                      cout<<"Escribe el ano de fabricacion del vehiculo"<<endl;
                      cin>>anioDeFabricacion;
                      if(setAnoDeF(vehiculos[contador],anioDeFabricacion)== false)
                      {
                        validar = false;
                      }

                       cout<<"Escribe el estado del vehiculo; 'D' si esta disponible o 'R' si esta rentado"<<endl;
                        cin>>estado;
                        if(setEstado(vehiculos[contador], estado)== false)
                        {
                            validar= false;
                        }
                        if(!validar){
                            cout<<"ERROR"<<endl;
                            break;
                        }else{
                                cout<<"---VEHICULO REGISTRADO---"<<endl;
                                cout<<"PLACA: "<<vehiculos[contador].placa<<endl;
                                cout<<"MARCA: "<<vehiculos[contador].marca<<endl;
                                cout<<"ANO DE FABRICACION: "<<vehiculos[contador].anioDeFabricacion<<endl;
                                cout<<"ESTADO: "<<vehiculos[contador].estado<<endl<<endl;
                            }
                           
                }
                break;
               }
               

               case 2:
                    {
                        bool encontrado = false;
                    cout<<"---VEHICULOS RENTADOS---"<<endl;
                    for(int i =0; i<contador;i++){
                        if(vehiculos[i].estado == 'R')
                    {
                        encontrado = true;
                            cout<<"PLACA: "<<vehiculos[i].placa<<endl;
                            cout<<"MARCA: "<<vehiculos[i].marca<<endl;
                            cout<<"ANO DE FABRICACION: "<<vehiculos[i].anioDeFabricacion<<endl<<endl;
                    }
                }   
                    if(!encontrado)
                    {
                    cout<<"NO HAY VEHICULOS RENTADOS"<<endl;
                    }
                    break;
                }
                case 3:
                    {
                        bool encontrado = false;
                        cout<<"---VEHICULOs DISPONIBLES---"<<endl;
                    for(int i =0; i<contador;i++){
                        if(vehiculos[i].estado == 'D')
                    {
                            encontrado = true;   
                            cout<<"PLACA: "<<vehiculos[i].placa<<endl;
                            cout<<"MARCA: "<<vehiculos[i].marca<<endl;
                            cout<<"ANO DE FABRICACION: "<<vehiculos[i].anioDeFabricacion<<endl<<endl;
                    }
                }
                    if(!encontrado)
                    {
                    cout<<"NO HAY VEHICULOS DISPONIBLES"<<endl;
                    }
                    break;
                }
                case 4:
                cout<<"SALIENDO..."<<endl;
                menu = false;
                break;
                
                default:
                cout<<"ERROR: Elige una opcion del 1 al 4"<<endl;
                break;


        }
    } while (menu);
    





}