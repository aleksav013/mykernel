#include<source/keymap.h>

void us_en(char keymap[])
{
    keymap[0x01]=' ';        //escape pressed
    keymap[0x02]='1';        //1 pressed
    keymap[0x03]='2';        //2 pressed
    keymap[0x04]='3';        //3 pressed
    keymap[0x05]='4';        //4 pressed
    keymap[0x06]='5';        //5 pressed
    keymap[0x07]='6';        //6 pressed
    keymap[0x08]='7';        //7 pressed
    keymap[0x09]='8';        //8 pressed
    keymap[0x0A]='9';        //9 pressed
    keymap[0x0B]='0';        //0 (zero) pressed
    keymap[0x0C]='-';        //- pressed
    keymap[0x0D]='=';        //= pressed
    keymap[0x0E]=' ';        //backspace pressed
    keymap[0x0F]=' ';        //tab pressed
    keymap[0x10]='q';        //Q pressed
    keymap[0x11]='w';        //W pressed
    keymap[0x12]='e';        //E pressed
    keymap[0x13]='r';        //R pressed
    keymap[0x14]='t';        //T pressed
    keymap[0x15]='y';        //Y pressed
    keymap[0x16]='u';        //U pressed
    keymap[0x17]='i';        //I pressed
    keymap[0x18]='o';        //O pressed
    keymap[0x19]='p';        //P pressed
    keymap[0x1A]='[';        //[ pressed
    keymap[0x1B]=']';        //] pressed
    keymap[0x1C]='\n';        //enter pressed
    keymap[0x1D]=' ';        //left control pressed
    keymap[0x1E]='a';        //A pressed
    keymap[0x1F]='s';        //S pressed
    keymap[0x20]='d';        //D pressed
    keymap[0x21]='f';        //F pressed
    keymap[0x22]='g';        //G pressed
    keymap[0x23]='h';        //H pressed
    keymap[0x24]='j';        //J pressed
    keymap[0x25]='k';        //K pressed
    keymap[0x26]='l';        //L pressed
    keymap[0x27]=';';        //; pressed
    keymap[0x28]='\'';        //' (single quote) pressed
    keymap[0x29]='`';        //` (back tick) pressed
    keymap[0x2A]=' ';        //left shift pressed
    keymap[0x2B]='\\';        //\ pressed
    keymap[0x2C]='z';        //Z pressed
    keymap[0x2D]='x';        //X pressed
    keymap[0x2E]='c';        //C pressed
    keymap[0x2F]='v';        //V pressed
    keymap[0x30]='b';        //B pressed
    keymap[0x31]='n';        //N pressed
    keymap[0x32]='m';        //M pressed
    keymap[0x33]=',';        //, pressed
    keymap[0x34]='.';        //. pressed
    keymap[0x35]='/';        /// pressed
    keymap[0x36]=' ';        //right shift pressed
    keymap[0x37]='*';        //(keypad) * pressed
    keymap[0x38]=' ';        //left alt pressed
    keymap[0x39]=' ';        //space pressed
    keymap[0x3A]=' ';        //CapsLock pressed
    keymap[0x3B]=' ';        //F1 pressed
    keymap[0x3C]=' ';        //F2 pressed
    keymap[0x3D]=' ';        //F3 pressed
    keymap[0x3E]=' ';        //F4 pressed
    keymap[0x3F]=' ';        //F5 pressed
    keymap[0x40]=' ';        //F6 pressed
    keymap[0x41]=' ';        //F7 pressed
    keymap[0x42]=' ';        //F8 pressed
    keymap[0x43]=' ';        //F9 pressed
    keymap[0x44]=' ';        //F10 pressed
    keymap[0x45]=' ';        //NumberLock pressed
    keymap[0x46]=' ';        //ScrollLock pressed
    keymap[0x47]='7';        //(keypad) 7 pressed
    keymap[0x48]='8';        //(keypad) 8 pressed
    keymap[0x49]='9';        //(keypad) 9 pressed
    keymap[0x4A]='-';        //(keypad) - pressed
    keymap[0x4B]='4';        //(keypad) 4 pressed
    keymap[0x4C]='5';        //(keypad) 5 pressed
    keymap[0x4D]='6';        //(keypad) 6 pressed
    keymap[0x4E]='+';        //(keypad) + pressed
    keymap[0x4F]='1';        //(keypad) 1 pressed
    keymap[0x50]='2';        //(keypad) 2 pressed
    keymap[0x51]='3';        //(keypad) 3 pressed
    keymap[0x52]='0';        //(keypad) 0 pressed
    keymap[0x53]='.';        //(keypad) . pressed
    keymap[0x57]=' ';        //F11 pressed
    keymap[0x58]=' ';        //F12 pressed
    keymap[0x81]=' ';        //escape released
    keymap[0x82]=' ';        //1 released
    keymap[0x83]=' ';        //2 released
    keymap[0x84]=' ';        //3 released
    keymap[0x85]=' ';        //4 released
    keymap[0x86]=' ';        //5 released
    keymap[0x87]=' ';        //6 released
    keymap[0x88]=' ';        //7 released
    keymap[0x89]=' ';        //8 released
    keymap[0x8A]=' ';        //9 released
    keymap[0x8B]=' ';        //0 (zero) released
    keymap[0x8C]=' ';        //- released
    keymap[0x8D]=' ';        //= released
    keymap[0x8E]=' ';        //backspace released
    keymap[0x8F]=' ';        //tab released
    keymap[0x90]=' ';        //Q released
    keymap[0x91]=' ';        //W released
    keymap[0x92]=' ';        //E released
    keymap[0x93]=' ';        //R released
    keymap[0x94]=' ';        //T released
    keymap[0x95]=' ';        //Y released
    keymap[0x96]=' ';        //U released
    keymap[0x97]=' ';        //I released
    keymap[0x98]=' ';        //O released
    keymap[0x99]=' ';        //P released
    keymap[0x9A]=' ';        //[ released
    keymap[0x9B]=' ';        //] released
    keymap[0x9C]=' ';        //enter released
    keymap[0x9D]=' ';        //left control released
    keymap[0x9E]=' ';        //A released
    keymap[0x9F]=' ';        //S released
    keymap[0xA0]=' ';        //D released
    keymap[0xA1]=' ';        //F released
    keymap[0xA2]=' ';        //G released
    keymap[0xA3]=' ';        //H released
    keymap[0xA4]=' ';        //J released
    keymap[0xA5]=' ';        //K released
    keymap[0xA6]=' ';        //L released
    keymap[0xA7]=' ';        //; released
    keymap[0xA8]=' ';        //' (single quote) released
    keymap[0xA9]=' ';        //` (back tick) released
    keymap[0xAA]=' ';        //left shift released
    keymap[0xAB]=' ';        //\ released
    keymap[0xAC]=' ';        //Z released
    keymap[0xAD]=' ';        //X released
    keymap[0xAE]=' ';        //C released
    keymap[0xAF]=' ';        //V released
    keymap[0xB0]=' ';        //B released
    keymap[0xB1]=' ';        //N released
    keymap[0xB2]=' ';        //M released
    keymap[0xB3]=' ';        //, released
    keymap[0xB4]=' ';        //. released
    keymap[0xB5]=' ';        /// released
    keymap[0xB6]=' ';        //right shift released
    keymap[0xB7]='*';        //(keypad) * released
    keymap[0xB8]=' ';        //left alt released
    keymap[0xB9]=' ';        //space released
    keymap[0xBA]=' ';        //CapsLock released
    keymap[0xBB]=' ';        //F1 released
    keymap[0xBC]=' ';        //F2 released
    keymap[0xBD]=' ';        //F3 released
    keymap[0xBE]=' ';        //F4 released
    keymap[0xBF]=' ';        //F5 released
    keymap[0xC0]=' ';        //F6 released
    keymap[0xC1]=' ';        //F7 released
    keymap[0xC2]=' ';        //F8 released
    keymap[0xC3]=' ';        //F9 released
    keymap[0xC4]=' ';        //F10 released
    keymap[0xC5]=' ';        //NumberLock released
    keymap[0xC6]=' ';        //ScrollLock released
    keymap[0xC7]=' ';        //(keypad) 7 released
    keymap[0xC8]=' ';        //(keypad) 8 released
    keymap[0xC9]=' ';        //(keypad) 9 released
    keymap[0xCA]=' ';        //(keypad) - released
    keymap[0xCB]=' ';        //(keypad) 4 released
    keymap[0xCC]=' ';        //(keypad) 5 released
    keymap[0xCD]=' ';        //(keypad) 6 released
    keymap[0xCE]=' ';        //(keypad) + released
    keymap[0xCF]=' ';        //(keypad) 1 released
    keymap[0xD0]=' ';        //(keypad) 2 released
    keymap[0xD1]=' ';        //(keypad) 3 released
    keymap[0xD2]=' ';        //(keypad) 0 released
    keymap[0xD3]=' ';        //(keypad) . released
    keymap[0xD7]=' ';        //F11 released
    keymap[0xD8]=' ';        //F12 released
}

void us_en_shift(char keymap[])
{
    keymap[0x01]=' ';        //escape pressed
    keymap[0x02]='!';        //1 pressed
    keymap[0x03]='@';        //2 pressed
    keymap[0x04]='#';        //3 pressed
    keymap[0x05]='$';        //4 pressed
    keymap[0x06]='%';        //5 pressed
    keymap[0x07]='^';        //6 pressed
    keymap[0x08]='&';        //7 pressed
    keymap[0x09]='*';        //8 pressed
    keymap[0x0A]='(';        //9 pressed
    keymap[0x0B]=')';        //0 (zero) pressed
    keymap[0x0C]='_';        //- pressed
    keymap[0x0D]='+';        //= pressed
    keymap[0x0E]=' ';        //backspace pressed
    keymap[0x0F]=' ';        //tab pressed
    keymap[0x10]='Q';        //Q pressed
    keymap[0x11]='W';        //W pressed
    keymap[0x12]='E';        //E pressed
    keymap[0x13]='R';        //R pressed
    keymap[0x14]='T';        //T pressed
    keymap[0x15]='Y';        //Y pressed
    keymap[0x16]='U';        //U pressed
    keymap[0x17]='I';        //I pressed
    keymap[0x18]='O';        //O pressed
    keymap[0x19]='P';        //P pressed
    keymap[0x1A]='{';        //[ pressed
    keymap[0x1B]='}';        //] pressed
    keymap[0x1C]='\n';        //enter pressed
    keymap[0x1D]=' ';        //left control pressed
    keymap[0x1E]='A';        //A pressed
    keymap[0x1F]='S';        //S pressed
    keymap[0x20]='D';        //D pressed
    keymap[0x21]='F';        //F pressed
    keymap[0x22]='G';        //G pressed
    keymap[0x23]='H';        //H pressed
    keymap[0x24]='J';        //J pressed
    keymap[0x25]='K';        //K pressed
    keymap[0x26]='L';        //L pressed
    keymap[0x27]=':';        //; pressed
    keymap[0x28]='\"';        //' (single quote) pressed
    keymap[0x29]='~';        //` (back tick) pressed
    keymap[0x2A]=' ';        //left shift pressed
    keymap[0x2B]='|';        //\ pressed
    keymap[0x2C]='Z';        //Z pressed
    keymap[0x2D]='X';        //X pressed
    keymap[0x2E]='C';        //C pressed
    keymap[0x2F]='V';        //V pressed
    keymap[0x30]='B';        //B pressed
    keymap[0x31]='N';        //N pressed
    keymap[0x32]='M';        //M pressed
    keymap[0x33]='<';        //, pressed
    keymap[0x34]='>';        //. pressed
    keymap[0x35]='?';        /// pressed
    keymap[0x36]=' ';        //right shift pressed
    keymap[0x37]='*';        //(keypad) * pressed
    keymap[0x38]=' ';        //left alt pressed
    keymap[0x39]=' ';        //space pressed
    keymap[0x3A]=' ';        //CapsLock pressed
    keymap[0x3B]=' ';        //F1 pressed
    keymap[0x3C]=' ';        //F2 pressed
    keymap[0x3D]=' ';        //F3 pressed
    keymap[0x3E]=' ';        //F4 pressed
    keymap[0x3F]=' ';        //F5 pressed
    keymap[0x40]=' ';        //F6 pressed
    keymap[0x41]=' ';        //F7 pressed
    keymap[0x42]=' ';        //F8 pressed
    keymap[0x43]=' ';        //F9 pressed
    keymap[0x44]=' ';        //F10 pressed
    keymap[0x45]=' ';        //NumberLock pressed
    keymap[0x46]=' ';        //ScrollLock pressed
    keymap[0x47]='7';        //(keypad) 7 pressed
    keymap[0x48]='8';        //(keypad) 8 pressed
    keymap[0x49]='9';        //(keypad) 9 pressed
    keymap[0x4A]='-';        //(keypad) - pressed
    keymap[0x4B]='4';        //(keypad) 4 pressed
    keymap[0x4C]='5';        //(keypad) 5 pressed
    keymap[0x4D]='6';        //(keypad) 6 pressed
    keymap[0x4E]='+';        //(keypad) + pressed
    keymap[0x4F]='1';        //(keypad) 1 pressed
    keymap[0x50]='2';        //(keypad) 2 pressed
    keymap[0x51]='3';        //(keypad) 3 pressed
    keymap[0x52]='0';        //(keypad) 0 pressed
    keymap[0x53]='.';        //(keypad) . pressed
    keymap[0x57]=' ';        //F11 pressed
    keymap[0x58]=' ';        //F12 pressed
    keymap[0x81]=' ';        //escape released
    keymap[0x82]=' ';        //1 released
    keymap[0x83]=' ';        //2 released
    keymap[0x84]=' ';        //3 released
    keymap[0x85]=' ';        //4 released
    keymap[0x86]=' ';        //5 released
    keymap[0x87]=' ';        //6 released
    keymap[0x88]=' ';        //7 released
    keymap[0x89]=' ';        //8 released
    keymap[0x8A]=' ';        //9 released
    keymap[0x8B]=' ';        //0 (zero) released
    keymap[0x8C]=' ';        //- released
    keymap[0x8D]=' ';        //= released
    keymap[0x8E]=' ';        //backspace released
    keymap[0x8F]=' ';        //tab released
    keymap[0x90]=' ';        //Q released
    keymap[0x91]=' ';        //W released
    keymap[0x92]=' ';        //E released
    keymap[0x93]=' ';        //R released
    keymap[0x94]=' ';        //T released
    keymap[0x95]=' ';        //Y released
    keymap[0x96]=' ';        //U released
    keymap[0x97]=' ';        //I released
    keymap[0x98]=' ';        //O released
    keymap[0x99]=' ';        //P released
    keymap[0x9A]=' ';        //[ released
    keymap[0x9B]=' ';        //] released
    keymap[0x9C]=' ';        //enter released
    keymap[0x9D]=' ';        //left control released
    keymap[0x9E]=' ';        //A released
    keymap[0x9F]=' ';        //S released
    keymap[0xA0]=' ';        //D released
    keymap[0xA1]=' ';        //F released
    keymap[0xA2]=' ';        //G released
    keymap[0xA3]=' ';        //H released
    keymap[0xA4]=' ';        //J released
    keymap[0xA5]=' ';        //K released
    keymap[0xA6]=' ';        //L released
    keymap[0xA7]=' ';        //; released
    keymap[0xA8]=' ';        //' (single quote) released
    keymap[0xA9]=' ';        //` (back tick) released
    keymap[0xAA]=' ';        //left shift released
    keymap[0xAB]=' ';        //\ released
    keymap[0xAC]=' ';        //Z released
    keymap[0xAD]=' ';        //X released
    keymap[0xAE]=' ';        //C released
    keymap[0xAF]=' ';        //V released
    keymap[0xB0]=' ';        //B released
    keymap[0xB1]=' ';        //N released
    keymap[0xB2]=' ';        //M released
    keymap[0xB3]=' ';        //, released
    keymap[0xB4]=' ';        //. released
    keymap[0xB5]=' ';        /// released
    keymap[0xB6]=' ';        //right shift released
    keymap[0xB7]='*';        //(keypad) * released
    keymap[0xB8]=' ';        //left alt released
    keymap[0xB9]=' ';        //space released
    keymap[0xBA]=' ';        //CapsLock released
    keymap[0xBB]=' ';        //F1 released
    keymap[0xBC]=' ';        //F2 released
    keymap[0xBD]=' ';        //F3 released
    keymap[0xBE]=' ';        //F4 released
    keymap[0xBF]=' ';        //F5 released
    keymap[0xC0]=' ';        //F6 released
    keymap[0xC1]=' ';        //F7 released
    keymap[0xC2]=' ';        //F8 released
    keymap[0xC3]=' ';        //F9 released
    keymap[0xC4]=' ';        //F10 released
    keymap[0xC5]=' ';        //NumberLock released
    keymap[0xC6]=' ';        //ScrollLock released
    keymap[0xC7]=' ';        //(keypad) 7 released
    keymap[0xC8]=' ';        //(keypad) 8 released
    keymap[0xC9]=' ';        //(keypad) 9 released
    keymap[0xCA]=' ';        //(keypad) - released
    keymap[0xCB]=' ';        //(keypad) 4 released
    keymap[0xCC]=' ';        //(keypad) 5 released
    keymap[0xCD]=' ';        //(keypad) 6 released
    keymap[0xCE]=' ';        //(keypad) + released
    keymap[0xCF]=' ';        //(keypad) 1 released
    keymap[0xD0]=' ';        //(keypad) 2 released
    keymap[0xD1]=' ';        //(keypad) 3 released
    keymap[0xD2]=' ';        //(keypad) 0 released
    keymap[0xD3]=' ';        //(keypad) . released
    keymap[0xD7]=' ';        //F11 released
    keymap[0xD8]=' ';        //F12 released
}
