#include <iostream>


int main() {
    const char alphabet[] = "0123456789ABCDEFGHJKMNPQRSTVWXYZ";
    unsigned char a[5] = {'H', 'e', 'l', 'l', 'o'};
    unsigned char b[8];
    b[0] = ((a[0] >> 3) & 0xFF);
    b[1] = ((((a[0] & 7) << 2) & 0xFF) | ((a[1] >> 6) & 0xFF));
    b[2] = (((a[1] & 62) >> 1) & 0xFF);
    b[3] = (((a[1] & 1) << 4) & 0xFF) | ((a[2] >> 4) & 0xFF);
    b[4] = (((a[2] & 15) << 1) & 0xFF) | ((a[3] >> 7) & 0xFF);
    b[5] = (((a[3] & 124) >> 2) & 0xFF);
    b[6] = (((a[3] & 3) << 3) & 0xFF) | (((a[4] & 224) >> 5) & 0xFF);
    b[7] = (a[4] & 31);
    for (int i = 0; i < 8; ++i) {
        std::cout << alphabet[b[i]] << '\n';
    }
    return 0;
}