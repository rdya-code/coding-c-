//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//using namespace std;
//class Token
//{
//protected:
//    static int totalTokens;
//public:
//    Token() { totalTokens++; }
//    virtual void count() {}
//    static int getTotalTokens() { return totalTokens; }
//};
//
//int Token::totalTokens = 0;
//
//class Word : public Token 
//{
//protected:
//    static int totalWords;
//public:
//    Word() { totalWords++; }
//    virtual bool isPreposition(const char* word) { return false; }
//    static int getTotalWords() { return totalWords; }
//};
//
//int Word::totalWords = 0;
//
//class Preposition : public Word
//{
//protected:
//    static int totalPrepositions;
//public:
//    Preposition() { totalPrepositions++; }
//    bool isPreposition(const char* word) override 
//    {
//        const char* prepositions[] = { "in", "on", "at", "by", "for", "with", "about", "against", "between", "into", "through", "during", "before", "after", "above", "below", "to", "from", "up", "down", "under", "over", "again", "further", "then", "once" };
//        for (const char* prep : prepositions) 
//        {
//            if (strcmp(word, prep) == 0) 
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//    static int getTotalPrepositions() { return totalPrepositions; }
//};
//
//int Preposition::totalPrepositions = 0;
//
//class Number : public Token {
//protected:
//    static int totalNumbers;
//public:
//    Number() { totalNumbers++; }
//    virtual bool isInteger(const char* str) { return false; }
//    virtual bool isFloat(const char* str) { return false; }
//    static int getTotalNumbers() { return totalNumbers; }
//};
//
//int Number::totalNumbers = 0;
//
//class Integer : public Number 
//{
//protected:
//    static int totalIntegers;
//public:
//    Integer() { totalIntegers++; }
//    bool isInteger(const char* str) override {
//        for (int i = 0; str[i] != '\0'; i++)
//        {
//            if (!isdigit(str[i])) return false;
//        }
//        return true;
//    }
//    static int getTotalIntegers()
//    { return totalIntegers; }
//};
//
//int Integer::totalIntegers = 0;
//
//class Float : public Number
//{
//protected:
//    static int totalFloats;
//public:
//    Float() { totalFloats++; }
//    bool isFloat(const char* str) override
//    {
//        bool dotSeen = false;
//        for (int i = 0; str[i] != '\0'; i++)
//        {
//            if (str[i] == '.') {
//                if (dotSeen) return false;
//                dotSeen = true;
//            }
//            else if (!isdigit(str[i])) return false;
//        }
//        return dotSeen;
//    }
//    static int getTotalFloats() 
//    { return totalFloats; }
//};
//
//int Float::totalFloats = 0;
//
//int main()
//{
//    const char* inputText = "The book is on the table. It costs 12 dollars and 3.5 cents. In total, there are 5 books, 2 of which are on sale.";
//    char word[100];
//
//    // Simulate reading words from the hardcoded inputText
//    const char* start = inputText;
//    const char* end = inputText;
//
//    while (*end) {
//        while (*end && !isspace(*end) && *end != '.' && *end != ',') 
//        {
//            end++;
//        }
//
//        // Create a copy of the current word
//        int length = end - start;
//        if (length > 0) {
//            strncpy(word, start, length);
//            word[length] = '\0'; // Null-terminate the string
//
//            bool counted = false;
//            if (Integer().isInteger(word)) 
//            {
//                Integer();
//                counted = true;
//            }
//            else if (Float().isFloat(word))
//            {
//                Float();
//                counted = true;
//            }
//            else {
//                Word();
//                if (Preposition().isPreposition(word))
//                {
//                    Preposition();
//                }
//            }
//        }
//
//        // Move to the next word
//        while (*end && (isspace(*end) || *end == '.' || *end == ','))
//        {
//            end++;
//        }
//        start = end;
//    }
//
//    cout << "Total Words: " << Word::getTotalWords() << endl;
//    cout << "Total Prepositions: " << Preposition::getTotalPrepositions() << endl;
//    cout << "Total Numbers: " << Number::getTotalNumbers() << endl;
//    cout << "Total Integers: " << Integer::getTotalIntegers() << endl;
//    cout << "Total Floats: " << Float::getTotalFloats() << endl;
//
//    return 0;
//}
