#include "candle.h"

#include <string>
#include <stdexcept>

Candle::Candle(Price _open, Price _high, Price _low, Price _close)
	: open(_open)
	, high(_high)
	, low(_low)
	, close(_close)
{
}

bool Candle::body_contains(const Price &price) const noexcept
{
	if(is_green())
	{
		const Price &max = close;
		const Price &min = open;
		return price >= min && price <= max;
	}
	else
	{
		const Price &max = open;
		const Price &min = close;
		return price >= min && price <= max;
	}
}

// Проверяет, находится ли указанная цена внутри полной свечи, включая тело и тени
bool Candle::contains(const Price &price) const noexcept
{
	return price >= low && price <= high;
}

// Вычисляет полный диапазон свечи (разница между максимальной и минимальной ценой)
double Candle::full_size() const noexcept
{
	return std::abs(low - high);
}

// Вычисляет размер тела свечи (разница между ценой открытия и закрытия)
double Candle::body_size() const noexcept
{
	return std::abs(open - close);
}

// Возвращает true, если свеча "зеленая" (цена закрытия выше цены открытия)
bool Candle::is_green() const noexcept
{
	return close > open;
}

bool Candle::is_red() const noexcept
{
	return close < open;
}