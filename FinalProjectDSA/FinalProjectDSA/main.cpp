//
//  main.cpp
//  FinalProjectDSA
//
//  Created by Davin Pratama Chandra on 04/06/20.
//  Copyright © 2020 Davin Pratama Chandra. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

void menu(Trie* root) {
    string str;
    string yesOrNo;
    cout << "Enter word in lowercase: ";
    cin >> str;
    cout << getMeaning(root, str) << endl;
    cout << "Repeat ? (y/n) ";
    cin >> yesOrNo;
    if (yesOrNo == "y") {
        menu(root);
    }
    else {
        cout << "End" << endl;
    }
}

int main() {
    
    Trie* root = NULL;
    
    insert(root, "computer", "an electronic device for storing and processing data, typically in binary form, according to instructions given to it in a variable program.");
    insert(root, "science", "the intellectual and practical activity encompassing the systematic study of the structure and behaviour of the physical and natural world through observation and experiment.");
    insert(root, "data", "facts and statistics collected together for reference or analysis.");
    
    menu(root);
    
    return 0;
}
