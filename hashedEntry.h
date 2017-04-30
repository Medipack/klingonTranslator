/* 
 * File: HashedEntry.h
 * 
 * Class description:   Pointers to word objects that also generate a search key
						(based off of the first 2-3 characters after the first character) 
						which can then be used to create a hash index
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on August 1, 2016
 */
 
#pragma once

#include "Word.h"
#include "wordNode.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

template <class Type>
class hashedEntry
{
private:
    //Description:  Generates a search key based off of the second to fourth 
    //              characters in a string. If there is less than four characters, 
    //              then generate a key based off of the second third.
    //Precondition: string is more more than or equal to three characters long
    friend int searchKeyGen(string word);
	
    int searchKey; //the hash key
    Type* data; //The pointer to the WordNode in klingonTrans
    hashedEntry<Type>* next; //The next entry
public:
    // Default constuctor
    // Description: Creates a blank hash object
    // Postcondition: data, left, and right are all null
    hashedEntry();
    // Paramaterized constuctor
    // Description: Creates a blank wordNode
    // Postcondition: the parameter is set as the data
    hashedEntry(Type* theData);

    //Getters
    // Description: returns the Word object data in this entry
    Type getWord();
    // Description: returns the pointer to the data in this entry
    Type* getPtr();
    // Description: returns the point to the next entry
    hashedEntry<Type>* getNext();
    //Description: returns the generated search key for this entry
    int getKey();
    //Description: sets new data and generates a new searchKey
    void setWord(Type* theWord);
    // Description: sets the next node on the list
    void setNext(hashedEntry<Type>* nextEntry);
};

//Description:  Generates a search key based off of the second to fourth 
//              characters in a string. If there is less than four characters, 
//              then generate a key based off of the second third.
//Precondition: string is more more than or equal to three characters long
int searchKeyGen(string word){
    int key = 0;
    //Constant for ASCII code
    const int ASCII = 65;
    //check if string is less than or equal to 3
    if(word.length()< 4){
        //we ignore the first character in the string
        //find the number of the second letter
        int firstInt = toupper(word[1]) - ASCII +1;
        //find the number of the third letter
        int secInt = toupper(word[2]) - ASCII +1;
        //calculate the key
        key = (firstInt*5+secInt)*5;
    }else{
        //convert second character into integer
        int firstInt = toupper(word[1]) - ASCII +1;
        //convert third character into integer
        int secInt = toupper(word[2]) - ASCII +1;
        //convert the 4th 
        int thirInt = toupper(word[3]) - ASCII +1;
        //calculate the key
        key = ((firstInt*5+secInt)*5+thirInt)*5;
    }    
    return key;
}

// Default constructor
// Description: Creates a blank hashTable
// Postcondition: data, and next are all null
template <class Type>
hashedEntry<Type>::hashedEntry(){
    searchKey = 0;
    data = NULL;
    next = NULL;
}

// Parameterized constructor
// Description: Creates a hashTable containing data
// Postcondition: data, left, and right are all null
template <class Type>
hashedEntry<Type>::hashedEntry(Type* theData){
    searchKey = searchKeyGen(theData-> getEnglish());
    data = theData;
    next = NULL;
}

//Getters
// Description: returns the Word in this node
template <class Type>
Type hashedEntry<Type>::getWord(){
    Type temp = *data;
    return temp;
}

// Description: returns the data variable in this node
template <class Type>
Type* hashedEntry<Type>::getPtr(){
    return data;
}

// Description: returns the hashedEntry next of this one
template <class Type>
hashedEntry<Type>* hashedEntry<Type>::getNext(){
    return next;
}

// Description: returns the hash key
template <class Type>
int hashedEntry<Type>::getKey(){
    return searchKey;
}

//Setters
// Description: sets the data value for this node
// Postcondition: data is set to theWord
template <class Type>    
void hashedEntry<Type>::setWord(Type* theWord){
    searchKey = searchKeyGen(theWord->getEnglish());
    data = theWord;
}

// Description: sets the next entry of the linked list.
// Postcondition: next is set to nextEntry
template <class Type>
void hashedEntry<Type>::setNext(hashedEntry<Type>* nextEntry){
    next = nextEntry;
}