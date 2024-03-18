#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <windows.h>
#include <iomanip>
#include <bitset>



static std::string hexToBinary(char hexValue) {
    std::string binaryValue;
    switch (hexValue) {
        case 0: binaryValue = "00000000"; break;
        case 1: binaryValue = "00000001"; break;
        case 2: binaryValue = "00000010"; break;
        case 3: binaryValue = "00000011"; break;
        case 4: binaryValue = "00000100"; break;
        case 5: binaryValue = "00000101"; break;
        case 6: binaryValue = "00000110"; break;
        case 7: binaryValue = "00000111"; break;
        case 8: binaryValue = "00001000"; break;
        case 9: binaryValue = "00001001"; break;
        case 10: binaryValue = "00001010"; break;
        case 11: binaryValue = "00001011"; break;
        case 12: binaryValue = "00001100"; break;
        case 13: binaryValue = "00001101"; break;
        case 14: binaryValue = "00001110"; break;
        case 15: binaryValue = "00001111"; break;
        case 16: binaryValue = "00010000"; break;
        case 17: binaryValue = "00010001"; break;
        case 18: binaryValue = "00010010"; break;
        case 19: binaryValue = "00010011"; break;
        case 20: binaryValue = "00010100"; break;
        case 21: binaryValue = "00010101"; break;
        case 22: binaryValue = "00010110"; break;
        case 23: binaryValue = "00010111"; break;
        case 24: binaryValue = "00011000"; break;
        case 25: binaryValue = "00011001"; break;
        case 26: binaryValue = "00011010"; break;
        case 27: binaryValue = "00011011"; break;
    }
    return binaryValue;
}
class RAM{
public:

    std::string inputA = "0000";
    std::string inputB = "0000";
    size_t input_portA{};
    size_t input_portB{};
    size_t Register_A = 0;
    size_t Register_B = 0;
    size_t c_flag = 0;
    size_t program_counter = -1;
    size_t output_port = 0;
    std::string InputA;
    std::string InputB;

    std::vector<char> firstDigits, secondDigits, thirdDigits;
    char buffer[3];

    std::vector<int> decimalValues,decimalValues2,sumVec;


    std::string s;
    std::vector<std::string> binaryString;

    std::vector<std::string> stringVector;
    std::string binaryValss,instss;
};



class ROM{
public:
    RAM ram;
    friend class RAM;



    int calculations(){
        return 1;
        std::ifstream file("C:\\Users\\PC\\CLionProjects\\hzKakNazvat\\input.bin", std::ios::binary);
        if (!file.is_open()) {
            std::cout << "Не удалось открыть файл input.bin\n";
            return 1;
        }
        ///Первые два вектора это первые два байта которые считываются и скалыдваются в векторе sumVec после этого преобразуются в   std::string s; в bitset<8>

        while (file.read(ram.buffer, 3)) {
            ram.firstDigits.push_back(ram.buffer[0]);
            ram.secondDigits.push_back(ram.buffer[1]);
            ram.thirdDigits.push_back(ram.buffer[2]);
            file.seekg(1, std::ios::cur); // Пропускаем пробел между группами цифр
        }

        file.close();
        ///decimalValues и decimalValues2  суммируются в sumVec и получается


        for (char c : ram.firstDigits) {
            // Преобразование из 16-ричной системы в 10-ную
            int decimalValue = std::stoi(std::string(1, c), 0, 16);
            ram.decimalValues.push_back(decimalValue);
        }
        for (char c : ram.secondDigits) {
            // Преобразование из 16-ричной системы в 10-ную
            int decimalValue = std::stoi(std::string(1, c), 0, 16);
            ram.decimalValues2.push_back(decimalValue);
        }
        for (size_t i = 0; i < ram.decimalValues.size(); i++) {
            ram.sumVec.push_back(ram.decimalValues[i] + ram.decimalValues2[i]);

        }
        for (int i = 0; i < ram.sumVec.size() ; ++i) {
            std::cout<<ram.sumVec[i]<<" ";
        }
        std::cout<<"\n";



        // Вывод результата
    std::cout << "Первые цифры из каждой группы: ";
    for (char digit : ram.firstDigits) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    std::cout << "Вторые цифры из каждой группы: ";
    for (char digit : ram.secondDigits) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    std::cout << "Третьи цифры из каждой группы: ";
    for (char digit : ram.thirdDigits) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;


//////////////////


        for (int value : ram.sumVec) {
            ram.s = std::bitset<8>(value).to_string(); // Двоичное представление с ведущими нулями до 8 бит
            ram.binaryString.push_back(ram.s);
            std::cout << ram.s << " ";
        }
//////


        for (char c : ram.thirdDigits) {
            int hexValue;
            std::sscanf(&c, "%x", &hexValue); // Преобразуем char в шестнадцатеричное число
            ram.stringVector.push_back(std::bitset<4>(hexValue).to_string()); // Конвертируем шестнадцатеричное число в двоичную систему счисления и добавляем вектору строк
        }

        // Выводим результат
        for (const std::string& binaryString1 : ram.stringVector) {
            std::cout <<" stringVector"<< binaryString1 << " ";
        }
/////////
    for (const auto & i : ram.binaryString) {
        if(i=="00000010"){
            std::cout<<"Input A: ";
            std::cin>>ram.InputA;
            std::cout<<std::endl;
        }
        if(i=="00000110"){
            std::cout<<"Input B: ";
            std::cin>>ram.InputB;
            std::cout<<std::endl;
        }
    }
        return 0;
        std::cout<<"\n";
        std::cout<<"GG";
        return 0;
    }

    void dosmth(const std::string& inst,const std::string& im,const std::string& binaryCode,std::string inputA,std::string inputB) {
        switch (stoi(inst, nullptr,2)) {
            case 0: ///0000
                if ((ram.Register_A + stoi(im, nullptr,2)) > 15) {
                    ram.Register_A = (ram.Register_A + stoi(im, nullptr,2)) - 15;
                    ram.c_flag = 1;
                } else {
                    ram.Register_A = ram.Register_A + stoi(im, nullptr,2);
                }
               ram.program_counter++;
                break;
            case 5: ///0101
                if ((ram.Register_B + stoi(im, nullptr,2)) > 15) {
                    ram.Register_B = (ram.Register_B + stoi(im, nullptr,2)) - 15;
                    ram.c_flag = 1;
                } else {
                    ram.Register_B = ram.Register_B + stoi(im, nullptr,2);
                }
                ram.program_counter++;
                break;
            case 3: ///0011
                ram.Register_A = stoi(im, nullptr,2);
                ram.program_counter++;
                break;
            case 7: ///0111
                ram.Register_B = stoi(im, nullptr,2);
                ram.program_counter++;
                break;
            case 1: ///0001
                ram.Register_A = ram.Register_B;
                ram.program_counter++;
                break;
            case 4: ///0100
                ram.Register_B = ram.Register_A;
                ram.program_counter++;
                break;
            case 15: ///1111
                ram.program_counter = stoi(im, nullptr,2);
                break;
            case 14: ///1110
                if (ram.c_flag == 0) {
                    ram.program_counter = stoi(im, nullptr,2);
                } else {
                    ram.program_counter++;
                }
                break;
            case 2: ///0010
                ram.input_portA=stoi(inputA, nullptr,2);
                ram.Register_A =ram.input_portA;
                ram.program_counter++;
                break;
            case 6: ///0110
                ram.input_portB=stoi(inputB, nullptr,2);
                ram.Register_B = ram.input_portB;
                ram.program_counter++;
                break;
            case 9: ///1001
                ram.output_port = ram.Register_B;
                ram.program_counter++;
                break;
            case 11: ///1011
                ram.output_port = stoi(im, nullptr,2);
                ram.program_counter++;
                break;
                ////////////////////////////////
            case 8: ///1000
                ram.Register_A = ram.Register_A - stoi(im, nullptr, 2);
                if (ram.Register_A < 0) {
                    ram.c_flag = 1;
                    ram.Register_A += 16;
                }
                ram.program_counter++;
                break;
            case 10: ///1010
                ram.Register_B = ram.Register_B - stoi(im, nullptr, 2);
                if (ram.Register_B < 0) {
                    ram.c_flag = 1;
                    ram.Register_B += 16;
                }
                ram.program_counter++;
                break;
            case 12: ///1100
                ram.Register_A = ram.Register_A & stoi(im, nullptr, 2);
                ram.program_counter++;
                break;
            case 13: ///1101
                ram.Register_B = ram.Register_B & stoi(im, nullptr, 2);
                ram.program_counter++;
                break;
            case 16: ///10000
                ram.Register_A = ram.Register_A | stoi(im, nullptr, 2);
                ram.program_counter++;
                break;
            case 17: ///10001
                ram.Register_B = ram.Register_B | stoi(im, nullptr, 2);
                ram.program_counter++;
                break;
            case 18: ///10010
                ram.Register_A = ram.Register_A ^ stoi(im, nullptr, 2);
                ram.program_counter++;
                break;
            case 19: ///10011
                ram.Register_B = ram.Register_B ^ stoi(im, nullptr, 2);
                ram.program_counter++;
                break;
            case 20: ///10100
                ram.c_flag = 0;
                ram.program_counter++;
                break;
            case 21: ///10101
                ram.Register_A = ram.Register_A << 1;
                if (ram.Register_A >= 16) {
                    ram.Register_A -= 16;
                    ram.c_flag = 1;
                }
                ram.program_counter++;
                break;
            case 22: ///10110
                ram.Register_B = ram.Register_B << 1;
                if (ram.Register_B >= 16) {
                    ram.Register_B -= 16;
                    ram.c_flag = 1;
                }
                ram.program_counter++;
                break;
            case 23: ///10111
                ram.Register_A = ram.Register_A >> 1;
                ram.program_counter++;
                break;
            case 24: ///11000
                ram.Register_B = ram.Register_B >> 1;
                ram.program_counter++;
                break;
            case 25: ///11001
                ram.Register_A = ~ram.Register_A;
                ram.program_counter++;
                break;
            case 26: ///11010
                ram.Register_B = ~ram.Register_B;
                ram.program_counter++;
                break;
            case 27: ///11011
                if (ram.c_flag == 1) {
                    ram.program_counter = stoi(im, nullptr, 2);
                } else {
                    ram.program_counter++;
                }
                break;
        }
/*
8: SUB A, #двоичная_строка
10: SUB B, #двоичная_строка
12: AND A, #двоичная_строка
13: AND B, #двоичная_строка
16: OR A, #двоичная_строка
17: OR B, #двоичная_строка
18: XOR A, #двоичная_строка
19: XOR B, #двоичная_строка
20: CLR c_flag
21: ROL A
22: ROL B
23 DIV_A - деление числа, хранящегося в регистре A, на 2, а затем увеличение счетчика программы на 1
24 DIV_B - деление числа, хранящегося в регистре B, на 2, а затем увеличение счетчика программы на 1
25 NOT_A - операция побитового НЕ над числом, хранящимся в регистре A, а затем увеличение счетчика программы на 1
26 NOT_B - операция побитового НЕ над числом, хранящимся в регистре B, а затем увеличение счетчика программы на 1
27 JUMP_IF_C - переход на указанную в инструкции адресную ячейку, если c_flag равен 1, иначе увеличение счетчика программы на 1
 SUB A, #двоичная_строка - команда вычитает двоичную строку из регистра A.
SUB B, #двоичная_строка - команда вычитает двоичную строку из регистра B.
AND A, #двоичная_строка - команда выполняет логическую операцию "и" между содержимым регистра A и двоичной строкой.
AND B, #двоичная_строка - команда выполняет логическую операцию "и" между содержимым регистра B и двоичной строкой.
OR A, #двоичная_строка - команда выполняет логическую операцию "или" между содержимым регистра A и двоичной строкой.
OR B, #двоичная_строка - команда выполняет логическую операцию "или" между содержимым регистра B и двоичной строкой.
XOR A, #двоичная_строка - команда выполняет логическую операцию "исключающее или" между содержимым регистра A и двоичной строкой.
XOR B, #двоичная_строка - команда выполняет логическую операцию "исключающее или" между содержимым регистра B и двоичной строкой.
CLR c_flag - команда очищает флаг переноса.
ROL A - команда циклически сдвигает содержимое регистра A влево.
ROL B - команда циклически сдвигает содержимое регистра B влево.
 */
//output_port<<" Output Port " <<
        std::cout<<std::endl;
        std::cout<<"ProgramCounter "<<std::bitset<4>(ram.program_counter)<<" Register A "<<std::bitset<4>(ram.Register_A)<<" Register B "<<std::bitset<4>(ram.Register_B)<<" C Flag " <<ram.c_flag<<" ";

        std::string instruction;
        if (binaryCode == "00000000") {
            instruction = "ADD A,";
            std::cout<<"ADD A,"<<im<<" ";
        } else if (binaryCode == "00000101") {
            instruction = "ADD B,";
            std::cout<<"ADD B,"<<im<<" ";
        } else if (binaryCode == "00000011") {
            instruction = "MOV A,";
            std::cout<<"MOV A,"<<im<<" ";
        } else if (binaryCode == "00000111") {
            instruction = "MOV B,";
            std::cout<<"MOV B,"<<im<<" ";
        } else if (binaryCode == "00000001") {
            instruction = "MOV A,B";
            std::cout<<"MOV A,B"<<" ";
        } else if (binaryCode == "00000100") {
            instruction = "MOV B,A";
            std::cout<<"MOV B,A"<<" ";
        } else if (binaryCode == "00001111") {
            instruction = "JMP ";
            std::cout<<"JMP,"<<im<<" ";
        } else if (binaryCode == "00001110") {
            instruction = "JNC ";
            std::cout<<"JNC,"<<im<<" ";
        } else if (binaryCode == "00000010") {
            instruction = "IN A";
            std::cout<<"IN A,"<<" ";
        } else if (binaryCode == "00000110") {
            instruction = "IN B";
            std::cout<<"IN B,"<<" ";
        } else if (binaryCode == "00001001") {
            instruction = "OUT B";
            std::cout<<"OUT B,"<<" ";
        } else if (binaryCode == "00001011") {
            instruction = "OUT ";
            std::cout<<"OUT ,"<<im<<" ";
        }else if (binaryCode == "00001000") {
            instruction = "SUB A,";
            std::cout<<"SUB A,"<<im<<" ";
        } else if (binaryCode == "00001010") {
            instruction = "SUB B, ";
            std::cout<<"SUB B,"<<im<<" ";
        } else if (binaryCode == "00001100") {
            instruction = "AND A,";
            std::cout<<"AND A,"<<im<<" ";
        } else if (binaryCode == "00001101") {
            instruction = "AND B,";
            std::cout<<"AND B,"<<im<<" ";
        } else if (binaryCode == "00010000") {
            instruction = "OR A,";
            std::cout<<"OR A,"<<im<<" ";
        } else if (binaryCode == "00010001") {
            instruction = "OR B, ";
            std::cout<<"OR B,"<<im<<" "; }
        else if (binaryCode == "00010010") {
            instruction = "XOR A,";
            std::cout<<"XOR A,"<<im<<" ";
        } else if (binaryCode == "00010011") {
            instruction = "XOR B, ";
            std::cout<<"XOR B,"<<im<<" ";
        } else if (binaryCode == "00010100") {
            instruction = "CLR c_flag";
            std::cout<<"CLR c_flag"<<" ";
        } else if (binaryCode == "00010101") {
            instruction = "ROL A";
            std::cout<<"ROL A"<<" ";
        } else if (binaryCode == "00010110") {
            instruction = "ROL B";
            std::cout<<"ROL B"<<" ";
        } else if (binaryCode == "00010111") {
            instruction = "DIV_A ";
            std::cout << "DIV_A," <<im<< " ";
        }
        else if (binaryCode == "00011000") {
            instruction = "DIV_B";
            std::cout<<"DIV_B,"<<im<<" ";
        } else if (binaryCode == "00011001") {
            instruction = "NOT_A ";
            std::cout<<"NOT_A,"<<im<<" ";
        } else if (binaryCode == "00011010") {
            instruction = "NOT_B";
            std::cout<<"NOT_B,"<<im<<" ";
        } else if (binaryCode == "00011011") {
            instruction = "JUMP_IF_C";
            std::cout<<"JUMP_IF_C"<<" ";
        }
        ram.c_flag = 0;
    }
};


class TD4M{
public:


friend class ROM;
RAM ram;
ROM rom;
int main1(){

//
//    std::ifstream file("C:\\Users\\PC\\CLionProjects\\hzKakNazvat\\input.bin", std::ios::binary);
//    if (!file.is_open()) {
//        std::cout << "Не удалось открыть файл input.bin\n";
//        return 1;
//    }
//    ///Первые два вектора это первые два байта которые считываются и скалыдваются в векторе sumVec после этого преобразуются в   std::string s; в bitset<8>
//
//    while (file.read(ram.buffer, 3)) {
//        ram.firstDigits.push_back(ram.buffer[0]);
//        ram.secondDigits.push_back(ram.buffer[1]);
//        ram.thirdDigits.push_back(ram.buffer[2]);
//        file.seekg(1, std::ios::cur); // Пропускаем пробел между группами цифр
//    }
//
//    file.close();
//    ///decimalValues и decimalValues2  суммируются в sumVec и получается
//
//
//    for (char c : ram.firstDigits) {
//        // Преобразование из 16-ричной системы в 10-ную
//        int decimalValue = std::stoi(std::string(1, c), 0, 16);
//        ram.decimalValues.push_back(decimalValue);
//    }
//    for (char c : ram.secondDigits) {
//        // Преобразование из 16-ричной системы в 10-ную
//        int decimalValue = std::stoi(std::string(1, c), 0, 16);
//        ram.decimalValues2.push_back(decimalValue);
//    }
//    for (size_t i = 0; i < ram.decimalValues.size(); i++) {
//        ram.sumVec.push_back(ram.decimalValues[i] + ram.decimalValues2[i]);
//
//    }
//    for (int i = 0; i < ram.sumVec.size() ; ++i) {
//        std::cout<<ram.sumVec[i]<<" ";
//    }
//    std::cout<<"\n";
//    // Вывод результата
//
//
//    // Вывод результата
////    std::cout << "Первые цифры из каждой группы: ";
////    for (char digit : ram.firstDigits) {
////        std::cout << digit << " ";
////    }
////    std::cout << std::endl;
////
////    std::cout << "Вторые цифры из каждой группы: ";
////    for (char digit : ram.secondDigits) {
////        std::cout << digit << " ";
////    }
////    std::cout << std::endl;
////
////    std::cout << "Третьи цифры из каждой группы: ";
////    for (char digit : ram.thirdDigits) {
////        std::cout << digit << " ";
////    }
////    std::cout << std::endl;
//
//
////////////////////
//
//
//    for (int value : ram.sumVec) {
//        ram.s = std::bitset<8>(value).to_string(); // Двоичное представление с ведущими нулями до 8 бит
//        ram.binaryString.push_back(ram.s);
//        std::cout << ram.s << " ";
//    }
////////
////    std::stringstream ss;
////    for (const char& c : thirdDigits) {
////        int value;
////        std::stringstream converter;
////        converter << c;
////        converter >> std::hex >> value; // Преобразование символа из 16-ричного представления в числовое значение
////        ss << value;
////
////    }
//
////    std::string im=ss.str();
////    std::cout<<im<<" ";
///////////////
//
//    for (char c : ram.thirdDigits) {
//        int hexValue;
//        std::sscanf(&c, "%x", &hexValue); // Преобразуем char в шестнадцатеричное число
//        ram.stringVector.push_back(std::bitset<4>(hexValue).to_string()); // Конвертируем шестнадцатеричное число в двоичную систему счисления и добавляем вектору строк
//    }
//
//    // Выводим результат
//    for (const std::string& binaryString1 : ram.stringVector) {
//        std::cout <<" stringVector"<< binaryString1 << " ";
//    }
///////////
////    for (const auto & i : binaryString) {
////        if(i=="00000010"){
////            std::cout<<"Input A: ";
////            std::cin>>InputA;
////            std::cout<<std::endl;
////        }
////        if(i=="00000110"){
////            std::cout<<"Input B: ";
////            std::cin>>InputB;
////            std::cout<<std::endl;
////        }
////    }
//
//    std::cout<<"\n";
if(rom.calculations()){
    std::cout<<"FSDSA"<<"\n";
}
std::cout<<ram.binaryString.size();
    do {
        std::cout<<"1"<<"\n";
        for (int i = 0; i < ram.binaryString.size(); ++i) {
            ram.binaryValss=ram.binaryString[i];
            std::cout<<"2"<<"\n";
            //  std::cout<<binaryValss<<" ";
            ram.instss=ram.stringVector[i];
            // std::cout<<instss<<" ";
            rom.dosmth(ram.binaryValss, ram.instss,ram.binaryValss,ram.InputA,ram.InputB);
        }
    } while (_getwch()==' ');
    return 0;


}

};




int main() {
    SetConsoleOutputCP(CP_UTF8);
    TD4M processor;
    processor.main1();

}


