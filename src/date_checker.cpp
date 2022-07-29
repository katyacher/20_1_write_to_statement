#include <string>
#include "../include/date_checker.h"

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
    int year = std::stoi(date.substr(6, 4));

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
