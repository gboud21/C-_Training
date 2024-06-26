#ifndef RANSOMNOTE_H
#define RANSOMNOTE_H
///////////////////////////////////////////////////////////////////////////////
/* Problem: Ransom Note
Given two strings ransomNote and magazine, return true if ransomNote can be
constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input:  ransomNote = This is a Ransom
        magazine = This is spelling mosnar backwards
Output: TRUE

Constrabools:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

/* Scratch Pad:
Analysis:

Questions:
Q: Assuming a letter from the magazine can only be used once?
A: Yes
*/

#include <iostream>
#include <vector>

#include "AlgorithmTypes.h"

///////////////////////////////////////////////////////////////////////////
// \details The algorithms namespace
///////////////////////////////////////////////////////////////////////////
namespace alg
{

class RansomNote
{
public:
    ///////////////////////////////////////////////////////////////////////////
    // \details Default Constructor
    ///////////////////////////////////////////////////////////////////////////
    RansomNote(FunctionVersion version);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function calls one of the private implementations of the
    // algorithm based upon the value of m_functionVersion.
    // \param [in] ransomNote - The characters from the ransom note
    // \param [in] magazine - The characters that can be used from the magzine
    // \return bool - TRUE if ransomeNote is a subset of the characters in
    // magazine, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool ransomNote(std::string ransomNote, std::string magazine);

private:
    ///////////////////////////////////////////////////////////////////////////
    // \details This function will iterate through both the ransome note and the
    // magazine trying to determine if the number of each character within
    // the ransomNote can be found within the magazine
    // \param [in] ransomNote - The characters from the ransom note
    // \param [in] magazine - The characters that can be used from the magzine
    // \return bool - TRUE if ransomeNote is a subset of the characters in
    // magazine, FALSE otherwise
    ///////////////////////////////////////////////////////////////////////////
    bool bruteForce(std::string ransomNote, std::string magazine);

    ///////////////////////////////////////////////////////////////////////////
    // \details This function
    // \param [in] n - The number of stairs
    // \return bool - the number of ways that the stairs can be climbed
    ///////////////////////////////////////////////////////////////////////////
    // bool optimizedOne(std::string ransomnote, std::string magazine);

    // Determines which private implementation of the RansomNote
    // algorithm is called when the public function is called
    const FunctionVersion m_functionVersion;
};
} // namespace alg
#endif