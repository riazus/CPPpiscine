#include <string>
#include <fstream>

class Algoritm
{
    public :
        Algoritm(std::string filename, std::string s1, std::string s2);
        ~Algoritm();
        void WriteToNewFile(void);
    
    private :
        static std::string MyReplace(std::string line, int start, int len, std::string dest);
        std::string ReadFilePath;
        std::string s1;
        std::string s2; 
    
};