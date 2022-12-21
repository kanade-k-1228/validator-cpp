#pragma once
#include <optional>
#include <string>
#include <vector>

namespace Valid {
struct CondItem {
  enum Type {
    NUM,
    RANGE,
    ENUM
  };
  Type type;
  int num, end;
  std::string label;
public:
  CondItem(std::string cond);
  std::optional<int> match(std::string value);
  std::string print();
};

class Condition {
  std::vector<CondItem> cond;
public:
  Condition(std::string cond_str);
  std::optional<int> match(std::string value);
  std::string print();
};
}  // namespace Valid
