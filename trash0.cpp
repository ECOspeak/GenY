#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <random>
#include <clocale>
#include <stdio.h>

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr)); // íàñòðîéêà ðàíäîìà

	float a=0;
	float b=0;
//
	int size;
	int tmp=0;
//
	cout<<"Ââåäèòå êîýôôèöèåíò à : ";
	cin>>a;
	cout<<"Ââåäèòå êîýôôèöèåíò b : ";
	cin>>b;
	cout<<"Ââåäèòå êîëëè÷åñòâî âû÷èñëÿåìûõ òî÷åê : ";
	cin>>size;

	//ãåíåðàöèÿ <-
	float* X = genX(tmp);
    float* Y = genY(a,b, X, tmp);





	return 0;
}


//ãåíåðàöèÿ ->

float* genX(int count){
    float* X = new float[count];
    for (int i = count-1;i >= 0;i--) {
        X[i] = 0.5 * (rand()%100);
        float tmp1;
        if(rand()%2 == 0)
            tmp1 = 0.5 * (rand()%10);
        else
            tmp1 = 0.5 * (rand()%10) * -1;
        X[i] += tmp1;
    }
    return X;
}

float* genY(const float a, const float b, float* X, int count){
    float* Y = new float[count];
    for (int i = count-1;i >= 0;i--) {
        Y[i] = a*X[i] + b;
    }
    return Y;
}

//


void writetofile(const float* X,const  float* Y,const  int count,const float a,const float b,const int* size) {
	ofstream fout("output.txt"); // ñîçäà¸ì îáúåêò êëàññà ofstream äëÿ çàïèñè è ñâÿçûâàåì åãî ñ ôàéëîì output.txt
	// çàïèñü ñòðîê â ôàéë
	for (int i = 0; i < count - 1; i++)
	{
		fout << "êîýôôèöèåíò à= "<< a << endl;
		fout << "êîýôôèöèåíò b= "<< b << endl;
		fout << "êîëëè÷åñòâî âû÷èñëÿåìûõ òî÷åê : " << size << endl;
		for (int i = 0; i < count;i++) //âûâîä õ
			 {
        if(i == count-1)
            fout << X[i] <<endl;
        else
            fout << X[i] << "," <<endl;
    		 }

		for (int i = 0; i < count;i++) //âûâîä y
			 {
        if(i == count-1)
            fout << Y[i] << endl;
        else
            fout << Y[i] <<"," << endl;
   			 }
	}

	fout.close(); // çàêðûâàåì ôàéë
}
