#include <iostream>
#include <vector>
#include <string>

struct TodoItem {
    int id;
    std::string description;
    bool completed;

    TodoItem(int id, const std::string& desc)
        : id(id), description(desc), completed(false) {}
};
