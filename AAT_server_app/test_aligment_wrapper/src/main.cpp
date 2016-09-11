/**
* author: Rami Mtier
* date: 10.9.2016
*/
#include <iostream>
#include "gtest/gtest.h"

int main(int ac, char* av[])
{
  ::testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
