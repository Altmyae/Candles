#pragma once

#include <iostream>
#include <cassert>
#include "candle.h" // Подключение структуры Candle

// Функция для тестирования метода body_contains
void test_body_contains() {
    Candle candle(100.0, 120.0, 90.0, 110.0);

    // Проверяем цены, которые должны быть внутри тела
    assert(candle.body_contains(105.0)); // Внутри тела
    assert(candle.body_contains(100.0)); // На уровне открытия
    assert(candle.body_contains(110.0)); // На уровне закрытия

    // Проверяем цены, которые вне тела
    assert(!candle.body_contains(95.0)); // Ниже открытия
    assert(!candle.body_contains(115.0)); // Выше закрытия

    std::cout << "test_body_contains passed!\n";
}

// Функция для тестирования метода contains
void test_contains() {
    Candle candle(100.0, 120.0, 90.0, 110.0);

    // Проверяем цены, которые должны быть внутри полной свечи
    assert(candle.contains(95.0)); // Между low и high
    assert(candle.contains(100.0)); // Равно open
    assert(candle.contains(120.0)); // Равно high
    assert(candle.contains(90.0)); // Равно low

    // Проверяем цены, которые вне полной свечи
    assert(!candle.contains(85.0)); // Ниже low
    assert(!candle.contains(125.0)); // Выше high

    std::cout << "test_contains passed!\n";
}

// Функция для тестирования размеров свечи
void test_sizes() {
    Candle candle(100.0, 120.0, 90.0, 110.0);

    // Проверяем размер полной свечи
    assert(candle.full_size() == 30.0); // High - Low = 120 - 90 = 30

    // Проверяем размер тела свечи
    assert(candle.body_size() == 10.0); // Close - Open = 110 - 100 = 10

    std::cout << "test_sizes passed!\n";
}

// Функция для тестирования цветов свечи
void test_colors() {
    Candle greenCandle(100.0, 120.0, 90.0, 110.0);
    Candle redCandle(110.0, 120.0, 90.0, 100.0);

    // Проверяем зелёную свечу
    assert(greenCandle.is_green());
    assert(!greenCandle.is_red());

    // Проверяем красную свечу
    assert(redCandle.is_red());
    assert(!redCandle.is_green());

    std::cout << "test_colors passed!\n";
}

// Общая функция для запуска всех тестов
void run_all_tests() {
    test_body_contains();
    test_contains();
    test_sizes();
    test_colors();
    std::cout << "All tests passed!\n";
}



//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

// Метод contains проверяет, находится ли цена внутри тела или теней свечи (от low до high)
bool test_contains1() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.contains(18.0); // В пределах свечи
}

bool test_contains2() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.contains(4.0); // Ниже минимума (low)
}

bool test_contains3() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.contains(20.0); // На границе (high)
}




// Метод full_size возвращает расстояние между high и low
bool test_full_size1() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.full_size() == 15.0; // 20.0 - 5.0 = 15.0
}

bool test_full_size2() {
    Candle candle{10.0, 10.0, 10.0, 10.0};
    return candle.full_size() == 0.0; // Все значения одинаковые
}

bool test_full_size3() {
    Candle candle{15.0, 25.0, 10.0, 20.0};
    return candle.full_size() == 15.0; // 25.0 - 10.0 = 15.0
}


// Метод body_size возвращает расстояние между open и close
bool test_body_size1() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.body_size() == 5.0; // 15.0 - 10.0 = 5.0
}

bool test_body_size2() {
    Candle candle{15.0, 20.0, 5.0, 10.0};
    return candle.body_size() == 5.0; // 15.0 - 10.0 = 5.0
}

bool test_body_size3() {
    Candle candle{10.0, 20.0, 5.0, 10.0};
    return candle.body_size() == 0.0; // Open и Close одинаковы
}


//Тесты для метода is_red. Метод is_red возвращает true, если close < open 
bool test_is_red1() {
    Candle candle{15.0, 20.0, 5.0, 10.0};
    return candle.is_red(); // Свеча медвежья
}

bool test_is_red2() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.is_red() == false; // Свеча не медвежья
}

bool test_is_red3() {
    Candle candle{10.0, 20.0, 5.0, 10.0};
    return candle.is_red() == false; // Open == Close
}

// Тесты для метода is_green. Метод is_green возвращает true, если close > open
bool test_is_green1() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.is_green(); // Свеча бычья
}

bool test_is_green2() {
    Candle candle{15.0, 20.0, 5.0, 10.0};
    return candle.is_green() == false; // Свеча не бычья
}

bool test_is_green3() {
    Candle candle{10.0, 20.0, 5.0, 10.0};
    return candle.is_green() == false; // Open == Close
}


// Тесты для метода body_contains
// Метод body_contains проверяет, находится ли заданная цена внутри тела свечи (от open до close).
bool test_body_contains1() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.body_contains(12.0); // Внутри тела свечи
}

bool test_body_contains2() {
    Candle candle{15.0, 20.0, 5.0, 10.0};
    return candle.body_contains(14.0) == false; // Вне тела свечи
}

bool test_body_contains3() {
    Candle candle{10.0, 20.0, 5.0, 15.0};
    return candle.body_contains(10.0); // На границе тела свечи (open)
}
