
		
#include <iostream>
#include <windows.h>



using namespace std;
const int WIDTH = 4;
const int HEIGHT = 4;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class Figure abstract
{
protected:
	int figure[WIDTH][HEIGHT]{};
	int code;
public:
	virtual void SetFigure() = 0;
	virtual void SetColor() = 0;
	void ShowFigure()
	{
		
		for (size_t i = 0; i < WIDTH; i++)
		{
			for (size_t j = 0; j < HEIGHT; j++)
			{
				if (figure[i][j])
				{
					SetConsoleTextAttribute(h, code);
					cout << "*";
					SetConsoleTextAttribute(h, 8);
				}
				else
					cout << "*";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
};
class SquareFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][0] = 1;
		figure[0][1] = 1;
		figure[1][0] = 1;
		figure[1][1] = 1;
	}
	void SetColor()
	{
		code = 14;
	}
};

class LineFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][0] = 1;
		figure[1][0] = 1;
		figure[2][0] = 1;
		figure[3][0] = 1;
	}
	void SetColor()
	{
		code = 11;
	}
};
class SFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][1] = 1;
		figure[0][2] = 1;
		figure[1][0] = 1;
		figure[1][1] = 1;
	}
	void SetColor()
	{
		code = 12;
	}
};
class ZFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][0] = 1;
		figure[0][1] = 1;
		figure[1][1] = 1;
		figure[1][2] = 1;
	}
	void SetColor()
	{
		code = 10;
	}
};
class LFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][0] = 1;
		figure[1][0] = 1;
		figure[2][0] = 1;
		figure[2][1] = 1;
	}
	void SetColor()
	{
		code = 14;
	}
};
class JFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][1] = 1;
		figure[1][1] = 1;
		figure[2][1] = 1;
		figure[2][0] = 1;
	}
	void SetColor()
	{
		code = 11;
	}
};
class TFigure : public Figure
{
public:
	void SetFigure()
	{
		figure[0][0] = 1;
		figure[0][1] = 1;
		figure[0][2] = 1;
		figure[1][1] = 1;
	}
	void SetColor()
	{
		code = 12;
	}
};
class Creator abstract
{
public:
	virtual Figure* FactoryMethod() = 0;
};

class CreatorSquareFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new SquareFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};

class CreatorLineFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new LineFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};
class CreatorSFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new SFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};
class CreatorZFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new ZFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};
class CreatorLFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new LFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};
class CreatorJFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new JFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};
class CreatorTFigure : public Creator
{
public:
	Figure* FactoryMethod() override
	{
		Figure* figure = new TFigure();
		figure->SetFigure();
		figure->SetColor();
		return figure;
	}
};
Figure* Client(Creator* creator)
{
	return creator->FactoryMethod();
}

int main()
{
	Creator* creator = new CreatorSquareFigure();
	Figure* figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;

	creator = new CreatorLineFigure();
	figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;

	creator = new CreatorSFigure();
	figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;

	creator = new CreatorZFigure();
	figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;

	creator = new CreatorLFigure();
	figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;

	creator = new CreatorJFigure();
	figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;

	creator = new CreatorTFigure();
	figure = Client(creator);
	figure->ShowFigure();
	delete creator;
	delete figure;
}

