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
import std;
import std.string;
import std.conv;
import core.stdc.stdlib;
import core.stdc.string;

/**
 * Demangle D mangled names.
 *
 * Example:
 * * *
 * int main()
 * {
 *  char* s = demangle("_D1a1bi");
 *  printf("%s", s);
 *  free(s);
 *  return 0;
 * }
 * * *
 *
 * @param name the mangled name
 * @return A string. If it is not a D mangled name, it returns its argument name.
 */
extern (C) char* demangle(const char* name)
{
	auto re = std.demangle.demangle(to!string(name));
	char* buf = cast(char*) malloc((re.length + 1) * char.sizeof);
	if (buf == null)
	{
		return null;
	}
	strcpy(buf, re.toStringz);
	return buf;
}
