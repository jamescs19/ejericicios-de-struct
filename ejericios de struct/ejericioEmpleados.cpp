#include <iostream>
#include <string>
#include <cctype>
using namespace std;


struct Empleado
{
    string nombre;
    float salario;
    int horasTrabajadas;
    char estado;

};

void convertirMinusculas(string &texto) {
    for(char &c : texto) {
        c = tolower(c);
    }
}

bool setNombre(Empleado &empleado, string &nombre){

    convertirMinusculas(nombre);


    if (nombre.length() >=1 && nombre.length() <=40)
    {
        empleado.nombre = nombre;
        return true;
    }
    
    return false;
}

bool setSalario(Empleado &empleado, float salario){

    if(salario<=0){

        return false;
    }
    empleado.salario = salario;
    return true;
}


bool setHorasT(Empleado &empleado, int horasTrabajadas){

    if(horasTrabajadas<0 || horasTrabajadas>60){
        
        
        return false;
    }
    empleado.horasTrabajadas = horasTrabajadas;
    return true;

}

bool setEstado(Empleado &empleado, char estado ){

    estado = toupper(estado);

    if (estado == 'I' || estado == 'A')
    {
        empleado.estado = estado;
        return true;
    }
    
    
    return false;
}

void mostrarInactivos(const Empleado &empleado){

 
   
        cout<<"Nombre: "<<empleado.nombre<<endl;
        cout<<"Salario: "<<empleado.salario<<endl;
        cout<<"Horas trabajadas: "<<empleado.horasTrabajadas<<endl<<endl;
                
            
        }

        




int main (){

Empleado empleados [8];

    int contador=0;
    int opcion;
    bool menu = true;
    

    do
    {

            cout<<"-----MENU-----"<<endl;
        cout<<"1. Registrar empleado"<<endl;
        cout<<"2. Listar empleados activos"<<endl;
        cout<<"3. Listar empleados inactivos"<<endl;
        cout<<"4. Salario promedio de empleados Activos"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cin>>opcion;


        switch (opcion)
            {
                {
                case 1:
                string nombre;
                float salario;
                int horasTrabajadas;
                char estado;
                bool validar = true;

            if (contador >=8){
                cout<<"No se pueden agregar mas empleados"<<endl;
            }else{

                    cout<<"Ingrese el nombre del empleado"<<endl;
                    cin.ignore();
                    getline(cin,nombre);
                    if(setNombre(empleados[contador], nombre)== false)
                    {
                        cout<<"ERROR:Su nombre debe tener minimo 1 y maximo 40 caracteres"<<endl;
                        validar = false;
                    }

                    cout<<"Ingrese el salario del empleado"<<endl;
                    cin>>salario;
                    if (setSalario(empleados[contador], salario)== false)
                    {
                        cout<<"ERROR: El salario debe ser mayor a 0"<<endl;
                        validar = false;
                    }

                    cout<<"Ingrese las horas trabajadas"<<endl;
                    cin>>horasTrabajadas;
                    if(setHorasT(empleados[contador],horasTrabajadas)== false)
                    {
                        cout<<"ERROR: Las horas deben estar entre 0 y 60"<<endl;
                        validar = false;
                    }

                    cout<<"Ingrese el estado del empleado 'I' o 'A'"<<endl;
                    cin>>estado;
                    if(setEstado(empleados[contador],estado)==false)
                    {
                        cout<<"ERROR: Su estado debe ser 'I'(inactivo) o 'A' (activo)"<<endl;
                        validar = false;

                    }
                    


                    if(validar){

                        cout<<"Empleado registrado correctamente"<<endl;
                        cout<<"Nombre: "<<empleados[contador].nombre<<endl;
                        cout<<"Salario: "<<empleados[contador].salario<<endl;
                        cout<<"Horas trabajadas: "<<empleados[contador].horasTrabajadas<<endl;
                        cout<<"Estado: "<<empleados[contador].estado<<endl<<endl;
                        contador++;
                    }else{

                        cout<<"Hubo un error con los datos anteriores. Registre de nuevo al empleado"<<endl;
                    }
                   
                    }
                    break;
                } 

            

                
                case 2:
                    {
                        bool hayEmpleadoasActivos = false;
                            cout<<"Empleados activos"<<endl;
                        for(int i=0 ; i<contador;i++){
                            if(empleados[i].estado == 'A')
                            {      
                                cout<<"Nombre: "<<empleados[i].nombre<<endl;
                                cout<<"Salario: "<<empleados[i].salario<<endl;
                                cout<<"Horas trabajadas: "<<empleados[i].horasTrabajadas<<endl<<endl;
                                hayEmpleadoasActivos = true;

                            }
                        }
                            if (!hayEmpleadoasActivos)
                            {
                                cout<<"No hay trabajadores activos"<<endl;
                            }
                            break;
                     }


                     case 3:
                     {
                        bool hayEmpleadosInactivos= false;
                            cout<<"Empleados inactivos"<<endl;
                            for(int i= 0;i<contador; i++){
                                if(empleados[i].estado =='I'){
                                mostrarInactivos(empleados[i]);
                                hayEmpleadosInactivos = true;
                                }
                            }

                            if(!hayEmpleadosInactivos){
                                cout<<"No hay empleados inactivos"<<endl;
                            }
                            break;
                    }      
                     

                     
                     case 4:
                     {
                      float sumaSalarios =0;
                      float promedio =0;

                      for(int i =0;i<contador;i++){
                        if(empleados[i].estado == 'A')
                        {
                        sumaSalarios +=empleados[i].salario;
                        promedio +=1;
                        }
                      }
                      if(promedio ==0){
                        cout<<"No hay empleados activos para calcular el promedio de su salario"<<endl;
                      }else{
                        float resultado = sumaSalarios/promedio;
                        cout<<"El promedio es: "<<resultado<<endl; 
                      }
                      break;
                     }

                     case 5:
                     cout<<"Saliendo..."<<endl;
                     menu = false;
                     break;

                     default:
                     cout<<"Elige una opcion del 1 al 5"<<endl;
                     break;

        }
    



    


    } while (menu);
    


}