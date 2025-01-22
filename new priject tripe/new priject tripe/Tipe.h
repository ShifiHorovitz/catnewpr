#pragma once
#include "Date.h"
constexpr auto SIZE = 10;
class Tipe
{
	
	
	enum Area { center, north, north };
private:
	int Id;
	Area area;
	char *Sites[SIZE];
	int NumBus;
	int NumOrder;
	int Numwaiting;
	int Cost;
	int SumOut;
	Date DateTripe;

public:
	//getter
	int getId();
	
	char** getSites();
	int getNumBus();
	int getNumOrder();
	int getNumwaiting();
	int getCost();
	int getSumOut();
	Date getDateTripe();

	//setter

	void setId(int id);
	void setSites(char** sites);
	void setNumBus(int numBus);
	void setNumOrder(int numOrder);
	void setNumwaiting(int numwaiting);
	void setCost(int cost);
	void setSumOut(int sumOut);
	void setDateTripe(Date date);
	//constractors
	
	Tipe(Area area1, int numBus, int cost, int sumOut, Date dateTripe);
	Tipe();
	Tipe(const Tipe& other);
	Tipe(const Tipe&& other);


	~Tipe();

	//functions
	int NumPart();
	int NumAvible();
	void NumReg(int regist);
	void toString();
	int NUmIn();
	int NUmSites();
	bool FoundSites(char* sit);
	void AddBusToWaite(int raf);
	
};



