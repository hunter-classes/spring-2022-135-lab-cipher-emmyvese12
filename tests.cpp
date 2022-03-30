#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
// g++ -std=c++11 -c tests.cpp


TEST_CASE("Decoding Caesar Cipher Sentences"){
    CHECK(solve("Lyocph Rlcqtpwo td esp mpde datopcxly!") == "Andrew Garfield is the best spiderman!");
    CHECK(solve("Zkdw lv julhi, li qrw oryh shuvhyhulqj?") == "What is grief, if not love persevering?");
    CHECK(solve("Zsh'g uc gss hvs Bcfhvsfb Zwuvhg bslh kwbhsf") == "Let's go see the Northern Lights next winter");
    CHECK(solve("Xmqi jsv hmrriv, alex asyph csy pmoi xs svhiv?") == "Time for dinner, what would you like to order?");
    CHECK(solve("jpd, t htww opwtgpc estd yzep ez esp nsltcxly ctrse lhlj.") == "yes, i will deliver this note to the chairman right away.");

}
// note that short words most likely don't work
TEST_CASE("Decoding Caesar Cipher Short Words which DON'T WORK"){
    CHECK(solve("nkrru") != "hello");
    CHECK(solve("owwi") != "emmy");
    CHECK(solve("czydspi") != "spotify");
    CHECK(solve("xalqrmb") != "orchids");

}

TEST_CASE("Index of Letter in the Alphabet"){
    CHECK(indexOfLetter('l') == 11);
    CHECK(indexOfLetter('b') == 1);
    CHECK(indexOfLetter('r') == 17);
    CHECK(indexOfLetter('H') == 7);
    CHECK(indexOfLetter('U') == 20);
    CHECK(indexOfLetter('A') == 0);
    
}

TEST_CASE("Shift String by 1 Character"){
    CHECK(shiftString("hello there") == "ifmmp uifsf");
    CHECK(shiftString("by the shore") == "cz uif tipsf");
    CHECK(shiftString("rudolph the red nosed reindeer") == "svepmqi uif sfe optfe sfjoeffs");
    

}
