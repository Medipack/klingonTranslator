/* 
 * File: klingonTrans.h
 * 
 * Class description:   Holds the English/Klingon words in a binary search tree
 *                      and performs the appropriate operations such as printing,
 *                      searching, storing, etc.
 * 
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on August 1, 2016
 */
#pragma once

#include "Word.h"
#include "wordNode.h"
#include "hashTable.h"
#include <cstdlib>

using namespace std;

template <class Type>
class klingonTrans
{
private:
    wordNode<Type>* root; //pointer to the root node of the tree
    hashedEntry<Type>* firstEngWord; //pointer to the first of the list of words
									 //to be translated
    hashTable<Type> dictionList; //The hashTable holding the words for fast searching
public:

    // Default Constructor
    // Description: Create an empty klingonTrans
    // Postcondition: root node is empty
    klingonTrans();

    //Destructor
    ~klingonTrans();
    
    //Description: adds the dictionary entry into the tree
    //Postcondition: the tree now has the dictionary entry
    bool add(Type* newWord);
    
    //Description: adds the input into the list of words to be translated
    //Postcondition: the list now has the input entry    
    bool addInput(string newInput);

    // Description: Inserts the new node in the correct position in the tree
    // Postcondition: The tree now contains the newNode in the correct position
    void insert(wordNode<Type>* newNode, wordNode<Type>* node);

    // Description: Returns true if there are no wordNodes, and false otherwise
    bool isEmpty();
    
    // Description: Returns the address of the root wordNode, and null if there
    //	            is none
    wordNode<Type>* getRoot();
    
    // Description: Prints all the inputted words and their Klingon translations
    //              in the format [english]:[klingon]
    void translateAll();
    
    // Description: Returns the Klingon translation of wordToFind
    string search(string wordToFind, wordNode<Type>* node);
    
    // Description: Recursive function that prints the whole dictionary in 
    //              alphabetical order by English word. This is the variant
    //              called by the client
    bool display();
    
    // Description: Recursive function that prints the whole dictionary in 
    //              alphabetical order by English word.
    bool display(wordNode<Type>* rootNode);
};


// Default Constructor
// Description: Create an empty klingonTrans
// Postcondition: root node is empty
template <class Type>
klingonTrans<Type>::klingonTrans(){
    root = NULL;  
    firstEngWord = NULL;
}

//Destructor
template <class Type>
klingonTrans<Type>::~klingonTrans(){}

//Description: adds the input into the list of words to be translated
//Postcondition: the list now has the input entry   
template <class Type>
bool klingonTrans<Type>::addInput(string newInput){
    
    //copy string
    string inputTemp = newInput;
    //adjust first character
    inputTemp[0] = tolower(inputTemp[0]);
    //generate the searchKey
    int searchKey = searchKeyGen(inputTemp);
    //find the hashIndex
    int hashIndex = dictionList.hash(searchKey);
    //retrieve the pointer to the word we're looking for
    hashedEntry<Type>* input = dictionList.hashRetrieve(inputTemp, hashIndex);
    //check if the word exists in our dictionary
    if (firstEngWord == NULL){
        firstEngWord = input;
        return true;
    }
    
    hashedEntry<Type>* current = firstEngWord;
    while (current->getNext() != NULL){
            current = current->getNext();
    }
    current->setNext(input);
    return true;
    
}

//Description: adds the dictionary entry into the tree
//Postcondition: the tree now has the dictionary entry
template <class Type>
bool klingonTrans<Type>::add(Type* newWord){
    
    wordNode<Type> firstNode = wordNode<Type>(newWord);
    if (isEmpty()){
        root = new wordNode<Type>(firstNode);
    }else{
        insert(new wordNode<Type>(firstNode), root);
    }
    dictionList.hashInsert(newWord);
    return true;
}

// Description: Inserts a wordNode in the correct position in the tree
// Postcondition: The tree now contains the newNode in the correct position
template <class Type>
void klingonTrans<Type>::insert(wordNode<Type>* newNode, wordNode<Type>* node){
    string word = newNode->getWord().getEnglish();
    word[0] = tolower(word[0]);
    //Compare english words for node and newNode
    //if lower, then getLeftChild()
    if (word < node->getWord().getEnglish()){
        if (node->getLeftChild() == NULL){
            node->setLeft(newNode);
        }
        else{
            insert(newNode, node->getLeftChild());
        }
    }
    //if higher, then getRightChild()
    if (word > node->getWord().getEnglish()){
        if (node->getRightChild() == NULL){
            node->setRight(newNode);
        }
        else{
            insert(newNode, node->getRightChild());
        }
    }
}

// Description: Returns true if there are no wordNodes, and false otherwise
template <class Type>
bool klingonTrans<Type>::isEmpty(){
    return (root == NULL);
}

// Description: Returns the address of the root wordNode, and null if there
//              is none
template <class Type>
wordNode<Type>* klingonTrans<Type>::getRoot(){
    return root;
}

// Description: Recursive function that prints the whole dictionary in 
//              alphabetical order by English word. This is the variant
//              called by the client
template <class Type>
bool klingonTrans<Type>::display(){
    display(root);
    return true;
}

// Description: Recursive function that prints the whole dictionary in 
//              alphabetical order by English word.
template <class Type>
bool klingonTrans<Type>::display(wordNode<Type>* rootNode){ 
    if (rootNode->getLeftChild() != NULL){
        display(rootNode->getLeftChild());
    }
    cout << (rootNode->getWord().getEnglish());
    cout << ":";
    cout << (rootNode->getWord().getKlingon());
    cout << "\n";

    if (rootNode->getRightChild() != NULL){
        display(rootNode->getRightChild());
    }

    return true;
}

// Description: Prints all the inputted words and their Klingon translations
//              in the format [english]:[klingon]
template <class Type>
void klingonTrans<Type>::translateAll(){
    cout << "\nTRANSLATIONS\n";
    hashedEntry<Type>* currentInput = firstEngWord;
    while (currentInput != NULL){
        cout << (currentInput->getWord().getEnglish()) << ":";
        cout << (dictionList.search(currentInput->getWord().getEnglish())) << "\n";
        currentInput = currentInput->getNext();
    }
}
