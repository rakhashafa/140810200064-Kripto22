/*
Nama Program : Program Shift Cipher
Nama         : Muhammad Ariiq Rakha Shafa
NPM          : 140810200064
Kelas        : A
Tanggal Buat : 20 September 2022
*/

#include <iostream>

namespace ShiftCipher
{
    int ascii_lower = 97;
    int ascii_upper = 65;

    std::string encryption(std::string text, int key)
    {
        std::string result = "";
        for (char ch : text)
        {
            if ((ch - ascii_lower) >= 0 && (ch - ascii_lower) <= 25)
            {
                ch = (((ch - ascii_lower) + key) % 26) + ascii_lower;
            }
            else if ((ch - ascii_upper) >= 0 && (ch - ascii_upper) <= 25)
            {
                ch = (((ch - ascii_upper) + key) % 26) + ascii_upper;
            }
            result.push_back(ch);
        }
        return result;
    }

    std::string decryption(std::string text, int key)
    {
        std::string result = "";
        for (char ch : text)
        {
            if ((ch - ascii_lower) >= 0 && (ch - ascii_lower) <= 25)
            {
                ch -= (ascii_lower + key);
                ch = (ch < 0 ? ch + 26 : ch);
                ch = (ch % 26) + ascii_lower;
            }
            else if ((ch - ascii_upper) >= 0 && (ch - ascii_upper) <= 25)
            {
                ch -= (ascii_upper + key);
                ch = (ch < 0 ? ch + 26 : ch);
                ch = (ch % 26) + ascii_upper;
            }
            result.push_back(ch);
        }
        return result;
    }
}

int main(int argc, char const *argv[])
{
    std::string plainTeks = "";
    std::string cipherText = "";
    std::string decryptedText = "";
    int key;
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "----------------------------Shift Cipher-----------------------------\n";
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "Insert Plain Text : ";
    std::getline(std::cin, plainTeks);
    std::cout << "Insert Key : ";
    std::cin >> key;
    std::cout << "\nProses Enkripsi\n";
    cipherText = ShiftCipher::encryption(plainTeks, key);
    std::cout << "Cipher Text : " << cipherText;
    std::cout << "\n\nProses Dekripsi\n";
    decryptedText = ShiftCipher::decryption(cipherText, key);
    std::cout << "Decrypted Text : " << decryptedText;
}