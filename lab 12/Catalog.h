#pragma once
#include <iostream>
#include <map>
using namespace std;
enum TipMaterie
{
	Obligatoriu,
	Optional,
	Facultativ
};
class Materie
{
protected:
	const char* Nume;
	TipMaterie tip;
	int credite;
public:
	 Materie()
	{
		this->Nume = nullptr;
		this->tip = Obligatoriu;
		this->credite = 0;
	}
	 ~Materie()
	{
		 
	}
	 const char* GetNume() const { return this->Nume; }
	 int GetCredite() const { return this->credite; }
	 TipMaterie GetTip() const { return this->tip; }
	
	virtual void Afisare() = 0;
};
class Matematica : public Materie
{
	Matematica()
	{
		this->Nume = "Matematica";
		this->tip = Obligatoriu;
		this->credite = 6;
	}
	~Matematica()
	{
		
	}
	void Afisare() override
	{
		cout << "Nume:" << " " << "Matematica" << " " << "tip:" << " " << "(Obligatoriu)" << " " << "credite:" <<" "<< credite << endl;
	}

};
class Romana : public Materie
{
	Romana()
	{
		this->Nume = "Romana";
		this->tip = Obligatoriu;
		this->credite = 4;
	}
	~Romana()
	{
		
	}
	void Afisare() override
	{
		cout << "Nume:" << " " << this->Nume << " " << "tip:" << " " << "this->tip" << " " << "credite:" << " " << credite << endl;
	}

};
class Informatica : public Materie
{
	Informatica()
	{
		this->Nume = "Informatica";
		this->tip = Obligatoriu;
		this->credite = 5;
	}
	~Informatica()
	{
		
	}
	void Afisare() override
	{
		cout << "Nume:" << " " << this->Nume << " " << "tip:" << " " << "this->tip" << " " << "credite:" << " " << credite << endl;
	}

};
class Engleza : public Materie
{
	Engleza()
	{
		this->Nume = "Engleza";
		this->tip = Facultativ;
		this->credite = 3;
	}
	~Engleza()
	{
	
	}
	void Afisare() override
	{
		cout << "Nume:" << " " << this->Nume << " " << "tip:" << " " << "this->tip" << " " << "credite:" << " " << credite << endl;
	}

};
class Optional1 : public Materie
{
	Optional1()
	{
		this->Nume = "Optional1";
		this->tip = Optional;
		this->credite = 5;
	}
	~Optional1()
	{
	
	}
	void Afisare() override
	{
		cout << "Nume:" << " " << this->Nume << " " << "tip:" << " " << "this->tip" << " " << "credite:" << " " << credite << endl;
	}

};
class Optional2 : public Materie
{
	Optional2()
	{
		this->Nume = "Optional2";
		this->tip = Optional;
		this->credite = 5;
	}
	~Optional2()
	{
		
	}
	void Afisare() override
	{
		cout << "Nume:" << " " << this->Nume << " " << "tip:" << " " << "this->tip" << " " << "credite:" << " " << credite << endl;
	}

};
class Student
{
	 char* nume;
	 char* NrMatricol;
     char* program;
	map<Materie, float> Harta;
public:
	Student(map<Materie,float> &m,char* Nume, char* NrMatricol, char* program)
	{
		this->Harta = m;
		this->nume = new char[strlen(Nume) + 1];
		strcpy(this->nume, Nume);

		this->NrMatricol = new char[strlen(NrMatricol) + 1];
		strcpy(this->NrMatricol, NrMatricol);

		this->program = new char[strlen(program) + 1];
		strcpy(this->program, program);
	}
	~Student()
	{
		delete[] nume;
		delete[] NrMatricol;
		delete[] program;
	}
	float medie()
	{
		auto calculeazaMedie = [this]() -> float 
			{
			if (Harta.empty()) return 0;
			float suma = 0;
			int contor = 0;
			for (auto& i : this->Harta) 
			{
				suma += i.second;
				contor++;
			}
			return suma / contor;
			};

		return calculeazaMedie(); 
	}

	char* GetName()
	{
		return this->nume;
	}
	char* GetNrMatricol()
	{
		return this->NrMatricol;
	}
	char* GetProgram()
	{
		return this->program;
	}
};
class Catalog
{
protected:
	Student *S;
	int nr_stud;
public:
	Catalog()
	{
		this->nr_stud = 0;
	}
	virtual Catalog& AddStudent(Student *S) = 0;
	virtual int GetNrStud(char *NrMatricol) = 0;
	virtual int RankingStud() = 0;
	~Catalog()
	{
		delete[] S;
	}
};
class Ro : public Catalog
{
	{

	}
};

