/* 
 * File: EKTApp.cpp
 * 
 * Class description:   Runs a program that reads words and their definitions
 *                      off of datafile.txt, and then either displays the 
 *                      entries in alphabetical order of the english word,
 *                      or takes English words from the keyboard and translates
 *                      them
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on August 1, 2016
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "Word.h"
#include "klingonTrans.h"



using namespace std;

int main(int argc, char** argv) {
    
    klingonTrans<Word> dictionary; //Holds data for translations
    
    ifstream dictionaryData; //Takes input from keyboard
    dictionaryData.open ("datafile.txt");
    string english; //Used to generate the inputted Engloish word
    string klingon; //Used to generate the imputted Klingon word
    char letter; //Letters read from input
    bool engMode = true; //Controls whether the translator is trying to read English
						 //or Klingon from the input
    Word* newWord; //Used to generate Word objects to be entered into the data structure
    
    while (true){
        dictionaryData.get(letter);
        //if we're done, get out
        if ((engMode) && (letter == '\n')) break;
        //go to Klingon mode at the colon
        else if (letter == ':') engMode = false;
        //change mode at the end of the line, and make a word
        else if (letter == '\n'){
            engMode = true;   
            newWord = new Word(english, klingon);
            dictionary.add(newWord);
            english = "";
            klingon = "";
        }
        else{
            if (engMode)english += letter;
            else klingon += letter;
        }
    }

	//Diplays all words in the dictionary in English and Klingon, if requested,
    if(argc ==2){
    	string display(argv[1]);
    		if (display == "display"){
    			dictionary.display();
    			}else{
    				cout << "Invalid command\n";
    			}
    }else{ //takes input and translates it when the user is done typing
        string input;
        while (cin>>input){
            dictionary.addInput(input);
        }
        if (cin.eof()){ //check for Ctrl+D
            dictionary.translateAll();
        }
    }
    return 0;
}
