#include <iostream>
#include <string>
#include <sstream>
#include <array>
using namespace std;

class ReadIn {
private:
    string _one; string _two;
public:
    string one() { return _one; }
    string two() { return _two; }
    ReadIn()     { cin >> this; }
    friend istream& operator>>(istream& in, ReadIn *self) {
        return in >> self->_one >> self->_two;
    }
};

class Output {
private:
    ReadIn data;
    array<string, 3> outputText;
    void processFirst() {
        ostringstream first;
        first << data.one().size()
              << ' '
              << data.two().size();
        outputText[0] = first.str();
    }
    void processSecond() {
        outputText[1] = data.one() + data.two();
    }
    void processThird() {
        ostringstream last;
        last << data.two()[0]
             << (data.one().c_str() + 1)
             << ' '
             << data.one()[0]
             << data.two().c_str() + 1;
        outputText[2] = last.str();
    }
    void processData() {
        processFirst(); processSecond(); processThird();
    }
public:
    Output(ReadIn d = ReadIn {}): data(d) {
        processData();
    }
    // forward indexing of Output to outputText
    string operator[](const size_t index) {
        if( index >= outputText.size() || index < 0 )
            throw out_of_range("Output can only be indexed between 0 and 3");
        return outputText[index];
    }
    friend ostream& operator<<(ostream& out, Output &self) {
        return out << self[0]
           << '\n' << self[1]
           << '\n' << self[2];
    }
};

int main() {
    // Complete the program
    Output result;
    cout << result;
    return 0;
}

