#include <iostream>
#include <string>

using namespace std;


const int MAX =5;


struct Producto{

string name;
string code;
double price;
int amount;

};

bool setName(Producto &Producto, string name){

    if(name.length()>2 && name.length()<15){

        Producto.name = name;
        return true;
    }

    return false;

}

bool setPrice(Producto &Producto, double price){

    if(price <=0){
        return false;
    }

    Producto.price = price;
    return true;

}


bool setAmount (Producto &producto, int amount){

    if (amount<0)
    {
        return false;
    }

    producto.amount = amount;
    return true;
    
}

void registrarP(Producto productos[],int &contador){
    

    string name;
    string code;
    double price;
    int amount;
    Producto prueba;

    if(contador >=MAX){
        cout<<"Error: you passed the limit of products"<<endl;
        return;
    }

    cout<<"Enter the product name"<<endl;
    cin.ignore();
    getline(cin,name);
    if (!setName(prueba,name))
    {
        cout<<"ERROR: The product name has to be between 2 and 14 letters"<<endl;
        return;
    }

     cout<<"Enter the product code"<<endl;
        getline(cin,code);
        prueba.code =code;

        cout<<"Enter the product price"<<endl;
        cin>>price;
        if(!setPrice(prueba,price)){
            cout<<"The price has to be bigger than 0"<<endl;
            return;
        }

        cout<<"Enter the product amount"<<endl;
        cin>>amount;
        if(!setAmount(prueba,amount)){
            cout<<"The product amount cannot be lower than 0"<<endl;
            return;
        }

        productos[contador] = prueba;

        cout<<"Product successfully registered"<<endl;
        cout<<"Name: "<<productos[contador].name<<endl;
        cout<<"Code: "<<productos[contador].code<<endl;
        cout<<"Price: "<<productos[contador].price<<endl;
        cout<<"Amount: "<<productos[contador].amount<<endl;
        contador ++;

}

string productState(Producto productos ){

if(productos.amount ==0){
return "State: Out of stock";
}

if(productos.amount >=1 && productos.amount <5){

    return "State: Limited stock";
} else{

    return "State: Available";
}

}

double totalPrice(Producto productos){

    double total =0;
     total = productos.price *productos.amount;
    return total;

}

void biggestPrice(Producto productos[], int contador){

    if(contador ==0){
        cout<<"There are not products registered"<<endl;
        return;
    }

    int biggest = 0;

    for( int i =1; i<contador; i++){

        if (productos[i].price> productos[biggest].price)
        {
            biggest = i;
        } 

    }       

    cout<<"The more expensive product is: "<<productos[biggest].name<<endl;
    

}




void sumProducts(Producto productos[], int contador){

    if(contador ==0){
        cout<<"There are no products registered"<<endl;
        return;
    }

    
    double sum = 0;

    for (int i = 0; i < contador; i++)
    {
        sum += productos[i].price* productos[i].amount;
    }

    cout<<"The price of the total products is: "<<sum<<endl;
    
}



void showProducts(Producto productos[],int contador){


if(contador ==0){
    cout<<"There are not products to show"<<endl;
    return;
}
        cout<<"------Products registered-----"<<endl;
    for(int i = 0; i<contador; i++){
     
        cout<<"Name: "<<productos[i].name<<endl;
        cout<<"Code: "<<productos[i].code<<endl;
        cout<<"Price: "<<productos[i].price<<endl;
        cout<<"Amount: "<<productos[i].amount<<endl;
        cout<<productState(productos[i])<<endl;
        cout<< "Total price: "<<totalPrice(productos[i])<<endl<<endl;
        

}
        biggestPrice(productos,contador);
    

}
    



int main (){


    Producto productos[MAX];
int contador =0;
bool menu = true;
int opcion =0;



do
{

        cout<<"-----MENU-----"<<endl;
        cout<<"1. Register product"<<endl;
        cout<<"2. Show registered products"<<endl;
        cout<<"3. Show total price"<<endl;
        cout<<"4. Exit"<<endl;
    cout<<"choose an option"<<endl;
    cin>>opcion;


    switch (opcion)
    {
    case 1:
        registrarP(productos,contador);
        break;
    
    case 2:
        showProducts(productos, contador);
        break;


    case 3: sumProducts(productos, contador);
    
        break;

    case 4:
    menu = false;
    break;
    
    default:
    cout<<"choose an option from 1 to 4"<<endl;
    break;
    }
} while (menu);




}