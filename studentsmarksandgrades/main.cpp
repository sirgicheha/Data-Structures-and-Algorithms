#include <iostream>

using namespace std;

#include <iostream>
#include <string>
#include <vector>

struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    string registration_number;
    string name;
    int age;
    Course course;
    vector<Grade> grades;
};

const int MAX_STUDENTS = 40;
Student students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    if (num_students >= MAX_STUDENTS) {
        cout << "Error: Maximum number of students reached." << endl;
        return;
    }
    Student s;
    cout << "Enter registration number: ";
    cin >> s.registration_number;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter course code: ";
    cin >> s.course.course_code;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, s.course.course_name);
    students[num_students] = s;
    num_students++;
}

void edit_student() {
    string reg_num;
    cout << "Enter registration number of student to edit: ";
    cin >> reg_num;
    for (int i = 0; i < num_students; i++) {
        if (students[i].registration_number == reg_num) {
            cout << "Enter new registration number: ";
            cin >> students[i].registration_number;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new age: ";
            cin >> students[i].age;
            cout << "Enter new course code: ";
            cin >> students[i].course.course_code;
            cout << "Enter new course name: ";
            cin.ignore();
            getline(cin, students[i].course.course_name);
            return;
        }
    }
    cout << "Error: Student not found." << endl;
}

void add_mark() {
    string reg_num;
    int mark;
    cout << "Enter registration number of student: ";
    cin >> reg_num;
    for (int i = 0; i < num_students; i++) {
        if (students[i].registration_number == reg_num) {
            cout << "Enter mark: ";
            cin >> mark;
            if (mark < 0 || mark > 100) {
                cout << "Error: Mark must be between 0 and 100." << endl;
                return;
            }
            Grade g;
            g.mark = mark;
            if (mark > 69) {
                g.the_grade = 'A';
            } else if (mark > 59) {
                g.the_grade = 'B';
            } else if (mark > 49) {
                g.the_grade = 'C';
            } else if (mark > 39) {
                g.the_grade = 'D';
            } else {
                g.the_grade = 'E';
            }
            students[i].grades.push_back(g);
            return;
        }
    }
    cout << "Error: Student not found." << endl;
}

void print_students() {
    cout << "Registration Number\tName\t\tAge\tCourse Code\tCourse Name" << endl;
    for (int i = 0; i < num_students; i++) {
        cout << students[i].registration_number << "\t"
                  << students[i].name << "\t"
                  << students[i].age << "\t"
                  << students[i].course.course_code << "\t"
                  << students[i].course.course_name << endl;
    }
}

int main() {
    while (true) {
        cout << "1. Add student\n"
                  << "2. Edit student\n"
                  << "3. Add mark\n"
                  << "4. Print students\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                edit_student();
                break;
            case 3:
                add_mark();
                break;
            case 4:
                print_students();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
