#include "validator.hpp"
#include <cctype>
#include <iostream>
#include <regex>

namespace Valid {
CondItem::CondItem(std::string cond) {
  for(int i = 0; i < cond.size(); ++i) {
    if(cond.at(i) == ':') {
      type = RANGE;
      num = std::stoi(cond.substr(0, i), nullptr, 0);
      end = std::stoi(cond.substr(i + 1), nullptr, 0);
      return;
    }
    if(cond.at(i) == '=') {
      type = ENUM;
      num = std::stoi(cond.substr(0, i), nullptr, 0);
      label = cond.substr(i + 1);
      return;
    }
  }
  type = NUM;
  num = std::stoi(cond, nullptr, 0);
  return;
}

std::optional<int> CondItem::match(std::string value) {
  if(type == NUM) {
    try {
      int n = std::stoi(value, nullptr, 0);
      if(n == num) return n;
    } catch(const std::exception& e) {
    }
  }
  if(type == RANGE) {
    try {
      int n = std::stoi(value, nullptr, 0);
      if(num <= n && n < end) return n;
    } catch(const std::exception& e) {
    }
  }
  if(type == ENUM) {
    try {
      int n = std::stoi(value, nullptr, 0);
      if(n == num) return n;
    } catch(const std::exception& e) {
      if(label == value) return num;
    }
  }
  return std::nullopt;
}

std::string CondItem::print() {
  std::stringstream ss;
  if(type == NUM) ss << num;
  if(type == RANGE) ss << num << ":" << end;
  if(type == ENUM) ss << num << "=" << label;
  return ss.str();
}

Condition::Condition(std::string cond_str) {
  if(*cond_str.begin() != '[') exit(EXIT_FAILURE);
  if(*cond_str.rbegin() != ']') exit(EXIT_FAILURE);
  cond_str.erase(0, 1);
  cond_str.pop_back();
  std::stringstream ss{cond_str};
  for(std::string buf; std::getline(ss, buf, ',');) {
    buf.erase(std::remove_if(buf.begin(), buf.end(), ::isspace), buf.end());
    cond.emplace_back(buf);
  }
}

std::optional<int> Condition::match(std::string value) {
  for(auto c : cond) {
    auto result = c.match(value);
    if(result) return result.value();
  }
  return std::nullopt;
}

std::string Condition::print() {
  std::stringstream ss;
  ss << "[";
  for(auto c : cond) ss << c.print() << ",";
  ss << "\b \b]";
  return ss.str();
}
}  // namespace Valid
