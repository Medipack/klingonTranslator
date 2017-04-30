/* 
 * File: Word.h
 * 
 * Class description:   Contains both the English and Klingon
 *						word for something
 * 
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on July 13, 2016
 */
#pragma once

#include <string>
#include <cstddef> 

using namespace std;

class Word
{
private:
	string engWord; //English word
	string klingon; //Klingon word
public:

	// Default constuctor
	// Description: Creates a blank Word
	// Postcondition: engWord and klingon are both set to null
	Word();

	// Parameterized constructors
	// Description: Creates a word with only an English meaning
	// Postcondition: engWord is set as the parameter, klingon is set
	//			      to <notfound>
	Word(string theWord);

	// Description: Creates a word with both meanings
	// Postcondition: both engWord and klingon are set as the 
	//				  appropriate values
	Word(string theWord, string klingTrans);

	//Getters
	// Description: Returns the English word
	string getEnglish() const;

	// Description: Returns the Klingon word
	string getKlingon() const;
};
