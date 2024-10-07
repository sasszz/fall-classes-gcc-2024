//
//  PrecondViolatedExcep.cpp
//  ch16_pp2
//
//  Created by Lucie Chevreuil on 10/7/24.
//

/**
 * @file PrecondViolatedExcep.cpp
 */
#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message)
    : logic_error("Precondition Violated Exception: " + message)
{
} // end constructor
