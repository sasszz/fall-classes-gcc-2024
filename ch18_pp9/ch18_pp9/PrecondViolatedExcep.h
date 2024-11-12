//
//  PrecondViolatedExcep.h
//  ch18_pp9
//
//  Created by Lucie Chevreuil on 11/11/24.
//

/**
 * Exception class for precondition violations.
 * @file PrecondViolatedExcep.h
 */

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error {
public:
    explicit PrecondViolatedExcep(const std::string& message = "")
        : std::logic_error("Precondition Violated Exception: " + message) {}
}; // end PrecondViolatedExcep

#endif // _PRECOND_VIOLATED_EXCEP
