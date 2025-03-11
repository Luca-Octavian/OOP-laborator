#include <iostream>
#include <cmath>
using namespace std;
#include "Canvas.h"
Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->Clear();
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (x<0 || y<0 || x>this->width || y>this->height)
	{
		return;
	}
	this->canvas[y][x] = ch;//inversez din cauza ca in mod normal mai intai se ia pe verticala dupa pe orizontala
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 1;i < 360;i++)
	{
		int xraza = x + ray * cos(i);
		int yraza = y + ray * sin(i);
		if (xraza > 0 && yraza > 0 && xraza < this->width && yraza < this->height)
		{
			this->canvas[xraza][yraza] = ch;
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 1;i < 360;i++)// fac cercuri mai mici in cercul mare, astfel dand iluzia ca il umplu manual
		for(int j=1;j<ray;j++)
	{
		int xraza = x + j * cos(i);//mate calcul cerc furat din functia anterioara
		int yraza = y + j * sin(i);
		if (xraza > 0 && yraza > 0 && xraza < this->width && yraza < this->height)// sa nu ies din matrix
		{
			this->canvas[xraza][yraza] = ch;
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if ((left < 0 || top < 0 || right < 0 || bottom < 0) || (left > this->width || right > this->width || top > this->height || bottom > this->height))
	{
		cout << "coordonate invalide" << endl;
		return;
	}
	for (int i = top;i <= bottom;i++)
		this->canvas[i][right] = this->canvas[i][left] = ch;//desenez laturile paralele in 2 foruri, prima data pe horizontala dupa pe verticala
	for (int j = left;j <= right;j++)
		this->canvas[top][j] = this->canvas[bottom][j] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++)
		for (int j = left;j <= right;j++)
			this->canvas[i][j] = ch;
}
void Canvas::DrawLine(int x1, int x2, int y1, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int cx;
	if (x1 < x2)
		cx = 1;
	else
		cx = -1;
	int cy;
	if (y1 < y2)
	{
		 cy = 1;

	}
	else cy = -1;
	int detour = dx + dy;
	while (true) 
	{
		SetPoint(x1, y1, ch);  //punem pixelul

		if (x1 == x2 && y1 == y2)  
			break;
		//deci aici verificam daca diferenta este catre x si y si mergem accordingly(sa fie cat mai aproape de o linie perfecta)
		int detour_control = 2 * detour;
		if (detour_control >= dy) 
		{
			detour += dy;
			x1 += cx;
		}
		if (detour_control <= dx) 
		{
			detour += dx;
			y1 += cy;
		}
	}
}
void Canvas::Clear()
{
	for (int i = 0;i < this->width;i++)
	{
		for (int j = 0;j < this->height;j++)
		{
			this->canvas[i][j] = ' ';
		}
	}
}
void Canvas::Print()
{
	for (int i = 0;i < this->width;i++)
	{
		for (int j = 0;j < this->height;j++)
		{
				cout << this->canvas[i][j];
			
		}
		cout << endl;
	}
}
