#include <iostream>
#include <string>

using namespace std;

// Функция шифрования строки с помощью шифра Цезаря с кодировкой cp1251
string encrypt(string message, int key)
{
    string result = "";

    for (int i = 0; i < message.length(); i++)
    {
        unsigned char c = message[i]; // Преобразовать символ в код cp1251
        int code = c;
        code = (code + key) % 256; // Применить формулу шифрования Caesar Cipher
        c = (unsigned char)code; // Конвертировать код обратно в его символьное представление
        result += c; // Добавить зашифрованный символ в результирующую строку
    }
    return result;
}

// Функция расшифровки строки, зашифрованной шифром Цезаря с кодировкой cp1251
string decrypt(string message, int key)
{
    string result = "";

    for (int i = 0; i < message.length(); i++)
    {
        unsigned char c = message[i]; // Преобразовать символ в код cp1251
        int code = c;
        code = (code - key + 256) % 256; // Применить формулу расшифровки шифра Цезаря        
        c = (unsigned char)code; // Конвертировать код обратно в его символьное представление        
        result += c; // Добавить расшифрованный символ в результирующую строку
    }
    return result;
}

int main()
{

    string massage;
    cout << "Input the text: ";
    getline(cin, massage);

    int key = 33;
    cout << "Input the number: ";
    cin >> key;

    // зашифровать сообщение
    cout << encrypt(massage, key) << '\n';

    // расшифровать сообщение
    cout << decrypt(encrypt(massage, key), key) << '\n';

    return 0;

}