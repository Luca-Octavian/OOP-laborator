
class Number
{
	int base;
	char* number;
	int Char2Int();
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& other);
	Number(Number&& other);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	bool operator>(Number& other);
	bool operator<(Number& other);
	Number &operator=(Number& other);
	bool operator==(Number& other);
	Number operator+(Number& other);
	Number operator-(Number& other);
	Number& operator=(Number&& other);
	Number operator--();
};

