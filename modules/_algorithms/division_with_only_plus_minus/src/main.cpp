#include <iostream>
#include <cstring>
#include <algorithm>

void division_with_only_plus_minus(int a = 10, int b = 3) {
    int i = 0;
    while (true) {
        a -= b;
        if (a < 0) {
            a += b;
            break;
        }
        i++;
    }

    while (a != 0 && (a - b) < 0) {
        a += 10;
    }

    int y = 0;
    while (a != 0) {
        a -= b;
        if (a < 0) {
            a += b;
            break;
        }
        y++;
    }
    std::cout << i << "." << y << std::endl;
}

int main(int argc, char* argv[]) {
	division_with_only_plus_minus();
	return EXIT_SUCCESS;
}