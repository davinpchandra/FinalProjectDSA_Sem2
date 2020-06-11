//
//  Header.h
//  FinalProjectDSA
//
//  Created by Davin Pratama Chandra on 04/06/20.
//  Copyright © 2020 Davin Pratama Chandra. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <unordered_map>
using namespace std;

struct Trie {
    bool isEndOfWord;
    unordered_map <char, Trie*> map;
    string meaning;
};

// Function to create a new Trie node
Trie* getNewTrieNode() {
    Trie* node = new Trie;
    node->isEndOfWord = false;
    return node;
}

// Function to insert a word and the meaning into the dictionary
void insert (Trie*& root, const string& str, const string& meaning) {
    if (root == NULL) {
        root = getNewTrieNode();
    }
    
    Trie* temp = root;
    for (int i = 0; i < str.length(); i++) {
        char x = str[i];
        
        // if there is no existing path, make a new node
        if (temp->map.find(x) == temp->map.end()) {
            temp->map[x] = getNewTrieNode();
        }
        
        temp = temp->map[x];
    }
    
    // Set the boolean to true and enter the meaning
    temp->isEndOfWord = true;
    temp->meaning = meaning;
}

// Function to search a word in the dictionary and return the meaning
string getMeaning(Trie* root, const string& word) {
    if (root == NULL) {
        return "";
    }
    
    Trie* temp = root;
    
    // Search the word letter by letter
    for (int i = 0; i < word.length(); i++) {
        temp = temp->map[word[i]];
        if (temp == NULL) {
            return "";
        }
    }
    
    // If it reaches the end of the word, it returns the meaning
    if (temp->isEndOfWord) {
        return temp->meaning;
    }
    
    return "";
}


#endif /* Header_h */
