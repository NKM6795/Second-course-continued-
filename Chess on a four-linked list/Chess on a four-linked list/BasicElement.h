#pragma once


#include <fstream>
#include "SinglyLinked.h"


using std::ifstream;


template <typename T>
struct Vector2type
{
	T x, y;

	Vector2type() : x(T()), y(T()) {}

	Vector2type(T x, T y) : x(x), y(y) {}

	template <typename U>
	Vector2type(const Vector2type<U> &right)
	{
		*this = right;
	}

	Vector2type & operator = (const Vector2type &right)
	{
		if (this != &right)
		{
			x = right.x;
			y = right.y;
		}
		return *this;
	}

	template <typename U>
	Vector2type & operator = (const Vector2type<U> &right)
	{
		x = T(right.x);
		y = T(right.y);

		return *this;
	}

	inline Vector2type operator + (const Vector2type &right) const
	{
		return Vector2type(x + right.x, y + right.y);
	}

	inline Vector2type operator + (T value) const
	{
		return Vector2type(x + value, y + value);
	}

	inline Vector2type operator - (const Vector2type &right) const
	{
		return Vector2type(x - right.x, y - right.y);
	}

	inline Vector2type operator - (T value) const
	{
		return Vector2type(x - value, y - value);
	}

	inline Vector2type operator * (T value) const
	{
		return Vector2type(x * value, y * value);
	}

	inline Vector2type operator / (T value) const
	{
		return Vector2type(x / value, y / value);
	}

	inline bool operator < (const Vector2type &right) const
	{
		return this->x < right.x && this->y < right.y;
	}

	inline bool operator > (const Vector2type &right) const
	{
		return this->x > right.x && this->y > right.y;
	}

	inline bool operator <= (const Vector2type &right) const
	{
		return this->x <= right.x && this->y <= right.y;
	}

	inline bool operator >= (const Vector2type &right) const
	{
		return this->x >= right.x && this->y >= right.y;
	}

	inline bool operator == (const Vector2type &right) const
	{
		return this->x == right.x && this->y == right.y;
	}

	inline bool operator != (const Vector2type &right) const
	{
		return this->x != right.x || this->y != right.y;
	}
};

typedef Vector2type<int> Vector2int;
typedef Vector2type<float> Vector2float;


enum Figure
{
	Nothing = 0,
	King,
	Queen,
	Rook,
	Bishop,
	Knight,
	Pawn
};


enum ColorFigures
{
	NoColor = 0,
	White,
	Black
};


struct Cell
{
	bool moveThroughOne;
	bool firstUnique;
	union
	{
		Figure figure;
		int figureId;
	};

	union
	{
		ColorFigures color;
		int colorId;
	};

	Vector2int position;

	shared_ptr<Cell> up,
		down,
		left,
		right;

	Cell();

	void setInformation(Figure figure, ColorFigures color, int i, int j);
	void setInformation(int figureId, int colorId, int i, int j);
};


