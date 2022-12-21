# Validator

入力された文字列が、条件を満たすか判定して、数値を返します。

満たさない場合、`std::nullopt` を返します。

## Condition Rule

```
cond  ::= '[' item % ',' ']'
item  ::= num | range | enum
num   ::= -('0x' | '0' | '0b') *[0-9]
range ::= num ':' num
enum  ::= num '=' ident
```

条件リストの先頭から走査して、マッチしたら値を返します。

## 使い方

```cpp:
Validatar(std::string condition)
std::optional<int> match(std::string value)
```

```cpp:
Validator cond("[0=NULL,0:4,5,7,11,13]");
cond.match("NULL"); // > 0
cond.match("10");   // > std::nullopt
```

## TODO

- Error Handling
