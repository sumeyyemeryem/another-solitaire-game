#include <iostream>
#include <fstream>
#include "gameBoard.h"
using namespace std;

int print(Piles piles, Stock stock, Waste waste,int state, Foundation foundations, ofstream& output){
    //for printing stock
    int n = -1;
    for(int k = 0; k < 24; k++){ //check if the stock has a card
        if(stock.stock[k].size() == 3){
            n++;
            output << "@@@" << " ";
            break;
        }
    }
    if(n == -1){
        output << "___" << " ";
    }


    //for printing waste
    int length = 0;
    for(int k = 0; k < 24; k++) {
        if(waste.waste[k].size() == 3){
            length++; //keep the number of cards in the waste
        }
    }
    if(waste.waste[0].size() != 3){// no card in the waste
        output << "___ ___ ___         ";
    }
    else if (state == 3){//no card taken from waste
        output << waste.waste[length-3] << " " << waste.waste[length-2] << " " << waste.waste[length-1] << "         "; //end of the waste section
    }
    else if(state == 2){//one card taken from waste
        output << waste.waste[length - 2] << " " << waste.waste[length - 1] << " ___         ";
    }
    else {//two or more card taken from waste
        output <<waste.waste[length-1] << " ___ ___         ";
    }



    //for printing foundation hearts
    if(foundations.foundationH[0].size() != 3){ //check if the first element of the foundation has a card if not then the foundation is empty
        output << "___" << " ";
    }
    else{
        int last = -1;
        for(auto & k : foundations.foundationH) {
            if(k.size() == 3){
                last++; //keep the last index which have a card
            }
        }
        output << foundations.foundationH[last] << " ";
    }

    //for printing foundation diamonds
    if(foundations.foundationD[0].size() != 3){
        output << "___ ";
    }
    else{
        int last = -1;
        for(auto & k : foundations.foundationD) {
            if(k.size() == 3){
                last++; //keep the last index which have a card
            }
        }
        output << foundations.foundationD[last] << " ";
    }

    //for printing foundation spades
    if(foundations.foundationS[0].size() != 3){
        output << "___ ";
    }
    else{
        int last = -1;
        for(auto & k : foundations.foundationS) {
            if(k.size() == 3){
                last++; //keep the last index which have a card
            }
        }
        output << foundations.foundationS[last] << " ";
    }

    //for printing foundation clubs
    if(foundations.foundationC[0].size() != 3){
        output << "___ ";
    }
    else{
        int last = -1;
        for(auto & k : foundations.foundationC) {
            if(k.size() == 3){
                last++; //keep the last index which have a card
            }
        }
        output << foundations.foundationC[last] << " ";
    }
    output << endl << endl; //end of the foundation section

    //for printing piles
    int amount = 0;
    for(int i = 0; i < 20; i ++){
        if(piles.closed0[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
        if(piles.closed1[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
        if(piles.closed2[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
        if(piles.closed3[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
        if(piles.closed4[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
        if(piles.closed5[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
        if(piles.closed6[i].size() == 3 ){
            amount++; // keep the total number of cards
        }
    }
    int number = 0;//number of printed cards
    for(int i = 0; i < 20; i ++){
        if(piles.closed0[i].size() == 3){
            output << piles.closed0[i] << "   ";
            number++;
        }
        else{
            output << "      ";
        }
        if(piles.closed1[i].size() == 3){
            output << piles.closed1[i] << "   ";
            number++;
        }
        else{
            output << "      ";
        }
        if(piles.closed2[i].size() == 3){
            output << piles.closed2[i] << "   ";
            number++;
        }
        else{
            output << "      ";
        }
        if(piles.closed3[i].size() == 3){
            output << piles.closed3[i] << "   ";
            number++;
        }
        else{
            output << "      ";
        }
        if(piles.closed4[i].size() == 3){
            output << piles.closed4[i] << "   ";
            number++;
        }
        else{

            output << "      ";
        }
        if(piles.closed5[i].size() == 3){
            output << piles.closed5[i] << "   ";
            number++;
        }
        else{
            output << "      ";
        }
        if(piles.closed6[i].size() == 3){
            output << piles.closed6[i] << "   ";
            number++;
        }
        else{
            output << "      ";
        }

        output << endl;

        if(number == amount){// if all the cards are printed leave the loop
            break;
        }
    }
    output << endl;
    return 0;
}

int main(int argc, char *argv[]) {

    ifstream deckFile(argv[1]);
    ifstream commandFile(argv[2]);
    ofstream outputFile;
    outputFile.open(argv[3]);

    string deckArray[52];
    if(!deckFile.fail())
    {
        int i = 51;
        string line;
        while(getline(deckFile, line)){
            if(line != "\n"){
                deckArray[i] = line;
                i--;
            }
        }
        deckFile.close();
    }
    Piles piles(deckArray);
    Stock stock(deckArray);
    Waste waste;
    Foundation foundations;

    outputFile << endl;
    print(piles,stock,waste,0,foundations,outputFile); //print the beginning of the game board

    int state;
    int length;
    if(!commandFile.fail())
    {
        string line;
        while(getline(commandFile, line)){
            if(line != "\n"){
                if (line == "exit"){ //exiting case
                    outputFile << line << endl << endl;
                    outputFile << "****************************************" << endl << endl;
                    outputFile << "Game Over!" << endl;
                    outputFile.close();
                    return 0;
                }
                else if(line == "open from stock"){
                    outputFile << line << endl << endl;
                    length = 0;
                    for(int k = 0; k < 24; k++){ if(stock.stock[k].size() == 3){ length++;}}//keep the length of the stock

                    if(length < 3){state = length;}
                    else{state = 3;}

                    stock = waste.openFromStock(stock);//call the function
                    outputFile << "****************************************" << endl << endl;
                    print(piles, stock, waste, state, foundations, outputFile); //print the game board
                }
                else if(line.at(5) == 't'){
                    if(line.at(19) == 'p'){//move to foundation from pile
                        outputFile << line << endl << endl;
                        piles = foundations.moveToFoundationP(piles, line.at(24),outputFile);
                        outputFile << "****************************************" << endl << endl;
                        print(piles, stock, waste, state, foundations, outputFile); //print the game board
                    }
                    else{//move to foundation from waste
                        outputFile << line << endl << endl;
                        length = 0;
                        for(int k = 0; k < 24; k++){ if(waste.waste[k].size() == 3){ length++;}}
                        waste = foundations.moveToFoundationW(waste,outputFile);
                        if(waste.waste[length-1].size() != 3){state--;}//if last card of the waste has been moved change the state
                        outputFile << "****************************************" << endl << endl;
                        print(piles, stock, waste, state, foundations, outputFile); //print the game board
                    }
                }
                else if(line.at(5) == 'p'){//move a card from a pile to another pile
                    outputFile << line << endl << endl;
                    int index;
                    char destination;
                    if(line.size() == 16){
                        string s1 = line;
                        string s2 = s1.erase(0,12);
                        string s3 = s2.erase(2,2);
                        index = stoi(s2);
                        destination = line.at(15);
                    }
                    else{
                        unsigned char uc = line.at(12);
                        index = uc - 48;
                        destination = line.at(14);
                    }
                    piles.moveFromPile(line.at(10), index, destination,outputFile);
                    outputFile << "****************************************" << endl << endl;
                    print(piles, stock, waste, state, foundations, outputFile); //print the game board
                }
                else if(line.at(5) == 'w'){//move a card from waste to a pile
                    outputFile << line << endl << endl;
                    length = 0;
                    for(int k = 0; k < 24; k++){ if(waste.waste[k].size() == 3){ length++;}}//keep the length of the waste
                    piles = waste.moveFromWaste(piles, line.at(11),outputFile);
                    if(waste.waste[length-1].size() != 3){state--;}//if last card of the waste has been moved change the state

                    outputFile << "****************************************" << endl << endl;
                    print(piles, stock, waste, state, foundations, outputFile); //print the game board
                }
                else if(line.at(5) == 'f'){//move a card from foundation to a pile
                    outputFile << line << endl << endl;
                    piles = foundations.moveFromFoundation(piles, line.at(16), line.at(18),outputFile);
                    outputFile << "****************************************" << endl << endl;
                    print(piles, stock, waste, state, foundations, outputFile); //print the game board
                }
                else if(line.at(0) == 'o'){
                    outputFile << line << endl << endl;
                    piles.open(line.at(5),outputFile);
                    outputFile << "****************************************" << endl << endl;
                    print(piles, stock, waste, state, foundations, outputFile); //print the game board
                }
            }
        }
        outputFile << "****************************************" << endl << endl;
        outputFile << "You Win!" << endl << endl;
        outputFile << "Game Over!" << endl;
        outputFile.close();
        commandFile.close();
    }
    return 0;
}




