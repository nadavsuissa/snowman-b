#include <iostream>
#include <array>
#include <string>

using namespace std;
namespace bodycustomize
{
    const array<string, 4> hat = {
        "      \n _===_",
        "  ___ \n .....",
        "   _  \n  /_\\ ",
        "  ___ \n (_*_)",
    };
    const array<string, 4> nose = {
        ",",
        ".",
        "_",
        " ",
    };
    const array<string, 4> eye = {
        ".",
        "o",
        "O",
        "-",
    };
    const array<string, 4> larmUp = {
        // In order to fix problomatic situation
        " ",
        "\\",
        " ",
        " ",
    };
    const array<string, 4> larmDown = {
        "<",
        " ",
        "/",
        " ",
    };
    const array<string, 4> rarmUp = {
        // In order to fix problomatic situation
        " ",
        "/",
        " ",
        " ",
    };
    const array<string, 4> rarmDown = {
        ">",
        " ",
        "\\",
        " ",
    };
    const array<string, 4> torso = {
        "( : )",
        "(] [)",
        "(> <)",
        "(   )",
    };
    const array<string, 4> base = {
        " ( : ) ",
        " (\" \") ",
        " (___) ",
        " (   ) ",
    };
}

namespace ariel
{
    const int length = 8; // # Of Digits in a Valid Snowman input
    const int div = 10;   // Magic Number... hence Constant

    array<int, length> validateExtract(int num) // Extract Options From Input and Valitation ( 1-4 )
    {
        array<int, length> helpArr = {}; // Array to store every value from given number
        const int minOption = 1;         // Should be Constant...
        const int maxOption = 4;         // Should be Constant...
        int presentNum = 0;              // Shouldn't be Constant...They need to Change
        int helper = 0;                  // Shouldn't be Constant...They need to Change
        // Basic While to itterate over given value
        while (num > 0)
        {

            presentNum = num % div;
            // Check if Each digit is in the range
            if (presentNum < minOption || presentNum > maxOption)
            {
                throw std::out_of_range{"The Input For One of The Options Is Not Valid (Must Be Between 1-4)."};
            }
            num = num / div;
            presentNum--;
            helpArr.at(length - 1 - helper) = presentNum;
            helper++;
        }
        return helpArr;
    }
    string snowman(int num)
    {
        /* 
        https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman
        ----------------------------------------------------------------
        Should Be Built Like This:
        ----------------------------------------------------------------
          HHHHH
          HHHHH
         X(LNR)Y
         X(TTT)Y
          (BBB)
        ----------------------------------------------------------------
          Snowman Key Givven Below:
        */
        const int lowerBound = 11111111; // Limit for Lowest possible Input
        const int upperBound = 44444444; // Limit for Highest possible Input
        const int Hats = 0;              // H
        const int Nose_Mouth = 1;        // N
        const int Left_Eye = 2;          // L
        const int Right_Eye = 3;         // R
        const int Left_Arm = 4;          // X
        const int Right_Arm = 5;         // Y
        const int Torso = 6;             // T
        const int Base = 7;              // B
        // Simple Input Length Validation Check
        if (num < lowerBound || num > upperBound)
        {
            throw std::out_of_range{"Not a Valid Input - Length Wise"};
        }
        // Extracts and stores every option given to build
        array<int, length> optarray = validateExtract(num);

        string buildSnowman;
        // 3 Step Creation Proccess:
        // This will be simple with the help of append
        // Append - This function is used to extend the string by appending at the end of the current value.
        // Step by Step We Will Build his body like shown below.

        //First Stage - The Hat
        buildSnowman.append(bodycustomize::hat.at(optarray.at(Hats)));
        buildSnowman.append("\n");

        //Second Stage - Head + Torso
        buildSnowman.append(bodycustomize::larmUp.at(optarray.at(Left_Arm)));
        buildSnowman.append("(");
        buildSnowman.append(bodycustomize::eye.at(optarray.at(Left_Eye)));
        buildSnowman.append(bodycustomize::nose.at(optarray.at(Nose_Mouth)));
        buildSnowman.append(bodycustomize::eye.at(optarray.at(Right_Eye)));
        buildSnowman.append(")");
        buildSnowman.append(bodycustomize::rarmUp.at(optarray.at(Right_Arm)));
        buildSnowman.append("\n");
        buildSnowman.append(bodycustomize::larmDown.at(optarray.at(Left_Arm)));
        buildSnowman.append(bodycustomize::torso.at(optarray.at(Torso)));
        buildSnowman.append(bodycustomize::rarmDown.at(optarray.at(Right_Arm)));
        buildSnowman.append("\n");

        //Last Stage - Base
        buildSnowman.append(bodycustomize::base.at(optarray.at(Base)));

        // Send Back Built Snowman
        return buildSnowman;
    }
}