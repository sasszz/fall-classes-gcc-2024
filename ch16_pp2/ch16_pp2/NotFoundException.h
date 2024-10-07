//
//  NotFoundException.h
//  ch16_pp2
//
//  Created by Lucie Chevreuil on 10/7/24.
//

#ifndef _TARGET_NOT_FOUND_EXCEPTION
#define _TARGET_NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>

class TargetNotFoundException : public std::runtime_error {
public:
    explicit TargetNotFoundException(const std::string& message = "")
        : std::runtime_error("Target not found: " + message) {
    } // end constructor
}; // end TargetNotFoundException

#endif // _TARGET_NOT_FOUND_EXCEPTION
