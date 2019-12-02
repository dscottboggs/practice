#include <time.h>
#include <string>
#include <iostream>

const int TIME_MAX_LEN = 12;
const char f12hr[TIME_MAX_LEN] = {
    '%', 'I', ':', '%', 'M', ':', '%', 'S', '%', 'p'
};
const char f24hr[TIME_MAX_LEN] = {'%', 'H', ':', '%', 'M', ':', '%', 'S'};

bool to24(const char t[], tm* out){
    if (*strptime(t, f24hr, out) == '\0') {
        return true;
    }
    std::cout << "There was a problem parsing " << t << '.' << '\n';
    return false;
}

bool to12(const char t[], tm* out){
    if (*strptime(t, f12hr, out) == '\0') {
        return true;
    }
    std::cout << "There was a problem parsing " << t << '.' << '\n';
    return false;
}

bool from12(tm* timein, char out[]){
    if( !timein || strftime(out, TIME_MAX_LEN, f12hr, timein) == 0){
        std::cerr << "strftime returned 0!" << '\n';
        return false;
    }
    return true;
}

bool from24(tm* timein, char out[]){
    if( !timein || strftime(out, TIME_MAX_LEN, f24hr, timein) == 0){
        std::cerr << "Strftime returned 0!" << '\n';
        return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    // declarations
    char input[TIME_MAX_LEN];
    tm* t;
    char out[TIME_MAX_LEN];
    // get input
    std::cout << "Input a time in 12 hour format: " << '\n';
    std::cin >> input;
    // do conversion
    if (to12(input, t)){
        if(from24(t, out)){
            std::cout << "Time in 24 hour format: "
                      << out
                      << '\n';
        } else {
            return 2;
        }
    } else{
        return 1;
    }
    return 0;
}
