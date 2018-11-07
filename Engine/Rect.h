#pragma once
#include "Vec2.h"
template <typename T>
class Rect
{
public:
	T left;
	T right;
	T top;
	T bottom;
	Rect(T left_in, T right_in, T top_in, T bottom_in)
		:
		left(left_in),
		right(right_in),
		top(top_in),
		bottom(bottom_in)
	{
	}

	Rect(const Vec2& topLeft, const Vec2 & bottomRight)
		:
		Rect(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	{
	}

	Rect(const Vec2& topLeft, T width, T height)
		:
		Rect(topLeft, topLeft + Vec2(width, height))
	{
	}

	bool Rect::IsOverlappingWith(const Rect& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool Rect::IsContainedBy(const Rect & other) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	bool Rect::Contains(const Vec2& point) const
	{
		return point.x >= left && point.x < right && point.y >= top && point.y < bottom;
	}

	Rect Rect::FromCenter(const Vec2 & center, T halfWidth, T halfHeight)
	{
		const Vec2 half(halfWidth, halfHeight);
		return Rect(center - half, center + half);
	}

	Rect Rect::GetExpanded(T offset) const
	{
		return Rect(left - offset, right + offset, top - offset, bottom + offset);
	}

	Vec2 Rect::GetCenter() const
	{
		return Vec2((left + right) / 2, (top + bottom) / 2);
	}

	void MoveBy(Vec2 _pos) 
	{
		left += _pos.x;
		right += _pos.x;
		top += _pos.y;
		bottom += _pos.y;

	}

	void Scale(float scale_x, float scale_y)
	{
		left *= scale_x;
		right *= scale_x;
		top *= scale_y;
		bottom *= scale_y;
	}
};

