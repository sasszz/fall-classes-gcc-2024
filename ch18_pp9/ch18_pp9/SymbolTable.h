//
//  SymbolTable.h
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//

/**
 * Symbol Table implementation using TreeDictionary.
 * @file SymbolTable.h
 */

#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE

#include "TreeDictionary.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector> // For looping over a collection of identifiers

class SymbolTable {
private:
    TreeDictionary<std::string, int> table;

public:
    SymbolTable() : table() {}

    void insert(const std::string& identifier, int info) {
        if (!table.contains(identifier)) {
            table.add(identifier, info);
        } else {
            std::cerr << "Identifier already exists: " << identifier << std::endl;
        }
    }

    int retrieve(const std::string& identifier) const {
        return table.getItem(identifier); // Throws if not found
    }

    bool contains(const std::string& identifier) const {
        return table.contains(identifier);
    }

    void clear() {
        table.clear();
    }

    void printIdentifiers(const std::vector<std::string>& identifiers) const {
        std::cout << std::left << std::setw(15) << "Identifier" << std::setw(10) << "Value" << std::endl;
        std::cout << std::string(25, '-') << std::endl;

        for (const auto& identifier : identifiers) {
            try {
                int value = retrieve(identifier);
                std::cout << std::left << std::setw(15) << identifier << std::setw(10) << value << std::endl;
            } catch (const NotFoundException& e) {
                std::cout << std::left << std::setw(15) << identifier << std::setw(10) << "Not Found" << std::endl;
            }
        }
    }
};

#endif // _SYMBOL_TABLE
