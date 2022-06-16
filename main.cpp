#include <iostream>
#include <string.h>
#include <fstream>

void tokenize(std::string eqa, std::ofstream &writeFile)
{
    int countParen = 0; 
    std::string temp;
    for (int i = 0; i < eqa.length(); i++) 
    {
        if (eqa[i] == '=')
        {
            writeFile << eqa[i] << "  -> Assign_OP\n";
            printf("%c  -> Assign_OP\n",eqa[i]);
        } else if(eqa[i] == '+')
        {
            writeFile << eqa[i] << "  -> Add_OP\n";
            printf("%c  -> Add_OP\n",eqa[i]);
        } else if(eqa[i] == '-')
        {
            writeFile << eqa[i] << "  -> Sub_OP\n";
            printf("%c  -> Sub_OP\n",eqa[i]);
        } else if(eqa[i] == '/')
        {
            writeFile << eqa[i] << "  -> Div_OP\n";
            printf("%c  -> Div_OP\n",eqa[i]);
        } else if(eqa[i] == '*')
        {
            writeFile << eqa[i] << "  -> Mult_OP\n";
            printf("%c  -> Mult_OP\n",eqa[i]);
        } else if(eqa[i] == '(')
        {
            ++countParen;
            writeFile << eqa[i] << "  -> Open_Parenthesis\n";
            printf("%c  -> Open_Parenthesis\n",eqa[i]);
        } else if(eqa[i] == ')')
        {
            --countParen;
            writeFile << eqa[i] << "  -> Close_Parenthesis\n";
            printf("%c  -> Close_Parenthesis\n",eqa[i]);
        } else if(eqa[i] == ' ')
        {
            continue;
        } else if(eqa[i] >= '0' && eqa[i] <= '9')
        {
            temp = eqa[i];
            do {
                if(eqa[i+1] == '.' || eqa[i+1] >= '0' && eqa[i+1] <= '9')
                {
                    temp += eqa[i+1];
                    i++;
                }
                else {
                    break;
                }
            } while (eqa[i] == '.' || eqa[i] >= '0' && eqa[i] <= '9');
            writeFile << temp << "  -> int_literal\n";
            printf("%s   -> int_literal\n",temp.c_str());
        } else if(eqa[i] >= 'A' && eqa[i] <= 'Z' || eqa[i] >= 'a' && eqa[i] <= 'z')
        {
            temp = eqa[i];
            do {
                if(eqa[i+1] >= 'A' && eqa[i+1] <= 'Z' || eqa[i+1] >= 'a' && eqa[i+1] <= 'z')
                {
                    temp += eqa[i+1];
                    i++;
                }
                else {
                    break;
                }
            } while (eqa[i] >= 'A' && eqa[i] <= 'Z' || eqa[i] >= 'a' && eqa[i] <= 'z');
            writeFile << temp << "  -> identifier\n";
            printf("%s   -> int_literal\n",temp.c_str());
        } else if(eqa[i] == ';')
        {
            writeFile << eqa[i] << "  -> End_Marker\n";
            printf("%c  -> End_Marker\n",eqa[i]);
        } else {
            printf("Error '%c' is unknown character!\n",eqa[i]);
            break;
        }
    }
    if (countParen > 0 )
    {
        printf("Error missing closing parenthesis\n");
    }
}

int main() {
    std::ifstream dataFile;
    std::ofstream outfile;
    char readChar;
    std::string line;
        
    dataFile.open("data.txt");
    outfile.open("LexicalAnalysis.out");
    
    if (dataFile.is_open()) 
    {       
        while (dataFile.get(readChar))
        {
           line += readChar;
    	}
    	tokenize(line,outfile);
        dataFile.close();
        outfile.close();
    } else {
    	exit(1);
    }
    
    return 0;
}