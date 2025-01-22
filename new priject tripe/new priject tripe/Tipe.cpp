#include "Tipe.h"
#include <string>
using namespace std;

//Tipe::Tipe(int id, Area area1, char** sites, int numBus,
//	int numOrder, int numwaiting, int cost, int sumOut, Date dateTripe) {
//
//
//}
Tipe::Tipe( Area area1,  int numBus,int cost, int sumOut, Date dateTripe) : DateTripe(dateTripe){
	
	area = area1;
	NumBus = numBus;
	Cost = cost;
	SumOut = sumOut;
	

	Numwaiting = 0;
    NumOrder = 0;
	}
Tipe:: Tipe():DateTripe(01, 01, 2020) {
	area = center;
	NumBus = 2;
	Cost = 500;
	SumOut = 300;
	
	Numwaiting = 0;
	NumOrder = 0;
}

Tipe::Tipe(const Tipe& other) :DateTripe(other.DateTripe){
	Id=other.Id;
    area=other.area;
	//Sites = other.Sites;
	NumBus=other.NumBus;
	NumOrder = other.NumOrder;
	Numwaiting = other.Numwaiting;
	Cost = other.Cost;
	SumOut = other.SumOut;	

   /* Sites = new char**;*/
	

	for (int i = 0; i < SIZE; ++i) {
		Sites[i] = new char[strlen(other.Sites[i]) + 1]; // הקצאת זיכרון עבור המחרוזת
		strcpy(Sites[i], other.Sites[i]);               // העתקת תוכן המחרוזת
	}

}



//בנאי הזזה
Tipe::Tipe(const Tipe&& other) :DateTripe(other.DateTripe) {
	Id = other.Id;
	area = other.area;
	
	NumBus = other.NumBus;
	NumOrder = other.NumOrder;
	Numwaiting = other.Numwaiting;
	Cost = other.Cost;
	SumOut = other.SumOut;

	for (int i = 0; i < SIZE; ++i) {
		Sites[i] = other.Sites[i]; 
		
	}

}

Tipe :: ~ Tipe() {
	cout << "im dtor";
	for (int i = 0; i < SIZE; i++) {
		delete[] Sites[i];
	}
}

int Tipe :: getId()  {
	return Id;
}
char** Tipe::getSites() {
	return Sites;
}


int Tipe:: getNumBus() {
	return NumBus;
}

int Tipe::getNumOrder() {
	return NumOrder;
}
int Tipe::getNumwaiting() {
	return Numwaiting;
}
int Tipe::getCost() {
	return Cost;
}
int Tipe::getSumOut() {
	return SumOut;
}

Date Tipe::getDateTripe() {
	return DateTripe;
}

//setter

void Tipe::setId(int id) {
	if (id < 100)
		printf("the code small");
	else
	   Id = id;
}
void Tipe::setSites(char** sites) {
	for (int i = 0; i < SIZE; ++i) {
		Sites[i] = new char[strlen(Sites[i]) + 1]; // הקצאת זיכרון עבור המחרוזת
		strcpy(Sites[i],Sites[i]);               // העתקת תוכן המחרוזת
	}
}
void Tipe::setNumBus(int numBus) {
	NumBus = numBus;
}
void Tipe::setNumOrder(int numOrder) {
	NumOrder = numOrder;
}
void Tipe::setNumwaiting(int numwaiting) {
	Numwaiting = numwaiting;
}
void Tipe::setCost(int cost) {
	Cost = cost;
}
void Tipe::setSumOut(int sumOut) {
	SumOut = sumOut;
}
void Tipe::setDateTripe(Date dateTripe){

	DateTripe = dateTripe;
}

//מחזירה מס מקומות אפשריים
int Tipe :: NumPart() {
	return NumBus * 50;
}
//מחזירה את מס המקומות הפנויים
int Tipe :: NumAvible() {
	return (NumPart() - NumOrder);
}
//מעדכנת ממתינים ומזמינים
void Tipe::NumReg(int regist) {
	if (NumAvible() >= regist) {
		NumOrder += regist;
		cout << "all the regist saccsses";
	}
	else {
		int x = regist - (regist - NumAvible());
		Numwaiting += (regist - NumAvible());
		NumOrder = NumPart();
		cout << "num register:" << x << "  and in waiting :" << Numwaiting;
	}
}
//מדפיס פרטים על הטיול
void Tipe::toString() {
	cout << "ID -" << Id << "Area-"
		<< area << "cost- " << Cost << "NumOrder- " << NumOrder <<
		"NUmPart- " << NumPart() << "nUmAvible- " << NumAvible();
}
//מחשבת רווח
int Tipe::NUmIn() {
	return (NumOrder * Cost) - SumOut;
}

//מחזירה את כמות האתרים
int Tipe ::NUmSites() {
	int counter=0;
	int i = 0;
	while (Sites[i]!=nullptr) {
		counter++;
		i++;
	}
	return counter;
}
//בודקת האם האתר קיים בטיול
bool Tipe::FoundSites(char * sit) {
	for (int i = 0; i < SIZE; i++) {
		
		if (strcmp(Sites[i], sit)==0)
			return true;
	}
	return false;

}

void Tipe::AddBusToWaite(int raf) {
	if (Numwaiting <= raf) {
		cout << "אין מספיק ממתינים להוספת אוטובוס";
	}
	else{
		int busa = Numwaiting / raf;
		int bus = Numwaiting / 50;
		NumOrder += Numwaiting -( Numwaiting % 50);
		Numwaiting = Numwaiting % 50;

		if (busa - bus > 0 && Numwaiting > 0) {
			NumOrder += Numwaiting;
			Numwaiting = 0;
			cout << "all numwaiting";
		}
		cout << "NUmwaiting" << Numwaiting;

	}
		
}



















