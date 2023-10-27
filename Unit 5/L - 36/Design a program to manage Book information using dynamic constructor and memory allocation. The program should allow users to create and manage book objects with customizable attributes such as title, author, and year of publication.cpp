




#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    char* author;
    int year;

public:
    Book(const char* _title, const char* _author, int _year) {
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);

        author = new char[strlen(_author) + 1];
        strcpy(author, _author);

        year = _year;
    }

    ~Book() {
        delete[] title;
        delete[] author;
    }

    void setTitle(const char* _title) {
        delete[] title;
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);
    }

    void setAuthor(const char* _author) {
        delete[] author;
        author = new char[strlen(_author) + 1];
        strcpy(author, _author);
    }

    void setYear(int _year) {
        year = _year;
    }

    int getYear() {
        return year;
    }

    void display() {
        cout << "Book Details:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year of Publication: " << year << endl;
    }
};

int main() {
    char title[100];
    char author[100];
    int year, updatedYear;

    cin.getline(title, sizeof(title));
    cin.getline(author, sizeof(author));
    cin >> year >> updatedYear;

    Book book(title, author, year);
    book.display();

    cout << endl << "Updated Year of Publication: " << updatedYear << endl;

    return 0;
}
