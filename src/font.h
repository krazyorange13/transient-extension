#ifndef TRANSIENT_EXTENSION_FONT_H
#define TRANSIENT_EXTENSION_FONT_H

#include <stdint.h>

/*
 * I made this font. Check it out at https://fontstruct.com/fontstructions/show/2582143/fivebyfive-8
 * Licensed under FontStruct Non-Commercial License.
 */

#define FONT_WIDTH 5
#define FONT_HEIGHT 5
#define FONT_GLYPH_COUNT 95

#define FONT_CTOG_I(x) ((uint8_t) x - 32)

typedef uint32_t glyph_t;

static glyph_t FONT_GLYPHS[FONT_GLYPH_COUNT] = {
    0b0000000000000000000000000, // U+20 // 32  // SPACE
    0b0111001110001000000000100, // U+21 // 33  // EXCLAMATION MARK
    0b0101001010000000000000000, // U+22 // 34  // QUOTATION MARK
    0b0101011111010101111101010, // U+23 // 35  // NUMBER SIGN
    0b0111010100011100010101110, // U+24 // 36  // DOLLAR SIGN
    0b1100110010001000100110011, // U+25 // 37  // PERCENT SIGN
    0b0111010000011011000101111, // U+26 // 38  // AMPERSAND
    0b0010000100000000000000000, // U+27 // 39  // APOSTROPHE
    0b0011001000010000100000110, // U+28 // 40  // LEFT PARENTHESIS
    0b0110000010000100001001100, // U+29 // 41  // RIGHT PARENTHESIS
    0b0101000100010100000000000, // U+2A // 42  // ASTERISK
    0b0000000100011100010000000, // U+2B // 43  // PLUS SIGN
    0b0000000000000000010001000, // U+2C // 44  // COMMA
    0b0000000000011100000000000, // U+2D // 45  // HYPHEN-MINUS
    0b0000000000000000000000100, // U+2E // 46  // FULL STOP
    0b0001000010001000100001000, // U+2F // 47  // SOLIDUS
    0b0011001001100011001001100, // U+30 // 48  // DIGIT ZERO
    0b0110010100001000010011111, // U+31 // 49  // DIGIT ONE
    0b0111000001011101000011111, // U+32 // 50  // DIGIT TWO
    0b0111010001001101000101110, // U+33 // 51  // DIGIT THREE
    0b0100001010100101111100010, // U+34 // 52  // DIGIT FOUR
    0b1111110000011100000111110, // U+35 // 53  // DIGIT FIVE
    0b0011001000111101000101110, // U+36 // 54  // DIGIT SIX
    0b1111100001000100010000100, // U+37 // 55  // DIGIT SEVEN
    0b0111010001011101000101110, // U+38 // 56  // DIGIT EIGHT
    0b0111010001011110001001100, // U+39 // 57  // DIGIT NINE
    0b0000000100000000000000100, // U+3A // 58  // COLON
    0b0000000100000000010001000, // U+3B // 59  // SEMICOLON
    0b0000000000001100100000110, // U+3C // 60  // LESS-THAN SIGN
    0b0000000000011100000001110, // U+3D // 61  // EQUALS SIGN
    0b0000000000011000001001100, // U+3E // 62  // GREATER-THAN SIGN
    0b0111010001001100000000100, // U+3F // 63  // QUESTION MARK
    0b0111010001101011010101101, // U+40 // 64  // COMMERCIAL AT
    0b0010001010010101111110001, // U+41 // 65  // LATIN CAPITAL LETTER A 
    0b0110010010111101000111110, // U+42 // 66  // LATIN CAPITAL LETTER B
    0b0011101000100001000001111, // U+43 // 67  // LATIN CAPITAL LETTER C
    0b1110010010100011000111110, // U+44 // 68  // LATIN CAPITAL LETTER D
    0b1111110000011101000011111, // U+45 // 69  // LATIN CAPITAL LETTER E
    0b0111110000111101000010000, // U+46 // 70  // LATIN CAPITAL LETTER F
    0b0011001000100111000101111, // U+47 // 71  // LATIN CAPITAL LETTER G
    0b1100101001011110100111011, // U+48 // 72  // LATIN CAPITAL LETTER H
    0b0111110100001000010111110, // U+49 // 73  // LATIN CAPITAL LETTER I
    0b0111100010000101001001100, // U+4A // 74  // LATIN CAPITAL LETTER J
    0b1001010100111001001010001, // U+4B // 75  // LATIN CAPITAL LETTER K
    0b1100001000010000100101111, // U+4C // 76  // LATIN CAPITAL LETTER L
    0b1100111111101011000110001, // U+4D // 77  // LATIN CAPITAL LETTER M
    0b1000111001101011001110001, // U+4E // 78  // LATIN CAPITAL LETTER N
    0b0111010001100011000101110, // U+4F // 79  // LATIN CAPITAL LETTER O
    0b1111010001100011111010000, // U+50 // 80  // LATIN CAPITAL LETTER P
    0b0111010001101011001001101, // U+51 // 81  // LATIN CAPITAL LETTER Q
    0b1111010001100101110010011, // U+52 // 82  // LATIN CAPITAL LETTER R
    0b0111010000011100000101110, // U+53 // 83  // LATIN CAPITAL LETTER S
    0b1111100100001000010000100, // U+54 // 84  // LATIN CAPITAL LETTER T
    0b1000110001100011001001100, // U+55 // 85  // LATIN CAPITAL LETTER U
    0b1000110001010100101000100, // U+56 // 86  // LATIN CAPITAL LETTER V
    0b1000110001101011010101010, // U+57 // 87  // LATIN CAPITAL LETTER W
    0b0110110110001000110110110, // U+58 // 88  // LATIN CAPITAL LETTER X
    0b1000101010001000010000100, // U+59 // 89  // LATIN CAPITAL LETTER Y
    0b1111100010001000100011111, // U+5A // 90  // LATIN CAPITAL LETTER Z
    0b0111001000010000100001110, // U+5B // 91  // LEFT SQUARE BRACKET
    0b0100001000001000001000010, // U+5C // 92  // REVERSE SOLIDUS
    0b0111000010000100001001110, // U+5D // 93  // RIGHT SQUARE BRACKET
    0b0010001010000000000000000, // U+5E // 94  // CIRCUMFLEX ACCENT
    0b0000000000000000000011111, // U+5F // 95  // LOW LINE
    0b0010000010000000000000000, // U+60 // 96  // GRAVE ACCENT
    0b0000001100000101011001011, // U+61 // 97  // LATIN SMALL LETTER A
    0b1100001010011010100101110, // U+62 // 98  // LATIN SMALL LETTER B
    0b0000000111010001000001111, // U+63 // 99  // LATIN SMALL LETTER C
    0b0001001110100101001001111, // U+64 // 100 // LATIN SMALL LETTER D
    0b0000001100100101010001111, // U+65 // 101 // LATIN SMALL LETTER E
    0b0001100100011110010011000, // U+66 // 102 // LATIN SMALL LETTER F
    0b0000001110110010000100110, // U+67 // 103 // LATIN SMALL LETTER G
    0b1000010100110101001010011, // U+68 // 104 // LATIN SMALL LETTER H
    0b0010000000011001010100110, // U+69 // 105 // LATIN SMALL LETTER I
    0b0001000000001111001001100, // U+6A // 106 // LATIN SMALL LETTER J
    0b1000010010101001110010011, // U+6B // 107 // LATIN SMALL LETTER K
    0b0110010100001000010100110, // U+6C // 108 // LATIN SMALL LETTER L
    0b0000011110101011010110101, // U+6D // 109 // LATIN SMALL LETTER M
    0b0000010100110101001010011, // U+6E // 110 // LATIN SMALL LETTER N
    0b0000001110100011000101110, // U+6F // 111 // LATIN SMALL LETTER O
    0b0000000110010010101011000, // U+70 // 112 // LATIN SMALL LETTER P
    0b0000001100100100111000011, // U+71 // 113 // LATIN SMALL LETTER Q
    0b0000011010011010100011000, // U+72 // 114 // LATIN SMALL LETTER R
    0b0000000100010100000111110, // U+73 // 115 // LATIN SMALL LETTER S
    0b0010001111101000010000011, // U+74 // 116 // LATIN SMALL LETTER T
    0b0000010010100101011001011, // U+75 // 117 // LATIN SMALL LETTER U
    0b0000010001010010101000100, // U+76 // 118 // LATIN SMALL LETTER V
    0b0000010101101011010111010, // U+77 // 119 // LATIN SMALL LETTER W
    0b0000011010001000101010011, // U+78 // 120 // LATIN SMALL LETTER X
    0b0000010010011010000100110, // U+79 // 121 // LATIN SMALL LETTER Y
    0b0000011110001000100111110, // U+7A // 122 // LATIN SMALL LETTER Z
    0b0011000100010000010000110, // U+7B // 123 // LEFT CURLY BRACKET
    0b0010000100001000010000100, // U+7C // 124 // VERTICAL LINE
    0b0110000100000100010001100, // U+7D // 125 // RIGHT CURLY BRACKET
    0b0000001000101010001000000, // U+7E // 126 // TILDE
};

#endif
