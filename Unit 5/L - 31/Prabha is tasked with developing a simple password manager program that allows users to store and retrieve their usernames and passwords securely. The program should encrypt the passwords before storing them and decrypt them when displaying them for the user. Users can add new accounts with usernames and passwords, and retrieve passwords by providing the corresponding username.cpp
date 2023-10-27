















#include <iostream>
#include <string>

const int ENCRYPTION_SHIFT = 3;  
const int MAX_USERS = 10;

std::string encryptPassword(const std::string &password) {
    std::string encrypted = password;
    for (char &c : encrypted) {
        c += ENCRYPTION_SHIFT;
    }
    return encrypted;
}

std::string decryptPassword(const std::string &encryptedPassword) {
    std::string decrypted = encryptedPassword;
    for (char &c : decrypted) {
        c -= ENCRYPTION_SHIFT;
    }
    return decrypted;
}

int main() {
    std::string* usernames = new std::string[MAX_USERS];
    std::string* passwords = new std::string[MAX_USERS];
    int userCount = 0;
    int choice;

    while (true) {
        if (!(std::cin >> choice)) {  
            break;  
        }
        
        switch (choice) {
            case 1: {
                if (userCount == MAX_USERS) {
                    std::cout << "Maximum number of users reached." << std::endl;
                    break;
                }
                std::string username, password;
                std::cin >> username >> password;
                usernames[userCount] = username;
                passwords[userCount] = encryptPassword(password);
                userCount++;
                break;
            }
            case 2: {
                std::string username;
                std::cin >> username;
                bool found = false;
                for (int i = 0; i < userCount; i++) {
                    if (usernames[i] == username) {
                        std::cout << "Password for user '" << username << "' is: " << decryptPassword(passwords[i]) << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "User not found." << std::endl;
                }
                break;
            }
            case 3:
                delete[] usernames;
                delete[] passwords;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    // Clean up
    delete[] usernames;
    delete[] passwords;
    return 0;
}
