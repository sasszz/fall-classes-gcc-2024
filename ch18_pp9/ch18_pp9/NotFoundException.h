//
//  NotFoundException.h
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//

/**
 * Exception class for cases when an entry is not found.
 * @file NotFoundException.h
 */

#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error {
public:
    explicit NotFoundException(const std::string& message = "")
        : std::logic_error("Not Found Exception: " + message) {}
}; // end NotFoundException

#endif // _NOT_FOUND_EXCEPTION
