/* 
 * File: hashTable.h
 * 
 * Class description: A two dimensional array holding hashedEntry objects.
					  The first dimension is for each letter, the second is	
					  for hash values which are determined by the letters of the word
					   
 * 
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on August 1, 2016
 */
#pragma once

#include "Word.h"
#include "hashedEntry.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

template <class Type>
class hashTable
{
private:
	static const int LETTERS = 26; //size of first dimension
    static const int HASH_CAPACITY = 31; //size of second dimension
    hashedEntry<Type>** table[HASH_CAPACITY]; //Dictionary entry
    int letterRecord[LETTERS]; //master list of elements in each category
public:
    // Default constructor
    // Description: Creates a blank hashTable
    // Postcondition: data, left, and right are all null
    hashTable();
    // Destructor
    // Description: Deletes the hashTable
    ~hashTable();
    // Description: Takes the first letter of the word and find it's position
    friend int getLetterCode(string word);
    bool hashEmpty(hashedEntry<Type>* wordPtr);
    bool hashInsert(Type* word);
    string search(string wordToFind);
    hashedEntry<Type>* hashRetrieve(string wordToFind, int hashIndex);
    // Description : Create the hash index for the array out of the search key;
    int hash(int searchKey);

};

// Default constructor
// Description: Creates a blank hashTable
// Postcondition: data, left, and right are all null
template <class Type>
hashTable<Type>::hashTable(){
    for (int i = 0; i < LETTERS; i++){
        table[i] = new hashedEntry<Type>*[HASH_CAPACITY];
    }
}

// Default constructor
// Description: Deallocates data for deletion
template <class Type>
hashTable<Type>::~hashTable(){
    for (int i = 0; i < LETTERS; i++){
        delete[] table[i];
    }
}

// Description: Returns letter position for pointer array
int getLetterCode(string word){
    const int ASCII = 65; //ASCII constant
    int letterCode = 0;
    //find the ASCII code of the first letter (capitalized)
    //subtract ASCII constant to figure out array position
    letterCode = toupper(word[0]) - ASCII;
    //return the array position
    return letterCode;
}

//  Description: checks if empty, returns true if it is and faqlse if it is not
template<class Type>
bool hashTable<Type>::hashEmpty(hashedEntry<Type>* wordPtr){
    return(wordPtr==NULL);
}

// Getters
// Description: returns the Word in this node
template <class Type>
bool hashTable<Type>::hashInsert(Type* word){
    bool inserted = false;
    string engWord = word->getEnglish(); //get the English word
    //establish which part of the array it should be
    int letterCode = getLetterCode(engWord); 
    //create new hashedEntry
    hashedEntry<Type>* newWord = new hashedEntry<Type>(word);
    //get the searchKey
    int searchKey = newWord->getKey();
    //generate the hasIndex
    int hashIndex = hash(searchKey);
    
    //Resolve collisions
    //check if location is empty
    // (if not, then increment hashIndex until it is empty)
    while(!hashEmpty(table[letterCode][hashIndex])){
        hashIndex++;
    }
    //set the entry into the array
    table[letterCode][hashIndex] = newWord;
    inserted = true;
    return inserted;
}

//  Description: Searches for the given word by using its hash key to
//			     look in the appropriate spot in the table
template <class Type>
string hashTable<Type>::search(string wordToFind){
    //generate the search key for the word
    int searchKey = searchKeyGen(wordToFind);
    // create the hash index
    int hashIndex = hash(searchKey);
    hashedEntry<Type>* temp = hashRetrieve(wordToFind,hashIndex);
    //check if the hashIndex can be found
    if (hashEmpty(temp)){
        return "NOT FOUND IN DICTIONARY";
        //check if word is correct;
        }else{
            return temp->getWord().getKlingon();
    }
}

// Description: Returns the word at a hash value
template <class Type>
hashedEntry<Type>* hashTable<Type>::hashRetrieve(string wordToFind, int hashIndex){
    hashedEntry<Type>* temp = NULL;
    //find which letter category the word would be
    int letterCode = getLetterCode(wordToFind);
    //make a surface copy of the entry at that location
    hashedEntry<Type>* targetWord = table[letterCode][hashIndex];
    //check if the word can be found at that hashIndex
    if (hashEmpty(targetWord)){
        //if we can't find the word
        //create a new word object with the unfound word
        Type* untranslatedWord = new Type(wordToFind);
        //create a new hashedEntry with the new word attached
        temp = new hashedEntry<Type>(untranslatedWord);
        return temp;
        //check if word is correct;
        }else if(targetWord->getWord().getEnglish() == wordToFind){
            temp = targetWord;
        }else{
            temp = hashRetrieve(wordToFind,hashIndex+1);
        }
    return temp;
}

// Description: Returns the hash index given a search key
template <class Type>
int hashTable<Type>::hash(int searchKey){
    int hashIndex = 0;
    hashIndex = searchKey % HASH_CAPACITY;
    return hashIndex;
}
