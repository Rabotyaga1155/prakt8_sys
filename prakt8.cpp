#include <iostream>
#include <algorithm>
#include <cstring>

struct Person {
    char name[100];
    int birthYear;
    char gender;
    char maritalStatus[100];

    union {
        bool isConscript;
        char address[100];
    } additionalInfo;
};

bool compareByBirthYear(const Person& a, const Person& b) {
    return a.birthYear < b.birthYear;
}

int main() {
    setlocale(LC_ALL, "rus");
    Person people[4] = {
        {"Анна Смирнова", 1985, 'F', "женат (замужем)", {"ул. Ленина, 1"}},
        {"Мария Иванова", 1990, 'F', "женат (замужем)", {"ул. Советская, 2"}},
        {"Елена Петрова", 1980, 'F', "женат (замужем)", {"ул. Кирова, 3"}},
        {"Мария Иванова", 1990, 'M', "женат (замужем)", {"ул. Советская, 2"}}
    };

    Person marriedWomen[4];
    int count = 0;

    for (int i = 0; i < 4; ++i) {
        if (people[i].gender == 'F' && strcmp(people[i].maritalStatus, "женат (замужем)") == 0) {
            marriedWomen[count++] = people[i];
        }
    }

    std::sort(marriedWomen, marriedWomen + count, compareByBirthYear);

    for (int i = 0; i < count; ++i) {
        std::cout << marriedWomen[i].name << ", " << marriedWomen[i].birthYear << ", " << marriedWomen[i].additionalInfo.address << std::endl;
    }

    return 0;
}
