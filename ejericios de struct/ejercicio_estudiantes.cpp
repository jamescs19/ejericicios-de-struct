#include<iostream>
#include<string>
using namespace std;

const int MAX =100;

struct Estudiante {

    string nombre;
    string matricula;
    float cal1, cal2, cal3;

};


bool setNombre(Estudiante &estudiante, string nombre){

    if(nombre.length()>=2 && nombre.length()<=14){

    estudiante.nombre = nombre;
    return true;

    }
    return false;
}

bool setMatricula(Estudiante &estudiantes, string matricula){

    if(matricula.length()>3 && matricula.length()<11){

        estudiantes.matricula = matricula;
        return true;
    }

    return false;
}

bool setCalificaciones(float calificacion){
    return calificacion>=0 && calificacion<=5;
}


void regisrtrarEstudiante(Estudiante estudiantes[],int &n){

string nombre;
string matricula;
float cal1, cal2, cal3;
    Estudiante prueba;

    if( n >=MAX){
        cout<<"Limite de estudiantes alcanzados"<<endl;

    }else{
    cout<<"Indique el nombre del estudiante"<<endl;
        cin.ignore();
    getline(cin, nombre);
    if(!setNombre(prueba, nombre))
    {
        cout<<"ERROR"<<endl;
        return;
    }    
    cout<<"Indique la matricula del estudinate"<<endl;
    getline(cin, matricula);
    if(!setMatricula(prueba, matricula))
    {
        cout<<"ERROR"<<endl;
        return;
    }

    cout<<"Calificacion 1:"<<endl;
    cin>>cal1;
    if (!setCalificaciones(cal1)){
        cout<<"ERROR"<<endl;
        return;
    }
    prueba.cal1 = cal1;
    

        cout<<"Calificacion 2:"<<endl;
    cin>>cal2;
    if (!setCalificaciones(cal2)){
        cout<<"ERROR"<<endl;
        return;
    } 
    prueba.cal2 = cal2;
    
            cout<<"Calificacion 3:"<<endl;
    cin>>cal3;
    if (!setCalificaciones(cal3)){
        cout<<"ERROR"<<endl;
        return;
    } 
    prueba.cal3 = cal3;
    
    estudiantes[n] = prueba;
            
            cout<<"Estudiante registrado correctamente"<<endl;
            cout<<"Nombre: "<<estudiantes[n].nombre<<endl;
            cout<<"Matricula: "<<estudiantes[n].matricula<<endl;
            cout<<"Calificaciones "<<estudiantes[n].cal1<<", ";
            cout<<estudiantes[n].cal2<<" y "<<estudiantes[n].cal3<<endl<<endl;
              n++;

    }
}

float promedio (Estudiante estudiantes){
    return (estudiantes.cal1 + estudiantes.cal2 + estudiantes.cal3) /3;
}
void mayorPromedio(Estudiante estudiante[],int n){
int contador =0;
float mayor = promedio(estudiante[0]);
if (n == 0){
    cout<<"No hay estudiantes registrados"<<endl;
    return;
}

for(int i =0; i<n; i++){
    if (promedio(estudiante[i])> mayor)
    {
        mayor = promedio(estudiante[i]);
        contador =i;
    }
}

 cout<<"El estudiante con mejor promedio es: "<<estudiante[contador].nombre<< " su promedio es de: "<<mayor<<endl;
}
void mostrarEstudiantes (Estudiante estudiantes[], int n){

    if(n==0){
        cout<<"No hay estudiantes registrados"<<endl;
        return;
    }
    cout<<"-----Estudiantes registrados-----"<<endl;
    for (int i = 0; i < n; i++)
    {
            cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
            cout<<"Matricula: "<<estudiantes[i].matricula<<endl;
            cout<<"Calificaciones "<<estudiantes[i].cal1<<", ";
            cout<<estudiantes[i].cal2<<" y "<<estudiantes[i].cal3<<endl<<endl;
    }
    
}




int main(){

Estudiante estudiantes [MAX];
int n = 0;
int opcion =0;
bool menu = true;

do
{
    cout<<"1. Registrar estudiantes"<<endl;
    cout<<"2. Mostrar mejor promedio"<<endl;
    cout<<"3. Mostrar estudiantes registrados"<<endl;
    cout<<"4. Salir"<<endl<<endl;
    cout<<"Elige una opcion (del 1 al 4)"<<endl;
    cin>>opcion;
    

    switch (opcion)
    {
    case 1:
        regisrtrarEstudiante(estudiantes,n);
        break;
    
    case 2:
        mayorPromedio(estudiantes,n);
        break;
    

    case 3:
    mostrarEstudiantes(estudiantes,n);
    break;

    case 4:
    cout<<"Saliendo..."<<endl;
    menu = false;
    break;

    default:
    cout<<"Elige una opcion del 1 al 4"<<endl;
        break;
    }

} while (menu);


}

