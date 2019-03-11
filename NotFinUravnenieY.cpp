#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <random>

using namespace std;

int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); // настройка рандома
	//
	float a=0;
	float b=0;
	float* X = nullptr;             
	float* Y = nullptr;
	int size=0;
	//
	cout<<"Введите коэффициент а : ";
	cin>>a;
	cout<<"Введите коэффициент b : ";
	cin>>b;
	cout<<"Введите колличество вычисляемых значений : ";
	cin>>size;
			
	return 0;
}


//генерация ->

//

void createX(const int* size)
{
   float* X = new float[size];
    for (int i = size-1;i >= 0;i--) 
	{
        X[i] = 0.5 * (rand()%100);
    }
    return X;
}

void createY(const float a, const float b, float* X, const int* size)
{
    float* Y = new float[size];
    for (int i = size;i > 0;i--)
	{
        Y[i] = a * X[i] + b;
    }
    return Y;
}

//


void writetofile(const float a,const float b,const float* X,const float* Y,const int* size) 
{
	ofstream fout("output.txt"); // создаём ofstream для записи и связываем его с файлом output.txt
	// запись строк в файл
	for (int i = 0; i < size - 1; i++)
	{
		fout << "коэффициент а= "<< a << endl;
		fout << "коэффициент b= "<< b << endl;
		fout << "колличество вычисляемых значений = " << size << endl;
			for (int i = 0; i < size;i++) //вывод y 
			 {
            	fout <<"Y="<< Y[i]  << endl;
   			 }
   			 
			for (int i = 0; i < size;i++) //вывод х
			 {
			 	fout<<"При X ="<< X[i] << "\t" << endl;
    		 }
	
			
	}
	fout.close(); // закрываем файл
}
