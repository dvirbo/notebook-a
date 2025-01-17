#include "doctest.h"
#include "Notebook.hpp"

#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;
using namespace ariel;
using ariel::Direction;
const int DEFAULT_SIZE = 100;



TEST_CASE("CHECK NEGATIVE INPUT")
{
    Notebook nb1;
    CHECK_THROWS(nb1.write(-1, 50, 50, Direction::Horizontal, "abcd"));
    CHECK_THROWS(nb1.write(50, -1, 50, Direction::Horizontal, "abcd"));
    CHECK_THROWS(nb1.write(50, 50, -1, Direction::Horizontal, "abcd"));

    CHECK_THROWS(nb1.read(-1, 50, 50, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.read(50, -1, 50, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.read(50, 50, -1, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.read(50, 50, -1, Direction::Horizontal, -5));

    CHECK_THROWS(nb1.erase(-1, 50, 50, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.erase(50, -1, 50, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.erase(50, 50, -1, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.erase(50, 50, -1, Direction::Horizontal, -5));
}
TEST_CASE("LINE POS BIGGER THAN 100")
{
    Notebook nb1;
    CHECK_THROWS(nb1.write(50, 50, 101, Direction::Horizontal, "abcd"));
    CHECK_THROWS(nb1.read(50, 50, 101, Direction::Horizontal, 5));
    CHECK_THROWS(nb1.erase(50, 50, 101, Direction::Horizontal, 5));
}

TEST_CASE("READ MORE THAN 100 CHARS"){
    Notebook nb1;
    CHECK_NOTHROW(nb1.write(50, 50, 51, Direction::Horizontal, "abcdefggggg"));
    CHECK_THROWS(nb1.write(50, 50, 51, Direction::Horizontal, "~~~~"));
    CHECK_THROWS(nb1.write(50, 50, 51, Direction::Horizontal, "~"));
    CHECK_THROWS(nb1.write(50, 50, 51, Direction::Horizontal, "~"));
    CHECK_THROWS(nb1.read(50, 50, 101, Direction::Horizontal, 101));
    CHECK_THROWS(nb1.erase(50, 50, 101, Direction::Horizontal, 101));
    


}
