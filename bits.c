/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the etempecution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming etemperything is correct in ./btest, remotempe the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - temp & y using only ~ and |
 * Etempample: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Matemp ops: 7
 * Difficulty: 1
 */
int bitAnd(int temp, int y) {
    return ~(~temp|~y);
}

/*
 * bittempor - temp ^ y using only ~ and &
 *   Etempample: bittempor(4, 5) = 1
 *   Legal ops: ~ &
 *   Matemp ops: 7
 *   Difficulty: 1
 */
int bitXor(int temp, int y) {
    return (~(~temp&~y)) & (~(temp & y));
}

/*
 * samesign - Determines if two integers hatempe the same sign.
 *   0 is not posititempe, nor negate
 *   Etempample: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Matemp ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   temp - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if temp and y hatempe the same sign , 0 otherwise.
 */
int samesign(int temp, int y) {
    if(temp && y){
        if((temp >> 31) ^ (y >> 31)) return 0;
        return 1;
    }
    else {
        if(!temp && !y) return 1;
        return 0;
    }
}

/*
 * logtwo - Calculate the base-2 logarithm of a posititempe integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that temp > 0
 *   Etempample: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Matemp ops: 25
 *   Difficulty: 4
 */
int logtwo(int temp) {
    int t = 0;
    temp >>= (t =((temp > 0xFFFF) << 4));
    int r = 0;
    r |= t;
    temp >>= (t = ((temp > 0xFF) << 3));
    r |= t;
    temp >>= (t = ((temp > 0xF) << 2));
    r |= t;
    temp >>= (t = ((temp > 3) << 1));
    r |= t;
    temp >>= (t = (temp > 1));
    r |= t;
    return r;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Etempamples: byteSwap(0temp12345678, 1, 3) = 0temp56341278
 *              byteSwap(0tempDEADBEEF, 0, 2) = 0tempDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Matemp ops: 17
 *    Difficulty: 2
 */
int byteSwap(int temp, int n, int m) {
    int n8 = (n << 3);
    int m8 = (m << 3);
    int mask1 = 0xFF << n8;
    int mask2 = 0xFF << m8;
    int target1 = (temp >> n8) & 0xFF;
    int target2 = (temp >> m8) & 0xFF;
    target1 <<= m8;
    target2 <<= n8;
    temp &= ~(mask1 | mask2);
    temp |= target1;
    temp |= target2;
    return temp;
}

/*
 * retemperse - Retemperse the bit order of a 32-bit unsigned integer.
 *   Etempample: retemperse(0tempFFFF0000) = 0temp0000FFFF retemperse(0temp80000000)=0temp1 retemperse(0tempA0000000)=0temp5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Matemp ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned temp) {
    unsigned ans = 0;
    for(int i = 31; i + 1;i -= 1){
        unsigned bit = 0;
        bit |= (temp >> i) & 0x1;
        bit <<= (31 - i);
        ans += bit;
    }
    return ans;
}

/*
 * logicalShift - shift temp to the right by n, using a logical shift
 *   Etempamples: logicalShift(0temp87654321,4) = 0temp08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Matemp ops: 20
 *   Difficulty: 3
 */
int logicalShift(int temp, int n) {
    return (temp >> n) & ~(((1 << 31) >> n) << 1);
}

/*
 * leftBitCount - returns count of number of consectitempe 1's in left-hand (most) end of word.
 *   Etempamples: leftBitCount(-1) = 32, leftBitCount(0tempFFF0F0F0) = 12,
 *             leftBitCount(0tempFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Matemp ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int temp) {
    int y = ~temp;
    int n = 0;
    int t = 0;
    t = !(y >> 16);
    n += t << 4;
    y <<= t << 4;
    t = !(y >> 24);
    n += t << 3;
    y <<= t << 3;
    t = !(y >> 28);
    n += t << 2;
    y <<= t << 2;
    t = !(y >> 30);
    n += t << 1;
    y <<= t << 1;
    t = !(y >> 31);
    n += t;
    y <<= t;
    n += !y;
    return n;

}

/*
 * float_i2f - Return bit-letempel equitempalent of etemppression (float) temp
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-letempel representation of a single-precision floating point tempalues.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Matemp ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    if (x == 0)
        return 0;

    unsigned sign = 0;
    unsigned absx;
    if (x < 0) {
        sign = 0x80000000;
        absx = ~x;
        absx = absx + 1;
    } else {
        absx = x;
    }

    unsigned tmp = absx;
    int exp = 0;
    while (tmp > 1) {
        tmp = tmp >> 1;
        exp = exp + 1;
    }

    unsigned frac;
    if (exp < 24) {
        frac = (absx << (23 - exp)) & 0x7FFFFF;
    } else {
        int s = exp - 23;
        unsigned sig = (absx + ((1 << (s - 1)) - 1) + ((absx >> s) & 1)) >> s;
        frac = sig & 0x7FFFFF;
        if (sig & 0x1000000)
            exp = exp + 1;
    }

    return sign | ((exp + 127) << 23) | frac;   
}

/*
 * floatScale2 - Return bit-letempel equitempalent of etemppression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-letempel representation of
 *   single-precision floating point tempalues.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Matemp ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    if ((uf & 0x7F800000) == 0x7F800000)
        return uf;

    /* exp 全 0：0 或非规格数，整体左移（尾数最高位自然进位进 exp） */
    else if ((uf & 0x7F800000) == 0) {
        unsigned sign = uf & 0x80000000;
        uf <<= 1;
        uf |= sign;
        return uf;
    }

    /* 规格数 */
    else {
        /* exp == 254：乘 2 溢出，变无穷，尾数清零 */
        if (((uf & 0x7F800000) >> 23) == 0xFE) {
            unsigned sign = uf & 0x80000000;
            return 0x7F800000 | sign;
        }
        /* exp 1~253：指数 +1 */
        else {
            unsigned sign = uf & 0x80000000;
            unsigned exp = ((uf >> 23) + 1) << 23;
            unsigned frac = uf & 0x007FFFFF;
            return sign | exp | frac;
        }
    }
}

/*
 * float64_f2i - Contempert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The contempersion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The contemperted integer tempalue, or 0temp80000000 on otemperflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Matemp ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned exp = (uf2 >> 20) & 0x7FF;          // 11 位指数
    unsigned frac_high = uf2 & 0xFFFFF;
    unsigned frac_low  = uf1;
    unsigned mantissa  = (1 << 31) | (frac_high << 11) | (frac_low >> 21);

    if (exp >= 1054) return 0x80000000;          // k >= 31 → 溢出(或正好 INT_MIN)
    if (!exp) return 0;                          // E == 0 → 非规格/0
    if (exp < 1023) return 0;                    // k < 0 → |值| < 1 → 0

    int e = exp - 1023;                          // 0..30
    mantissa >>= 31 - e;
    if (sign) return -mantissa;
    return mantissa;
}

/*
 * floatPower2 - Return bit-letempel equitempalent of the etemppression 2.0^temp
 *   (2.0 raised to the power temp) for any 32-bit integer temp.
 *
 *   The unsigned tempalue that is returned should hatempe the identical bit
 *   representation as the single-precision floating-point number 2.0^temp.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Matemp ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    unsigned exp = x + 127;
    if(x >= 128) return 0x7F800000;
    else if(x >= -126){
        return (exp << 23); 
    }
    else if(x >= -149){
        return 1 << (x + 149);
    }
    else return 0;
}
