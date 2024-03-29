#include <iostream>
#include <vector>

using namespace std;

class Student {
    short age;
    string name;    
    string team;
    Student* partner;
public:
    Student(string name, short age){
        this->name = name;
        this->age = age;
    }
    void setFavouriteTeam(string team){
        this->team = team;
    }
    void reportPartner() {
        cout << partner->name << " " << partner->age << " "<< partner->team << endl;
    }

    static void pair(Student &a, Student &b) { 
        a.partner = &b;
        b.partner = &a;
    }
};

int main() {
    Student s1 = Student("John", 17);
    Student s2 = Student("George", 18);

    Student::pair(s1, s2);   

    s1.setFavouriteTeam("Chelsea");
    s2.reportPartner(); // John, 17, fan of Chelsea
}