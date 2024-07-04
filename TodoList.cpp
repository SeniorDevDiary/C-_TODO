class TodoList {
private:
    std::vector<TodoItem> items;
    int nextId;

public:
    TodoList() : nextId(1) {}

    void addItem(const std::string& description) {
        items.emplace_back(nextId++, description);
        std::cout << "Item added successfully.\n";
    }

    void viewItems() const {
        if (items.empty()) {
            std::cout << "No TODO items found.\n";
            return;
        }
        for (const auto& item : items) {
            std::cout << item.id << ". " << item.description 
                      << (item.completed ? " [Completed]" : "") << '\n';
        }
    }

    void deleteItem(int id) {
        auto it = std::remove_if(items.begin(), items.end(),
            [id](const TodoItem& item) { return item.id == id; });
        if (it != items.end()) {
            items.erase(it, items.end());
            std::cout << "Item deleted successfully.\n";
        } else {
            std::cout << "Item not found.\n";
        }
    }

    void markComplete(int id) {
        for (auto& item : items) {
            if (item.id == id) {
                item.completed = true;
                std::cout << "Item marked as completed.\n";
                return;
            }
        }
        std::cout << "Item not found.\n";
    }
};
