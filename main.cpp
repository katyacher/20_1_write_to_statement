#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void write_to_statement(std::string file_name){
    std::ofstream file;
    file.open(file_name, std::ios::app);

    std::string name, surname, date;
    double salary;

    if(file.is_open()){
        std::cout << "Введите имя: ";
        std::cin >> name;
        std::cout << "Введите фамилию: ";
        std::cin >> surname;
        std::cout << "Введите дату: ";
        std::cin >> date;
        std::cout << "Введите зарплату: ";
        std::cin >> salary;
        std::stringstream  record;
        record << name << " " << surname << " " << date << " " << salary;
        //TODO реализовать валидацию данных
        file << record.str() << std::endl;
    } else {
        std::cout << "Error opening file." << std::endl;
    }
    file.close();
};

void show_statement(std::string file_name){
    std::ifstream file;
    file.open(file_name);
    if(file.is_open()){
        std::string record;
        while(!file.eof()){
            getline(file, record);
            std::cout << record << std::endl;
        }
    } else {
        std::cout << "Error opening file." << std::endl;
    }
    file.close();
}

int main() {
    std::cout << "19.5 Implementation of an entry in the statement.\n";

    std::string file_name = "/home/kate/CLionProjects/20_1_write_to_statement/statement.txt";

    while(true){
        std::cout << "Выберете пункт меню: " << std::endl;
        std::cout << "1 - внести запись в ведомость" << std::endl;
        std::cout << "2 - просмотреть содержимое ведомости" << std::endl;
        std::cout << "3 - Выйти из программы" << std::endl;

        int menu;
        std::cin >> menu;

        switch(menu){
            case 1:
                write_to_statement(file_name);
                break;
            case 2:
                show_statement(file_name);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Такого пункта меню нет" << std::endl;
                break;
        }
    }
}