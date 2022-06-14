/*
 * Copyright (c) 2022 XXIV
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __PHOBOS_MATH_REMAINDER_H__
#define __PHOBOS_MATH_REMAINDER_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculates the remainder from the calculation x/y. 
 * 
 * Special Values
 * |-------------------------------------------|
 *      x           y     fmod(x, y)  invalid?
 * |----------|----------|----------|----------|
 *     ±0.0      not 0.0     ±0.0        no
 * |----------|----------|----------|----------|
 *      ±∞      anything      NAN        yes
 * |----------|----------|----------|----------|
 *   anything     ±0.0        NAN        yes
 * |----------|----------|----------|----------|
 *     !=±∞        ±∞          x         no
 * |----------|----------|----------|----------|
 *
 * Example:
 * * *
 * int main()
 * {
 *  printf("%Lf", math_remainder_fmod(0.0, 1.0));
 *  return 0;
 * }
 * * *
 *
 * @param x
 * @param y
 * @return The value of x - i * y, where i is the number of times that y
 * can be completely subtracted from x. The result has the same sign as x.
 */
extern long double math_remainder_fmod(long double x, long double y);

/**
 * Breaks x into an integral part and a fractional part,
 * each of which has the same sign as x.
 * The integral part is stored in i. 
 * 
 * Special Values
 * |---------------------------------------------------|
 *       x 	     i(on input)  modf(x, i)  i(on return)
 * |------------|------------|------------|------------|
 *       ±∞        anything 	  ±0.0 	        ±∞
 * |------------|------------|------------|------------|
 *
 * Example:
 * * *
 * int main()
 * {
 *  long double intpart;
 *  printf("%Lf\n", math_remainder_modf(3.14159, &intpart));
 *  printf("%Lf", intpart);
 *  return 0;
 * }
 * * *
 *
 * @param x
 * @param i
 * @return The fractional part of x.
 */
extern long double math_remainder_modf(long double x, long double* i);

/**
 * Calculate the remainder x REM y, following IEC 60559.
 * 
 * REM is the value of x - y * n, where n is the integer nearest the exact value of x / y.
 * If |n - x / y| == 0.5, n is even. If the result is zero, it has the same sign as x.
 * Otherwise, the sign of the result is the sign of x / y.
 * Precision mode has no effect on the remainder functions.
 * 
 * remquo returns n in the parameter n. 
 * 
 * Special Values
 * |-------------------------------------------------------------------------------|
 *         x               y        remainder(x, y)       n             invalid?
 * |---------------|---------------|---------------|---------------|---------------|
 *       ±0.0 	        not 0.0 	     ±0.0 	         0.0 	          no
 * |---------------|---------------|---------------|---------------|---------------|
 *        ±∞ 	        anything 	     -NAN 	          ? 	          yes
 * |---------------|---------------|---------------|---------------|---------------|
 *      anything 	      ±0.0 	          ±NAN 	          ? 	          yes
 * |---------------|---------------|---------------|---------------|---------------|
 *       != ±∞ 	           ±∞ 	            x 	          ? 	          no
 * |---------------|---------------|---------------|---------------|---------------|
 *
 * Example:
 * * *
 * int main()
 * {
 *  printf("%Lf", math_remainder(5.1, 3.0));
 *  return 0;
 * }
 * * *
 *
 * @param x
 * @param y
 * @return long double
 */
extern long double math_remainder(long double x, long double y);

/**
 * Calculate the remainder x REM y, following IEC 60559.
 * 
 * REM is the value of x - y * n, where n is the integer nearest the exact value of x / y.
 * If |n - x / y| == 0.5, n is even. If the result is zero, it has the same sign as x.
 * Otherwise, the sign of the result is the sign of x / y.
 * Precision mode has no effect on the remainder functions.
 * 
 * remquo returns n in the parameter n. 
 * 
 * Special Values
 * |-------------------------------------------------------------------------------|
 *         x               y        remainder(x, y)       n             invalid?
 * |---------------|---------------|---------------|---------------|---------------|
 *       ±0.0 	        not 0.0 	     ±0.0 	         0.0 	          no
 * |---------------|---------------|---------------|---------------|---------------|
 *        ±∞ 	        anything 	     -NAN 	          ? 	          yes
 * |---------------|---------------|---------------|---------------|---------------|
 *      anything 	      ±0.0 	          ±NAN 	          ? 	          yes
 * |---------------|---------------|---------------|---------------|---------------|
 *       != ±∞ 	           ±∞ 	            x 	          ? 	          no
 * |---------------|---------------|---------------|---------------|---------------|
 *
 * Example:
 * * *
 * int main()
 * {
 *  int n;
 *  printf("%Lf\n", math_remainder_remquo(5.1, 3.0, &n));
 *  printf("%d", n);
 *  return 0;
 * }
 * * *
 *
 * @param x
 * @param y
 * @param n
 * @return long double
 */
extern long double math_remainder_remquo(long double x, long double y, int* n);

#ifdef __cplusplus
}
#endif

#endif // __PHOBOS_MATH_REMAINDER_H__