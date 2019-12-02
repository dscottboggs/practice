#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



#define CLASSES 6

class Person {
    string name;
    int age;
public:
    Person() = default;
    ~Person() = default;
    virtual void getdata() { getperson(); }
    virtual void putdata() { putperson(); }
protected:
    void getperson() { cin >> name >> age; }
    void putperson() { cout << name << ' ' << age; }
};

class Professor: public Person {
    int publications, cur_id;
public:
    Professor() = default;
    ~Professor() = default;
    static int count;
    void getdata() {
        getperson();
        cin >> publications;
        cur_id = ++count;
    }
    void putdata() {
        putperson();
        cout << ' ' << publications << ' ' << cur_id << '\n';
    }
};

class Student: public Person {
    int marks[CLASSES], cur_id;
    long long sumOfMarks() {
        long long total = 0;
        for( int mark : marks ) total += mark;
        return total;
    }
public:
  Student() = default;
  ~Student() = default;
  static int count;
  void getdata() {
    getperson();
    for (int i = 0; i < CLASSES; i++)
      cin >> marks[i];
    cur_id = ++count;
    }
    void putdata() {
        putperson();
        cout << ' ' << sumOfMarks() << ' ' << cur_id << '\n';
    }
};

int Professor::count = 0;
int Student::count = 0;

