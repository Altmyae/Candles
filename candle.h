#pragma once

#include <stdint.h>
#include <string>

using Price = double;

struct Candle
{
public:
	Price open; // Цена открытия (начало интервала)
	Price high; // Максимальная цена за интервал
	Price low;  // Минимальная цена за интервал
	Price close; 

public:
	Candle() = default;
    // конструктор, инициализирующий свечу с заданными значениями:
	Candle(Price _open, Price _high, Price _low, Price _close); 

public:
	//находится ли цена внутри тела этой свечи
	bool body_contains(const Price& price) const noexcept;

	//находится ли цена внутри тела и теней
	//другими словами, касается ли цена
	//тела или теней свечи
	bool contains(const Price& price) const noexcept;

	//возвращает размер целой свечи, включая тени
	double full_size() const noexcept;

	//возвращает размер тела свечи
	double body_size() const noexcept;

	bool is_green() const noexcept;
	bool is_red() const noexcept;

};