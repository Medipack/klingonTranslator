/* 
 * File: wordNode.h
 * 
 * Class description:   Contains a Word and two addressed to more nodes
 * 
 * Authors: Amritpaul Gill, Calvin Chou
 *
 * Created on July 13, 2016
 */
#pragma once

#include <string>
#include <cstddef> 
#include "Word.h"

template <class Type>
class wordNode
{
private:
    Type* data; //Dictionary entry
    wordNode<Type>* left; //Left link
    wordNode<Type>* right; //Right link
public:
    // Default constuctor
    // Description: Creates a blank wordNode
    // Postcondition: data, left, and right are all null
    wordNode();

    // Paramaterized constuctor
    // Description: Creates a blank wordNode
    // Postcondition: the parameter is set as the data
    wordNode(Type* theData);
    
    //Getters
    // Description: returns the Word in this node
    Type getWord();

    // Description: returns the address of the node on the right
    wordNode<Type>* getRightChild();

    // Description: returns the address of the node on the left
    wordNode<Type>* getLeftChild();

    //Setters
    // Description: Sets a new word as the data
    // Postcondition: newWord is set as data
    void setWord(Type* newWord);
    
    // Description: Sets a new node on the left address
    // Postcondition: left is set as leftChild
    void setLeft(wordNode<Type>* leftChild);

    // Description: Sets a new node on the right address
    // Postcondition: right is set as rightChild
    void setRight(wordNode<Type>* rightChild);
};

// Default constructor
// Description: Creates a blank wordNode
// Postcondition: data, left, and right are all null
template <class Type>
wordNode<Type>::wordNode(){
    data = NULL;
    right = NULL;
    left = NULL;
}

// Paramaterized constuctor
// Description: Creates a blank wordNode
// Postcondition: the parameter is set as the data
template <class Type>
wordNode<Type>::wordNode(Type* theData){
    data = theData;
    right = NULL;
    left = NULL;
}

// Getters
// Description: returns the Word in this node
template <class Type>
Type wordNode<Type>::getWord(){
    Type temp = *data;
    return temp;
}

// Description: returns the address of the node on the right
template <class Type>
wordNode<Type>* wordNode<Type>::getRightChild(){
    return right;
}

// Description: returns the address of the node on the left
template <class Type>
wordNode<Type>* wordNode<Type>::getLeftChild(){
    return left;
}
//Setters
// Description: Sets a new word as the data
// Postcondition: newWord is set as data
template <class Type>
void wordNode<Type>::setWord(Type* newWord){
    data = newWord;
    }

// Description: Sets a new node on the left address
// Postcondition: left is set as leftChild
template <class Type>
void wordNode<Type>::setLeft(wordNode<Type>* leftChild){
    left = leftChild;
}

// Description: Sets a new node on the right address
// Postcondition: right is set as rightChild
template <class Type>
void wordNode<Type>::setRight(wordNode<Type>* rightChild){
    right = rightChild;
}
