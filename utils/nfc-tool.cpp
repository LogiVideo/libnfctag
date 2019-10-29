#include <SmeNfc.h>
#include <cstring>
#include <iostream>
#include <cstdio>

void
usage(const char *prog)
{
        std::cerr << "Usage: " << prog << " getuid\n";
        std::cerr << "OR:    " << prog << " set <uri>\n";
        exit(1);
}

int
main(int argc, char *const argv[])
{
        uint8_t buffer[16];

        if (argc < 2 || argc > 3) {
                usage(argv[0]);
        }
        if (std::strcmp(argv[1], "getuid") == 0) {
                smeNfcDriver.readUID(buffer);
                for (int i = 0; i < 7; i++) {
                        std::printf("%02x", buffer[i]);
                }
                std::printf("\n");
        } else if (std::strcmp(argv[1], "set") == 0 && argc == 3) {
                smeNfc.storeUri(NDEFFirstPos, argv[2]);
        } else {
                usage(argv[0]);
        }
        return 0;
}

