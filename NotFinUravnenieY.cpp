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
	srand(time(nullptr)); // ��������� �������
	//
	float a=0;
	float b=0;
	float* X = nullptr;             
	float* Y = nullptr;
	int size=0;
	//
	cout<<"������� ����������� � : ";
	cin>>a;
	cout<<"������� ����������� b : ";
	cin>>b;
	cout<<"������� ����������� ����������� �������� : ";
	cin>>size;
			
	return 0;
}


//��������� ->

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
	ofstream fout("output.txt"); // ������ ofstream ��� ������ � ��������� ��� � ������ output.txt
	// ������ ����� � ����
	for (int i = 0; i < size - 1; i++)
	{
		fout << "����������� �= "<< a << endl;
		fout << "����������� b= "<< b << endl;
		fout << "����������� ����������� �������� = " << size << endl;
			for (int i = 0; i < size;i++) //����� y 
			 {
            	fout <<"Y="<< Y[i]  << endl;
   			 }
   			 
			for (int i = 0; i < size;i++) //����� �
			 {
			 	fout<<"��� X ="<< X[i] << "\t" << endl;
    		 }
	
			
	}
	fout.close(); // ��������� ����
}
