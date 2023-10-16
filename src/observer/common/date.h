//
// Created by Lenovo on 2023/10/15.
//

#ifndef MINIDB_DATE_H
#define MINIDB_DATE_H

#endif  // MINIDB_DATE_H

#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <sstream>
#include "common/rc.h"
#include "sql/parser/parse_defs.h"

inline bool is_leap_year(int year) { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }

inline bool is_valid_date(int32_t date_int) {
  int year, month, day;
  year = date_int / 10000;
  month = (date_int % 10000) / 100;
  day = date_int % 100;
  if (year < 1900 || year > 9999 || month <= 0 || month > 12 || day <= 0 || day > 31) {
    return false;
  }

  int max_day_in_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int max_day = max_day_in_month[month - 1];
  if (day > max_day) {
    return false;
  }
  if (month == 2 && !is_leap_year(year) && day > 28) {
    return false;
  }
  return true;
}

inline RC string_to_date(const char *str, int32_t &date) {
  int year, month, day;
  int ret = sscanf(str, "%d-%d-%d", &year, &month, &day);
  if (ret != 3) {
    return RC::INVALID_ARGUMENT;
  }
  date = year * 10000 + month * 100 + day;
  return RC::SUCCESS;
}