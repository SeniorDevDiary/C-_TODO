void showMenu() {
    std::cout << "\nTODO List Menu:\n";
    std::cout << "1. Add TODO item\n";
    std::cout << "2. View TODO items\n";
    std::cout << "3. Delete TODO item\n";
    std::cout << "4. Mark TODO item as completed\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    TodoList todoList;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // To ignore the newline character left in the buffer
                std::cout << "Enter description: ";
                std::string description;
                std::getline(std::cin, description);
                todoList.addItem(description);
                break;
            }
            case 2:
                todoList.viewItems();
                break;
            case 3: {
                std::cout << "Enter item ID to delete: ";
                int id;
                std::cin >> id;
                todoList.deleteItem(id);
                break;
            }
            case 4: {
                std::cout << "Enter item ID to mark as completed: ";
                int id;
                std::cin >> id;
                todoList.markComplete(id);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
