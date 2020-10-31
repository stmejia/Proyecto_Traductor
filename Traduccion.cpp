#include<iostream>
#include<fstream>
#include<string.h>
#include "Diccionario.cpp"

using namespace std;

Diccionario diccionario = Diccionario();
char palabrasTotales[500];
void modificacion();
void traducir();
string DatosTraducidos[500];
string datosTempunto[500];
string datosTempLlave[500];
int contador = 0;
int cont2 = 0;

main(){
	int opc = 0;
	while(opc != 3){
		cout<<"Ingrese el numero de la accion que desea realizar"<<endl;
		cout<<"1. Modificar archivo"<<endl;
		cout<<"2. Traductor de palabras reservadas"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>opc;
		
		if(opc == 1){
			
		} else if(opc == 2){
			traducir();
			/*string cod;
			cout<<"Ingrese algo xd"<<endl;
			cin.ignore();
			getline(cin, cod);
			DatosTraducidos[0] = cod + "Mandarina";
			cout<<DatosTraducidos[0]<<endl;*/
		}
	}
}

void traducir(){
	/*diccionario.obtenerDatos();
	for(int j=0; j<diccionario.contador;j++){
		cout<<"Palabra: "<<diccionario.Palabras[j].palabra<<endl;
		cout<<"Traduccion: "<<diccionario.Palabras[j].traduccion<<endl;
	}*/
	std::fill_n(DatosTraducidos,500,0);
	std::fill_n(datosTempunto,500,0);
	contador=0;
	cont2 = 0;
	unsigned pos;
	char delpunto[] = ";";
	char delLlave[] = "{";
	string codigo;
	cout<<"Ingrese codigo a traducir sin saltos de linea"<<endl;
	cin.ignore();
	getline(cin,codigo);
	if(!codigo.empty()){
		strcpy(palabrasTotales, codigo.c_str());
		char *datopunto = strtok(palabrasTotales, delpunto);
		string datpunto(datopunto); 
		if(datopunto != NULL){
			datosTempunto[contador] = datpunto+";";
			contador++;
			while((datopunto=strtok(NULL, delpunto)) != NULL){
				string datpunto2(datopunto);
				datosTempunto[contador] = datpunto2+";";
				contador++;
			}
		}
		pos = datosTempunto[contador-1].find(";");
		string datAlone = datosTempunto[contador-1].substr(0,pos);
		datosTempunto[contador-1] = datAlone;
		
		for(int k=0; k<contador-1;k++){
			strcpy(palabrasTotales, datosTempunto[k].c_str());
			char *datoLlave = strtok(palabrasTotales, delLlave);
			string datLlave(datoLlave);
			if(datoLlave != NULL){
				datosTempLlave[]
			}
		}
	}
	cout<<endl;
	for(int i=0; i<contador;i++){
		cout<<datosTempunto[i]<<endl;
	}
	
}
