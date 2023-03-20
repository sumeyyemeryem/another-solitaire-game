#include "gameBoard.h"
#include <iostream>
#include <fstream>
#include <sstream>

Piles::Piles(string *deckArray) {
    pile0[0] = deckArray[0]; //0
    pile1[0] = deckArray[1], pile1[1] = deckArray[7]; //1 7
    pile2[0] = deckArray[2], pile2[1] = deckArray[8],  pile2[2] = deckArray[13]; //2 8 13
    pile3[0] = deckArray[3], pile3[1] = deckArray[9],  pile3[2] = deckArray[14], pile3[3] = deckArray[18]; //3 9 14 18
    pile4[0] = deckArray[4], pile4[1] = deckArray[10], pile4[2] = deckArray[15], pile4[3] = deckArray[19], pile4[4] = deckArray[22]; //4 10 15 19 22
    pile5[0] = deckArray[5], pile5[1] = deckArray[11], pile5[2] = deckArray[16], pile5[3] = deckArray[20], pile5[4] = deckArray[23], pile5[5] = deckArray[25]; //5 11 16 20 23 25
    pile6[0] = deckArray[6], pile6[1] = deckArray[12], pile6[2] = deckArray[17], pile6[3] = deckArray[21], pile6[4] = deckArray[24], pile6[5] = deckArray[26], pile6[6] = deckArray[27]; //6 12 17 21 24 26 27

    //closed piles
    closed0[0] = deckArray[0];
    closed1[0] = "@@@", closed1[1] = deckArray[7];
    closed2[0] = "@@@", closed2[1] = "@@@", closed2[2] = deckArray[13];
    closed3[0] = "@@@", closed3[1] = "@@@", closed3[2] = "@@@", closed3[3] = deckArray[18];
    closed4[0] = "@@@", closed4[1] = "@@@", closed4[2] = "@@@", closed4[3] = "@@@", closed4[4] = deckArray[22];
    closed5[0] = "@@@", closed5[1] = "@@@", closed5[2] = "@@@", closed5[3] = "@@@", closed5[4] = "@@@", closed5[5] = deckArray[25];
    closed6[0] = "@@@", closed6[1] = "@@@", closed6[2] = "@@@", closed6[3] = "@@@", closed6[4] = "@@@", closed6[5] = "@@@", closed6[6] = deckArray[27];
}

int Piles::open(char pileNumber, ofstream& output) {
    int length = 0;
    switch (pileNumber) {
        case '0' :
            for(int i = 0; i < 20; i++){
                if(pile0[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed0[length-1] == "@@@"){ //if the pile has cards and the last card of the closed pile is closed then open it
                closed0[length-1] = pile0[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;

        case '1' :
            for(int i = 0; i < 20; i++){
                if(pile1[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed1[length-1] == "@@@"){
                closed1[length-1] = pile1[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;

        case '2' :
            for(int i = 0; i < 20; i++){
                if(pile2[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed2[length-1] == "@@@"){
                closed2[length-1] = pile2[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;

        case '3' :
            for(int i = 0; i < 20; i++){
                if(pile3[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed3[length-1] == "@@@"){
                closed3[length-1] = pile3[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;

        case '4' :
            for(int i = 0; i < 20; i++){
                if(pile4[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed4[length-1] == "@@@"){
                closed4[length-1] = pile4[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;

        case '5' :
            for(int i = 0; i < 20; i++){
                if(pile5[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed5[length-1] == "@@@"){
                closed5[length-1] = pile5[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;

        default:
            for(int i = 0; i < 20; i++){
                if(pile6[i].size() == 3){
                    length++;//keep the number of cards in the pile
                }
            }
            if(length!= 0 && closed6[length-1] == "@@@"){
                closed6[length-1] = pile6[length-1];
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
            break;
    }




    return 0;
}

int Piles::moveFromPile(char source, int index, char destination, ofstream& output) {
    int state;
    int length = 0;
    switch (source) {
        case '0':
            for(int i = 0; i < 20; i++){
                if(pile0[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;//corresponding array index to the given card index
            if (pile0[index].size() != 3 || closed0[index] == "@@@") {//if command try to move a card from an empty pile array or move a card which is closed
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
            for(int i = index; i < length; i++){
                if(pile0[i].size() == 3) {
                    state = moveCard(pile0[i], destination);
                }
                if(state == 1){//to indicate that card has been moved
                    pile0[i] = "0";
                    closed0[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
        case '1':
            for(int i = 0; i < 20; i++){
                if(pile1[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;
            if (pile1[index].size() != 3 || closed1[index] == "@@@"){
                output << "Invalid Move!" << endl << endl;
                return 0;
            }

            for(int i = index; i < length; i++){
                if(pile1[i].size() == 3) {
                    state = moveCard(pile1[i], destination);
                }
                if(state == 1){//to indicate that card has been moved
                    pile1[i] = "0";
                    closed1[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
        case '2':
            for(int i = 0; i < 20; i++){
                if(pile2[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;
            if (pile2[index].size() != 3 || closed2[index] == "@@@"){
                output << "Invalid Move!" << endl << endl;
                return 0;
            }

            for(int i = index; i < length; i++){
                if(pile2[i].size() == 3) {
                    state = moveCard(pile2[i], destination);
                }
                if(state == 1){//to indicate that card has been moved
                    pile2[i] = "0";
                    closed2[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
        case '3':
            for(int i = 0; i < 20; i++){
                if(pile3[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;
            if (pile3[index].size() != 3 || closed3[index] == "@@@"){
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
            for(int i = index; i < length; i++){
                if(pile3[i].size() == 3) {
                    state = moveCard(pile3[i], destination);
                }
                if(state == 1){//to indicate that card has been moved
                    pile3[i] = "0";
                    closed3[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
        case '4':
            for(int i = 0; i < 20; i++){
                if(pile4[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;
            if (pile4[index].size() != 3 || closed4[index] == "@@@"){
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
            for(int i = index; i < length; i++){
                if(pile4[i].size() == 3) {
                    state = moveCard(pile4[i], destination);
                }
                else{
                    break;
                }
                if(state == 1){//to indicate that card has been moved
                    pile4[i] = "0";
                    closed4[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
        case '5':
            for(int i = 0; i < 20; i++){
                if(pile5[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;
            if (pile5[index].size() != 3 || closed5[index] == "@@@"){
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
            for(int i = index; i < length; i++){
                if(pile5[i].size() == 3) {
                    state = moveCard(pile5[i], destination);
                }
                else{
                    break;
                }
                if(state == 1){//to indicate that card has been moved
                    pile5[i] = "0";
                    closed5[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
        default:
            for(int i = 0; i < 20; i++){
                if(pile6[i].size() == 3) {
                    length++;
                }
            }
            index = (length - index)-1;
            if (pile6[index].size() != 3 || closed6[index] == "@@@"){
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
            for(int i = index; i < length; i++){
                if(pile6[i].size() == 3) {
                    state = moveCard(pile6[i], destination);
                }
                else{
                    break;
                }
                if(state == 1){//to indicate that card has been moved
                    pile6[i] = "0";
                    closed6[i] = "0";
                }
                else{
                    output << "Invalid Move!" << endl << endl;
                    return 0;
                }
            }
            break;
    }
    return 0;
}

int Piles::moveCard(string card, char destination) {

    if(destination == '0'){
        if(pile0[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile0[0] = card;
                closed0[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile0[i].size() != 3) {
                    string s1 = pile0[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile0[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed0[i-1] != "@@@"){//if the topmost card of the destination pile is one number higher and not closed
                        // and different color move given card to destination pile
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile0[i] = card;
                            closed0[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile0[i] = card;
                            closed0[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    if(destination == '1'){
        if(pile1[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile1[0] = card;
                closed1[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile1[i].size() != 3) {
                    string s1 = pile1[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile1[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed1[i-1] != "@@@"){
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile1[i] = card;
                            closed1[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile1[i] = card;
                            closed1[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    if(destination == '2'){
        if(pile2[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile2[0] = card;
                closed2[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile2[i].size() != 3) {
                    string s1 = pile2[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile2[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed2[i-1] != "@@@"){
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile2[i] = card;
                            closed2[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile2[i] = card;
                            closed2[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    if(destination == '3'){
        if(pile3[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile3[0] = card;
                closed3[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile3[i].size() != 3) {
                    string s1 = pile3[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile3[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed3[i-1] != "@@@"){
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile3[i] = card;
                            closed3[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile3[i] = card;
                            closed3[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    if(destination == '4'){
        if(pile4[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile4[0] = card;
                closed4[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile4[i].size() != 3) {
                    string s1 = pile4[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile4[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed4[i-1] != "@@@"){
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile4[i] = card;
                            closed4[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile4[i] = card;
                            closed4[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    if(destination == '5'){
        if(pile5[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile5[0] = card;
                closed5[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile5[i].size() != 3) {
                    string s1 = pile5[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile5[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed5[i-1] != "@@@"){
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile5[i] = card;
                            closed5[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile5[i] = card;
                            closed5[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }
    if(destination == '6'){
        if(pile6[0].size() != 3){ //if the first element of pile array is empty then put the card at beginning
            string s = card;
            if(s.erase(0,1) == "13"){
                pile6[0] = card;
                closed6[0] = card;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            for(int i = 1; i < 20; i++){
                if(pile6[i].size() != 3) {

                    string s1 = pile6[i-1];
                    string s2 = card;

                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }

                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    char color1 = pile6[i-1].at(0);
                    char color2 = card.at(0);
                    //D,H color red && C,S color black
                    if (number1 - number2 == 1 && closed6[i-1] != "@@@"){
                        if((color1 == 'D' || color1 == 'H') && (color2 == 'C' || color2 == 'S')) {
                            pile6[i] = card;
                            closed6[i] = card;
                            return 1;
                        }
                        if((color1 == 'C' || color1 == 'S') && (color2 == 'D' || color2 == 'H')){
                            pile6[i] = card;
                            closed6[i] = card;
                            return 1;
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0; //if given cases does not fit into the any of the conditions return false means an invalid move
}


Stock::Stock(string *deckArray) {
    for(int k = 28; k < 52; k++){
        stock[k-28] = deckArray[k];
    }
}


Stock Waste::openFromStock(Stock stock) {
    //if stock is not empty take 3 or less elements from it and put into waste

    int m = 0;
    for(int i = 0; i < 24; i++){
        if(waste[i].size() != 3){
            m = i;//first index which is empty
            break;
        }
    }
    int n = 0;
    for(int i = 0; i < 24; i++){
        if(stock.stock[i].size() == 3 && n < 3){
            n++; //for taking at most three elements from stock to waste
            waste[m] = stock.stock[i];
            m++;
            stock.stock[i] = '0'; //indicate places for taken elements are now empty
            }
        }
    if(n == 0) { //which means there is no card in the stock
        for(int k = 0; k < 24; k++){
            stock.stock[k] = waste[k];//fill the stack
            waste[k] = "0";//empty the waste

        }
    }
    return stock;
}

Piles Waste::moveFromWaste(Piles piles, char destination, ofstream& output) {
    string card;
    int length = 0;
    int state;
    for(int k = 0; k < 24; k++) {
        if(waste[k].size() == 3){
            length++;
            card = waste[k];
        }
    }
    if (length == 0){//if command try to move a card from empty waste
        output << "Invalid Move!" << endl << endl;
    }
    else{
        state = piles.moveCard(card, destination);
        if(state == 1){
            waste[length-1] = "0"; // to indicate that last element of the waste has been replaced
        }
        else{
            output << "Invalid Move!" << endl << endl;
        }
    }
    return piles;
}


Piles Foundation::moveToFoundationP(Piles piles, char pileNumber, ofstream& output) {
    string card;
    int length = 0;
    int state;
    switch (pileNumber) {
        case '0' :
            for(int k = 0; k < 20; k++){
                if(piles.pile0[k].size() == 3) {
                    length++;
                    card = piles.pile0[k];
                }
            }
            if(length == 0 || piles.closed0[length-1] == "@@@" ){//if command try to move a  card from an empty pile or move a card which is closed
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile0[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed0[length-1] = "0";
                }
            }
            break;
        case '1' :
            for(int k = 0; k < 20; k++){
                if(piles.pile1[k].size() == 3) {
                    length++;
                    card = piles.pile1[k];
                }
            }
            if(length == 0 || piles.closed1[length-1] == "@@@"){
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile1[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed1[length-1] = "0";
                }
            }
            break;
        case '2' :
            for(int k = 0; k < 20; k++){
                if(piles.pile2[k].size() == 3) {
                    length++;
                    card = piles.pile2[k];
                }
            }
            if(length == 0 || piles.closed2[length-1] == "@@@"){
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile2[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed2[length-1] = "0";
                }
            }
            break;
        case '3' :
            for(int k = 0; k < 20; k++){
                if(piles.pile3[k].size() == 3) {
                    length++;
                    card = piles.pile3[k];
                }
            }
            if(length == 0 || piles.closed3[length-1] == "@@@"){
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile3[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed3[length-1] = "0";
                }
            }
            break;
        case '4' :
            for(int k = 0; k < 20; k++){
                if(piles.pile4[k].size() == 3) {
                    length++;
                    card = piles.pile4[k];
                }
            }
            if(length == 0 || piles.closed4[length-1] == "@@@"){
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile4[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed4[length-1] = "0";
                }
            }
            break;
        case '5' :
            for(int k = 0; k < 20; k++){
                if(piles.pile5[k].size() == 3) {
                    length++;
                    card = piles.pile5[k];
                }
            }
            if(length == 0 || piles.closed5[length-1] == "@@@"){
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile5[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed5[length-1] = "0";
                }
            }
            break;
        default:
            for(int k = 0; k < 20; k++){
                if(piles.pile6[k].size() == 3) {
                    length++;
                    card = piles.pile6[k];
                }
            }
            if(length == 0 || piles.closed6[length-1] == "@@@"){
                output << "Invalid Move!" << endl << endl;
            }
            else{
                state = moveCard(card,output);
                if (state == 1) {
                    piles.pile6[length-1] = "0";//to indicate that last card has been replaced
                    piles.closed6[length-1] = "0";
                }
            }
            break;
    }
    return piles;
}

Waste Foundation::moveToFoundationW(Waste waste, ofstream& output) {
    string card;
    int length = 0;
    int state;
    for(int k = 0; k < 24; k++) {
        if(waste.waste[k].size() == 3){
            length++;
            card = waste.waste[k];
        }
    }
    if (length == 0){
        output << "Invalid Move!" << endl << endl;
    }
    else{
        state = moveCard(card, output);
        if(state == 1){
            waste.waste[length-1] = "0";
        }
    }

    return waste;
}

int Foundation::moveCard(string card, ofstream& output) { //get the last card from any pile and put it into corresponding foundation
    if(card.at(0) == 'H') {
        if(foundationH[0].size() != 3 ){ //if the first element of foundation array is empty and card is an ace then put the card at beginning
            if(card.at(1) == '0' && card.at(2) == '1'){
                foundationH[0] = card;
                return 1;
            }
            else{
                output << "Invalid Move!" << endl << endl;
                return 0;
            }

        }
        else{
            for(int i = 1; i < 13; i++){
                if(foundationH[i].size() != 3) {
                    string s1 = foundationH[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    if (number2 - number1 == 1){//if cards predecessor is the topmost card of the foundation put the card end of the array
                        foundationH[i] = card;
                        return 1;
                    }
                    else{
                        output << "Invalid Move!" << endl << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(card.at(0) == 'D') {
        if(foundationD[0].size() != 3){ //if the first element of foundation array is empty then put the card at beginning
            if(card.at(1) == '0' && card.at(2) == '1'){
                foundationD[0] = card;
                return 1;
            }
            else{
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
        }
        else{
            for(int i = 1; i < 13; i++){
                if(foundationD[i].size() != 3) {
                    string s1 = foundationD[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    if (number2 - number1 == 1){//if cards predecessor is the topmost card of the foundation put the card end of the array
                        foundationD[i] = card;
                        return 1;
                    }
                    else{
                        output << "Invalid Move!" << endl << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(card.at(0) == 'S') {
        if(foundationS[0].size() != 3){ //if the first element of foundation array is empty then put the card at beginning
            if(card.at(1) == '0' && card.at(2) == '1'){
                foundationS[0] = card;
                return 1;
            }
            else{
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
        }
        else{
            for(int i = 1; i < 13; i++){
                if(foundationS[i].size() != 3) {
                    string s1 = foundationS[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    if (number2 - number1 == 1){//if cards predecessor is the topmost card of the foundation put the card end of the array
                        foundationS[i] = card;
                        return 1;
                    }
                    else{
                        output << "Invalid Move!" << endl << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(card.at(0) == 'C'){
        if(foundationC[0].size() != 3){ //if the first element of foundation array is empty then put the card at beginning
            if(card.at(1) == '0' && card.at(2) == '1'){
                foundationC[0] = card;
                return 1;
            }
            else{
                output << "Invalid Move!" << endl << endl;
                return 0;
            }
        }
        else{
            for(int i = 1; i < 13; i++){
                if(foundationC[i].size() != 3) {
                    string s1 = foundationC[i-1];
                    string s2 = card;
                    if(s1.at(1) == '0'){
                        s1 = s1.erase(0,2);
                    }
                    else{
                        s1 = s1.erase(0,1);
                    }
                    if(s2.at(1) == '0'){
                        s2 = s2.erase(0,2);
                    }
                    else{
                        s2 = s2.erase(0,1);
                    }
                    int number1 = stoi(s1);
                    int number2 = stoi(s2);
                    if (number2 - number1 == 1){//if cards predecessor is the topmost card of the foundation put the card end of the array
                        foundationC[i] = card;
                        return 1;
                    }
                    else{
                        output << "Invalid Move!" << endl << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

Piles Foundation::moveFromFoundation(Piles piles, char source, char destination, ofstream& output) {

    int length = 0;
    int state;
    if(source == '0'){//foundation hearts
        for(int i = 0; i < 13; i++){
            if(foundationH[i].size() != 3) {
                length++;//keep the number of cards in the foundation
            }
        }
        if(length == 0){
            output << "Invalid Move!" << endl << endl;
        }
        else{
            state = piles.moveCard(foundationH[length-1], destination);
            if(state == 1){
                foundationH[length-1] = "0"; //to indicate that last card has been replaced
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
        }

    }
    if(source == '1'){//foundation diamonds
        for(int i = 0; i < 13; i++){
            if(foundationD[i].size() != 3) {
                length++;//keep the number of cards in the foundation
            }
        }
        if(length == 0){
            output << "Invalid Move!" << endl << endl;
        }
        else{
            state = piles.moveCard(foundationD[length-1], destination);
            if(state == 1){
                foundationD[length-1] = "0"; //to indicate that last card has been replaced
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
        }

    }
    if(source == '2'){//foundation spades
        for(int i = 0; i < 13; i++){
            if(foundationS[i].size() != 3) {
                length++;//keep the number of cards in the foundation
            }
        }
        if(length == 0){
            output << "Invalid Move!" << endl << endl;
        }
        else{
            state = piles.moveCard(foundationS[length-1], destination);
            if(state == 1){
                foundationS[length-1] = "0"; //to indicate that last card has been replaced
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
        }
    }
    if(source == '3'){//foundation clubs
        for(int i = 0; i < 13; i++){
            if(foundationC[i].size() != 3) {
                length++;//keep the number of cards in the foundation
            }
        }
        if(length == 0){
            output << "Invalid Move!" << endl << endl;
        }
        else{
            state = piles.moveCard(foundationC[length-1], destination);
            if(state == 1){
                foundationC[length-1] = "0"; //to indicate that last card has been replaced
            }
            else{
                output << "Invalid Move!" << endl << endl;
            }
        }

    }
    return piles;
}


