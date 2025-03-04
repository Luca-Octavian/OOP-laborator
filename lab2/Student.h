class Student
{
private:
	char name[50];
	int math, eng, ist;
public:
	char* GetName();
	float GetMath();
	float GetEng();
	float GetIst();
	float GetAvg();
	void SetName(char name[50]);
	void SetMath(float x);
	void SetEng(float x);
	void SetIst(float x);
}
;