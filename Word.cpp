/* 
 * File: Word.cpp
 * 
 * Class description:   Contains both the English and Klingon
 *						word for something
 * 
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on July 13, 2016
 */

#include <string>
#include "Word.h"

using namespace std;

// Default constuctor
// Description: Creates a blank Word
// Postcondition: engWord and klingon are both set to 
Word::Word(){
	engWord = "<not found>";
	klingon = "<not found>";
}

// Parameterized constructors
// Description: Creates a word with only an English meaning
// Postcondition: engWord is set as the parameter, klingon is set
//			      to <notfound>
Word::Word(string theWord){
	engWord = theWord;
	klingon = "<not found>";
}

// Description: Creates a word with both meanings
// Postcondition: both engWord and klingon are set as the 
//				  appropriate values
Word::Word(string theWord, string klingTrans){
	engWord = theWord;
	klingon = klingTrans;
}

//Getters
// Description: Returns the English word
string Word::getEnglish() const{
	return engWord;
}

// Description: Returns the Klingon word
string Word::getKlingon() const{
	return klingon;
}
