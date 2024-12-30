#include <vector>
#include <functional>
#include <iostream>

#include "tests.h"


// Функция для запуска всех тестов, прописанных в файле tests.h
/*
'push_back' добавляет элемент в конец динамического массива (std::vector). 
Если вектор не имеет достаточно места для нового элемента, он автоматически расширяет свою емкость. 
Этот метод гарантирует, что новый элемент будет добавлен последним.
*/


void initTests() {
    // Tests for body_contains
    tests.push_back(test_body_contains1);
    tests.push_back(test_body_contains2);
    tests.push_back(test_body_contains3);

    // Tests for contains
    tests.push_back(test_contains1);
    tests.push_back(test_contains2);
    tests.push_back(test_contains3);

    // Tests for full_size
    tests.push_back(test_full_size1);
    tests.push_back(test_full_size2);
    tests.push_back(test_full_size3);

    // Tests for body_size
    tests.push_back(test_body_size1);
    tests.push_back(test_body_size2);
    tests.push_back(test_body_size3);

    // Tests for is_red
    tests.push_back(test_is_red1);
    tests.push_back(test_is_red2);
    tests.push_back(test_is_red3);

    // Tests for is_green
    tests.push_back(test_is_green1);
    tests.push_back(test_is_green2);
    tests.push_back(test_is_green3);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}