#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool check_dots_count(std::string ip_str){
    int dot_count = 0;
    for(int i = 0; i < ip_str.length(); i++){
        if(ip_str[i] == '.') dot_count++;
    }
    return (dot_count > 2)? false: true;
}

bool is_leap(int year){
    if ((year % 100 == 0) && (year % 400 == 0) || (year % 4 == 0)){
        return true;
    } else
        return false;
}

bool validate_date(std::string date) {
    // parse the date to day, month and year
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));;

    if ((year > 0) && (year <= 9999)) {
        if (month >= 1 && month <= 12) {
            if (month == 1 || month == 3 || month == 5 || month == 6 || month == 8 || month == 10) {
                if (day >= 1 && day <= 31) return true;
            } else if (month == 4 || month == 7 || month == 9 || month == 11) {
                if (day >= 1 && day <= 30) return true;
            } else if (month == 2) {
                if (is_leap(year)) {
                    if (day >= 1 && day <= 29) return true;
                } else if (day >= 1 && day <= 28) return true;
            }
        }
    }
    return false;
}
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
        while(!(check_dots_count(date) && validate_date(date))){
            std::cout << "Incorrect date." << std::endl;
            std::cout << "Введите дату: ";
            std::cin >> date;
        }
        std::cout << "Введите зарплату: ";
        std::cin >> salary;
        std::stringstream  record;
        record << name << " " << surname << " " << date << " " << salary;
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
