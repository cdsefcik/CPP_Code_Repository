
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <bitset> 
using namespace std;


int main() {

std:bitset<8> mybitset{0b0000'0101}; //8 bits is room for 8 flags.

    std::cout << "All the bits 1st " << mybitset << endl;

    mybitset.set(3);
    mybitset.flip(4);
    std::cout << "All the bits 2nd " << mybitset << endl;
    mybitset.reset(4);
    std::cout << "All the bits 3rd " << mybitset << endl;
    std::cout << "All the bits 3rd " << mybitset.test(5) << endl;

    [[maybe_unused]] constexpr int  isHungry{ 0 };
    [[maybe_unused]] constexpr int  isSad{ 1 };
    [[maybe_unused]] constexpr int  isMad{ 2 };
    [[maybe_unused]] constexpr int  isHappy{ 3 };
    [[maybe_unused]] constexpr int  isLaughing{ 4 };
    [[maybe_unused]] constexpr int  isAsleep{ 5 };
    [[maybe_unused]] constexpr int  isDead{ 6 };
    [[maybe_unused]] constexpr int  isCrying{ 7 };

    std::bitset<8> me{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    me.set(isHappy);      // set bit position 3 to 1 (now we have 0000 1101)
    me.flip(isLaughing);  // flip bit 4 (now we have 0001 1101)
    me.reset(isLaughing); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(isHappy) << '\n';
    std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

    std::bitset<8> bits{ 0b0000'1101 };
    std::cout << bits.size() << " bits are in the bitset\n";
    std::cout << bits.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << bits.all() << '\n';
    std::cout << "Some bits are true: " << bits.any() << '\n';
    std::cout << "No bits are true: " << bits.none() << '\n';

    std::bitset<4> x{ 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

    std::bitset<4> b4{ 0b100 }; // b4 is 0100
    std::bitset<8> b8{ 0b100 }; // b8 is 0000 0100

    std::cout << "Initial values:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << "\n\n";

    b4 = ~b4; // flip b4 to 1011
    b8 = ~b8; // flip b8 to 1111 1011

    std::cout << "After bitwise NOT:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';

    std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';

    std::cout << (std::bitset<4>{ 0b0111 } | std::bitset<4>{ 0b0011 } | std::bitset<4>{ 0b0001 }) << '\n';

    std::cout << (std::bitset<4>{ 0b0001 } &std::bitset<4>{ 0b0011 } &std::bitset<4>{ 0b0111 }) << '\n';

    std::bitset<4> bits1{ 0b0100 };
    bits1 >>= 1;
    std::cout << bits1 << '\n';

    std::uint8_t c{ 0b00001111 };

    std::cout << std::bitset<32>(static_cast<std::uint8_t>(~c)) << '\n';     // correct: prints 00000000000000000000000011110000
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(c << 6)) << '\n'; // correct: prints 0000000000000000000011000000
    std::uint8_t cneg{ static_cast<std::uint8_t>(~c) };                     // compiles
    c = static_cast<std::uint8_t>(~c);                                       // no warning

    //BIT MASKS
    constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    constexpr std::uint8_t mask012{ 0x01 }; // hex for 0000 0001
    constexpr std::uint8_t mask113{ 0x02 }; // hex for 0000 0010
    constexpr std::uint8_t mask214{ 0x04 }; // hex for 0000 0100
    constexpr std::uint8_t mask315{ 0x08 }; // hex for 0000 1000
    constexpr std::uint8_t mask416{ 0x10 }; // hex for 0001 0000
    constexpr std::uint8_t mask517{ 0x20 }; // hex for 0010 0000
    constexpr std::uint8_t mask618{ 0x40 }; // hex for 0100 0000
    constexpr std::uint8_t mask719{ 0x80 }; // hex for 1000 0000

    //Can shift bits:
    constexpr std::uint8_t mask01{ 1 << 0 }; // 0000 0001
    constexpr std::uint8_t mask12{ 1 << 1 }; // 0000 0010
    constexpr std::uint8_t mask23{ 1 << 2 }; // 0000 0100
    constexpr std::uint8_t mask34{ 1 << 3 }; // 0000 1000
    constexpr std::uint8_t mask45{ 1 << 4 }; // 0001 0000
    constexpr std::uint8_t mask56{ 1 << 5 }; // 0010 0000
    constexpr std::uint8_t mask67{ 1 << 6 }; // 0100 0000
    constexpr std::uint8_t mask78{ 1 << 7 }; // 1000 0000

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");

    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time


    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");

    flags &= ~mask2; // turn off bit 2

    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");

    flags &= ~(mask4 | mask5); // turn bits 4 and 5 off at the same time

    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");

    [[maybe_unused]] constexpr std::uint8_t isHungry1{ 1 << 0 }; // 0000 0001
    [[maybe_unused]] constexpr std::uint8_t isSad1{ 1 << 1 }; // 0000 0010
    [[maybe_unused]] constexpr std::uint8_t isMad1{ 1 << 2 }; // 0000 0100
    [[maybe_unused]] constexpr std::uint8_t isHappy1{ 1 << 3 }; // 0000 1000
    [[maybe_unused]] constexpr std::uint8_t isLaughing1{ 1 << 4 }; // 0001 0000
    [[maybe_unused]] constexpr std::uint8_t isAsleep1{ 1 << 5 }; // 0010 0000
    [[maybe_unused]] constexpr std::uint8_t isDead1{ 1 << 6 }; // 0100 0000
    [[maybe_unused]] constexpr std::uint8_t isCrying1{ 1 << 7 }; // 1000 0000
    
    std::uint8_t me1{}; // all flags/options turned off to start
    me |= (isHappy1 | isLaughing1); // I am happy and laughing
    me &= ~isLaughing1; // I am no longer laughing

    // Query a few states
    // (we'll use static_cast<bool> to interpret the results as a boolean value)
    std::cout << std::boolalpha; // print true or false instead of 1 or 0
    std::cout << "I am happy? " << static_cast<bool>(me1 & isHappy1) << '\n';
    std::cout << "I am laughing? " << static_cast<bool>(me1 & isLaughing1) << '\n';


    //RGB PROGRAM:
    constexpr std::uint32_t redBits{ 0xFF000000 };
    constexpr std::uint32_t greenBits{ 0x00FF0000 };
    constexpr std::uint32_t blueBits{ 0x0000FF00 };
    constexpr std::uint32_t alphaBits{ 0x000000FF };

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use Bitwise AND to isolate the pixels for our given color,
    // then right shift the value into the lower 8 bits
    const std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
    const std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
    const std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
    const std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

    std::cout << "Your color contains:\n";
    std::cout << std::hex; // print the following values in hex

    // reminder: std::uint8_t will likely print as a char
    // we static_cast to int to ensure it prints as an integer
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";

    return 0;
}




