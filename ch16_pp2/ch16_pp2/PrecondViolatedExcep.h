//
//  PrecondViolatedExcep.h
//  ch16_pp2
//
//  Created by Lucie Chevreuil on 10/7/24.
//

/**
 * @file PrecondViolatedExcep.h
 */
#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error {
public:
    PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep

#endif
