#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool check_dots_count(std::string data){
    int dot_count = 0;
    for(int i = 0; i < data.length(); i++){
        if(data[i] == '.') dot_count++;
    }
    return dot_count == 2;
}

bool is_leap(int year){
    if ((year % 100 == 0) && (year % 400 == 0) || (year % 4 == 0)){
        return true;
    } else
        return false;
}

std::string get_part_str(std::string str) {
    std::string part = "";
    for (int i = 0; str[i] != '.' && i < str.length(); i++) {
        part += str[i];
    }
    return part;
}

bool is_number(std::string part){
    for(int i = 0; i < part.length(); i++){
        if (part[i] >= '0' && part[i] <= '9'){
            continue;
        }else {
            return false;
        }
    }
    return true;
}
bool check_format(std::string date){
    for(int i = 0; i < 2; i++){
        std::string part = get_part_str(date);
        if ( !(part.length() == 2  && is_number(part))){
            return false;
        } else
            date.erase(0,part.length()+1);
    }
    std::string last_part = get_part_str(date);
    if(!(last_part.length() == 4 && is_number(last_part))){
        return false;
    }

    return true;
}

bool validate_date(std::string date) {
    if(!check_dots_count(date)){
        return false;
    }

    if (!check_format(date)){
        return false;
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));;

    if ((year > 0) && (year <= 9999)) {
        if (month >= 1 && month <= 12) {
            if (month == 1 || month == 3 || month == 5 || month == 6 || month == 8 || month == 10 || month == 12) {
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
        std::cout <<"Enter data " << std::endl;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Surname: ";
        std::cin >> surname;
        std::cout << "Date in format DD.MM.YYYY: ";
        std::cin >> date;
        while(!validate_date(date)){
            std::cout << "Incorrect date." << std::endl;
            std::cout << "Enter date in format DD.MM.YYYY: ";
            std::cin >> date;
        }
        std::cout << "Salary: ";
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
        std::cout << "Select menu item: " << std::endl;
        std::cout << "1 - Make an entry in the statement" << std::endl;
        std::cout << "2 - View the contents of the statement" << std::endl;
        std::cout << "3 - Exit the program" << std::endl;

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
                std::cout << "There is no such menu item." << std::endl;
                break;
        }
    }
}
