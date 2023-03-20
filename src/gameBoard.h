#ifndef SOLITAIRE_GAMEBOARD_H
#define SOLITAIRE_GAMEBOARD_H
#endif
#include <string>
#define PILESIZE 20
#define STOCKSIZE 24
#define WASTESIZE 24
#define FOUNDATIONSIZE 13


using namespace std;

class Piles{
public:
    Piles(string deckArray[52]);
    string pile0[PILESIZE], pile1[PILESIZE], pile2[PILESIZE], pile3[PILESIZE], pile4[PILESIZE], pile5[PILESIZE], pile6[PILESIZE];// open card piles
    string closed0[PILESIZE], closed1[PILESIZE], closed2[PILESIZE], closed3[PILESIZE], closed4[PILESIZE], closed5[PILESIZE], closed6[PILESIZE]; //closed card piles
    int moveFromPile(char source, int index, char destination, ofstream& output); //move cards from source pile to destination pile
    int moveCard(string card, char destination);//auxiliary method for moving cards from pile to pile
    int open(char pileNumber, ofstream& output); //open card from end of the closed pile according to open pile
};

class Stock {
public:
    string stock[STOCKSIZE];
    Stock(string deckArray[52]);
};


class Waste{
public:
    string waste[WASTESIZE];
    Stock openFromStock(Stock stock);
    Piles moveFromWaste(Piles piles, char destination ,ofstream& output); //move card from end of the waste to destination pile
};


class Foundation{
public:
    string foundationH[FOUNDATIONSIZE], foundationD[FOUNDATIONSIZE], foundationS[FOUNDATIONSIZE], foundationC[FOUNDATIONSIZE];
    Piles moveToFoundationP(Piles piles, char pileNumber, ofstream& output);//move cards from piles to foundation
    Waste moveToFoundationW(Waste waste, ofstream& output);//move cards from waste to foundation
    int moveCard(string card, ofstream& output);//auxiliary method for moving cards to foundations from piles or waste
    Piles moveFromFoundation(Piles piles, char source, char destination, ofstream& output); //move last card of given source foundation to destination pile
};




