#include <iostream>

using namespace std;

int main() {
    int one, two, four, eight, sixteen, thirtytwo, sixtyfour;
    
    one = sizeof(char); two = sizeof(short int); four = sizeof(int); eight = sizeof(long int); sixteen = eight+eight; thirtytwo = sixteen+sixteen; sixtyfour = thirtytwo+thirtytwo;
    
    putchar(sixtyfour + eight), putchar(sixtyfour + thirtytwo + four + one), putchar(sixtyfour + thirtytwo + eight + four), putchar(sixtyfour + thirtytwo + eight + four), putchar(sixtyfour + thirtytwo + eight + four + two + one), putchar(thirtytwo + eight + four), putchar(thirtytwo);
    putchar(sixtyfour + sixteen + four + two + one), putchar(sixtyfour + thirtytwo + eight + four + two + one), putchar(sixtyfour + thirtytwo + sixteen + two), putchar(sixtyfour + thirtytwo + eight + four), putchar(sixtyfour + thirtytwo + four), putchar(thirtytwo + one);
}