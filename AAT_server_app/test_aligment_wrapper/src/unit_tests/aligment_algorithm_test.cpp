/**
* author: Rami Mtier
* date: 10.9.2016
*/
#include "aligment_algorithms/aligment_algorithm.h"
#include "gtest/gtest.h"

class AligmentAlgorithmTest : public ::testing::Test {
protected:
      virtual void SetUp() {
      }

      virtual void TearDown() {
      }
};

TEST (AligmentAlgorithmTest, align_test)
{
    EXPECT_EQ(1,1);
}
