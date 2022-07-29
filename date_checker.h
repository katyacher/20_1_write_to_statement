#pragma once
/*
#ifndef INC_20_1_WRITE_TO_STATEMENT_DATE_CHECKER_H
#define INC_20_1_WRITE_TO_STATEMENT_DATE_CHECKER_H

#endif //INC_20_1_WRITE_TO_STATEMENT_DATE_CHECKER_H*/

bool check_dots_count(std::string data);

bool is_leap(int year);

std::string get_part_str(std::string str);

bool is_number(std::string part);

bool check_format(std::string date);

bool validate_date(std::string date);