#pragma once

#include "Common/Common.h"
#include "Math/Math.h"
#include "Utils/StringUtils.h"

#include <string>
#include <algorithm>
#include <cmath>

struct IntPoint
{
public:

	int32 x;
	int32 y;

	static const IntPoint ZeroValue;
	static const IntPoint NoneValue;

public:
    
	IntPoint();

	IntPoint(int32 inX, int32 inY);

	const int32& operator()(int32 pointIndex) const;

	int32& operator()(int32 pointIndex);

	int32& operator[](int32 index);

	int32 operator[](int32 index) const;

	IntPoint& operator=(const IntPoint& other);

	bool operator==(const IntPoint& other) const;

	bool operator!=(const IntPoint& other) const;

	IntPoint& operator*=(int32 scale);

	IntPoint& operator/=(int32 divisor);

	IntPoint& operator+=(const IntPoint& other);

	IntPoint& operator-=(const IntPoint& other);

	IntPoint& operator/=(const IntPoint& other);

	IntPoint operator*(int32 scale) const;

	IntPoint operator/(int32 divisor) const;

	IntPoint operator+(const IntPoint& other) const;

	IntPoint operator-(const IntPoint& other) const;

	IntPoint operator/(const IntPoint& other) const;

	FORCEINLINE IntPoint ComponentMin(const IntPoint& other) const;

	FORCEINLINE IntPoint ComponentMax(const IntPoint& other) const;

	int32 GetMax() const;

	int32 GetMin() const;

	int32 Size() const;

	int32 SizeSquared() const;

	std::string ToString() const;

	static int32 Num();

	static IntPoint DivideAndRoundUp(IntPoint lhs, int32 divisor);

	static IntPoint DivideAndRoundUp(IntPoint lhs, IntPoint divisor);

	static IntPoint DivideAndRoundDown(IntPoint lhs, int32 divisor);
};

FORCEINLINE IntPoint::IntPoint()
	: x(0)
	, y(0)
{

}


FORCEINLINE IntPoint::IntPoint(int32 inX, int32 inY)
	: x(inX)
	, y(inY)
{

}

FORCEINLINE const int32& IntPoint::operator()(int32 pointIndex) const
{
	return (&x)[pointIndex];
}

FORCEINLINE int32& IntPoint::operator()(int32 pointIndex)
{
	return (&x)[pointIndex];
}

FORCEINLINE int32 IntPoint::Num()
{
	return 2;
}

FORCEINLINE bool IntPoint::operator==(const IntPoint& other) const
{
	return x == other.x && y == other.y;
}

FORCEINLINE bool IntPoint::operator!=(const IntPoint& other) const
{
	return x != other.x || y != other.y;
}

FORCEINLINE IntPoint& IntPoint::operator*=(int32 scale)
{
	x *= scale;
	y *= scale;
	return *this;
}

FORCEINLINE IntPoint& IntPoint::operator/=(int32 divisor)
{
	x /= divisor;
	y /= divisor;
	return *this;
}

FORCEINLINE IntPoint& IntPoint::operator+=(const IntPoint& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

FORCEINLINE IntPoint& IntPoint::operator-=(const IntPoint& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

FORCEINLINE IntPoint& IntPoint::operator/=(const IntPoint& other)
{
	x /= other.x;
	y /= other.y;
	return *this;
}

FORCEINLINE IntPoint& IntPoint::operator=(const IntPoint& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

FORCEINLINE IntPoint IntPoint::operator*(int32 scale) const
{
	return IntPoint(*this) *= scale;
}

FORCEINLINE IntPoint IntPoint::operator/(int32 divisor) const
{
	return IntPoint(*this) /= divisor;
}

FORCEINLINE int32& IntPoint::operator[](int32 index)
{
	return ((index == 0) ? x : y);
}

FORCEINLINE int32 IntPoint::operator[](int32 index) const
{
	return ((index == 0) ? x : y);
}

FORCEINLINE IntPoint IntPoint::ComponentMin(const IntPoint& other) const
{
	return IntPoint(std::min(x, other.x), std::min(y, other.y));
}

FORCEINLINE IntPoint IntPoint::ComponentMax(const IntPoint& other) const
{
	return IntPoint(std::max(x, other.x), std::max(y, other.y));
}

FORCEINLINE IntPoint IntPoint::DivideAndRoundUp(IntPoint lhs, int32 divisor)
{
	return IntPoint(MMath::DivideAndRoundUp(lhs.x, divisor), MMath::DivideAndRoundUp(lhs.y, divisor));
}

FORCEINLINE IntPoint IntPoint::DivideAndRoundUp(IntPoint lhs, IntPoint divisor)
{
	return IntPoint(MMath::DivideAndRoundUp(lhs.x, divisor.x), MMath::DivideAndRoundUp(lhs.y, divisor.y));
}

FORCEINLINE IntPoint IntPoint::DivideAndRoundDown(IntPoint lhs, int32 divisor)
{
	return IntPoint(MMath::DivideAndRoundDown(lhs.x, divisor), MMath::DivideAndRoundDown(lhs.y, divisor));
}

FORCEINLINE IntPoint IntPoint::operator+(const IntPoint& other) const
{
	return IntPoint(*this) += other;
}

FORCEINLINE IntPoint IntPoint::operator-(const IntPoint& other) const
{
	return IntPoint(*this) -= other;
}

FORCEINLINE IntPoint IntPoint::operator/(const IntPoint& other) const
{
	return IntPoint(*this) /= other;
}

FORCEINLINE int32 IntPoint::GetMax() const
{
	return std::max(x, y);
}

FORCEINLINE int32 IntPoint::GetMin() const
{
	return std::min(x, y);
}

FORCEINLINE int32 IntPoint::Size() const
{
	int64 x64 = (int64)x;
	int64 y64 = (int64)x;
	return int32(std::sqrt(float(x64 * x64 + y64 * y64)));
}

FORCEINLINE int32 IntPoint::SizeSquared() const
{
	return x * x + y * y;
}

FORCEINLINE std::string IntPoint::ToString() const
{
	return StringUtils::Printf("X=%d Y=%d", x, y);
}
