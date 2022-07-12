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
import core.stdc.stdlib;
import core.stdc.string;

struct uri_t {
    char* buffer;
    char* error;
}

/**
 * Decodes the URI string encodedURI into a UTF-8 string and returns it. 
 * Escape sequences that resolve to reserved URI characters are not replaced. 
 * Escape sequences that resolve to the '#' character are not replaced.
 *
 * Example:
 * * *
 * int main()
 * {
 *  uri_t* uri = uri_decode("foo%20bar");
 *  if (uri->error != NULL)
 *  {
 *      printf("Something went wrong: %s", uri->error);
 *      uri_clean(uri);
 *      return 1;
 *  }
 *  printf("%s", uri->buffer);
 *  uri_clean(uri);
 *  return 0;
 * }
 * * *
 *
 * @param encoded_uri
 * @return pointer to uri_t
 */
extern (C) uri_t* uri_decode(const char* encoded_uri)
{
    uri_t* self = cast(uri_t*) malloc(uri_t.sizeof);
    if (self == null)
    {
        return null;
    }
    try
    {
        auto re = std.uri.decode(encoded_uri.fromStringz);
        char* buf = cast(char*) malloc(char.sizeof * re.length + 1);
        if (buf == null)
        {
            free(self);
            return null;
        }
        strcpy(buf, re.toStringz);
        self.buffer = buf;
        self.error = null;
        return self;
    }
    catch (std.uri.URIException ex)
    {
        char* err = cast(char*) malloc(char.sizeof * ex.msg.length + 1);
        if (err == null)
        {
            free(self);
            return null;
        }
        strcpy(err, ex.msg.toStringz);
        self.buffer = null;
        self.error = err;
        return self;
    }
}

/**
 * Decodes the URI string encodedURI into a UTF-8 string and returns it.
 * All escape sequences are decoded.
 *
 * Example:
 * * *
 * int main()
 * {
 *  uri_t* uri = uri_decode_component("foo%2F%26");
 *  if (uri->error != NULL)
 *  {
 *      printf("Something went wrong: %s", uri->error);
 *      uri_clean(uri);
 *      return 1;
 *  }
 *  printf("%s", uri->buffer);
 *  uri_clean(uri);
 *  return 0;
 * }
 * * *
 *
 * @param encoded_uri_component
 * @return pointer to uri_t
 */
extern (C) uri_t* uri_decode_component(const char* encoded_uri_component)
{
    uri_t* self = cast(uri_t*) malloc(uri_t.sizeof);
    if (self == null)
    {
        return null;
    }
    try
    {
        auto re = std.uri.decodeComponent(encoded_uri_component.fromStringz);
        char* buf = cast(char*) malloc(char.sizeof * re.length + 1);
        if (buf == null)
        {
            free(self);
            return null;
        }
        strcpy(buf, re.toStringz);
        self.buffer = buf;
        self.error = null;
        return self;
    }
    catch (std.uri.URIException ex)
    {
        char* err = cast(char*) malloc(char.sizeof * ex.msg.length + 1);
        if (err == null)
        {
            free(self);
            return null;
        }
        strcpy(err, ex.msg.toStringz);
        self.buffer = null;
        self.error = err;
        return self;
    }
}

/**
 * Encodes the UTF-8 string uri into a URI and returns that URI.
 * Any character not a valid URI character is escaped.
 * The '#' character is not escaped.
 *
 * Example:
 * * *
 * int main()
 * {
 *  uri_t* uri = uri_encode("foo bar");
 *  if (uri->error != NULL)
 *  {
 *      printf("Something went wrong: %s", uri->error);
 *      uri_clean(uri);
 *      return 1;
 *  }
 *  printf("%s", uri->buffer);
 *  uri_clean(uri);
 *  return 0;
 * }
 * * *
 *
 * @param uri
 * @return pointer to uri_t
 */
extern (C) uri_t* uri_encode(const char* uri)
{
    uri_t* self = cast(uri_t*) malloc(uri_t.sizeof);
    if (self == null)
    {
        return null;
    }
    try
    {
        auto re = std.uri.encode(uri.fromStringz);
        char* buf = cast(char*) malloc(char.sizeof * re.length + 1);
        if (buf == null)
        {
            free(self);
            return null;
        }
        strcpy(buf, re.toStringz);
        self.buffer = buf;
        self.error = null;
        return self;
    }
    catch (std.uri.URIException ex)
    {
        char* err = cast(char*) malloc(char.sizeof * ex.msg.length + 1);
        if (err == null)
        {
            free(self);
            return null;
        }
        strcpy(err, ex.msg.toStringz);
        self.buffer = null;
        self.error = err;
        return self;
    }
}

/**
 * Encodes the UTF-8 string uriComponent into a URI and returns that URI.
 * Any character not a letter, digit, or one of -.!~*'() is escaped.
 *
 * Example:
 * * *
 * int main()
 * {
 *  uri_t* uri = uri_encode_component("!@#$%^&*(");
 *  if (uri->error != NULL)
 *  {
 *      printf("Something went wrong: %s", uri->error);
 *      uri_clean(uri);
 *      return 1;
 *  }
 *  printf("%s", uri->buffer);
 *  uri_clean(uri);
 *  return 0;
 * }
 * * *
 *
 * @param uri_component
 * @return pointer to uri_t
 */
extern (C) uri_t* uri_encode_component(const char* uri_component)
{
    uri_t* self = cast(uri_t*) malloc(uri_t.sizeof);
    if (self == null)
    {
        return null;
    }
    try
    {
        auto re = std.uri.encodeComponent(uri_component.fromStringz);
        char* buf = cast(char*) malloc(char.sizeof * re.length + 1);
        if (buf == null)
        {
            free(self);
            return null;
        }
        strcpy(buf, re.toStringz);
        self.buffer = buf;
        self.error = null;
        return self;
    }
    catch (std.uri.URIException ex)
    {
        char* err = cast(char*) malloc(char.sizeof * ex.msg.length + 1);
        if (err == null)
        {
            free(self);
            return null;
        }
        strcpy(err, ex.msg.toStringz);
        self.buffer = null;
        self.error = err;
        return self;
    }
}

/**
 * Does string s start with a URL?
 *
 * Example:
 * * *
 * int main()
 * {
 *  printf("%lld", uri_length("http://www.digitalmars.com/~fred/fredsRX.html#foo end!"));
 *  return 0;
 * }
 * * *
 *
 * @param s
 * @return -1 it does not len it does, and s[0 .. len] is the slice of s that is that URL
 */
extern (C) long uri_length(const char* s)
{
    return std.uri.uriLength(s.fromStringz);
}

/**
 * Does string s start with an email address?
 *
 * Example:
 * * *
 * int main()
 * {
 *  printf("%lld", uri_email_length("my.e-mail@www.example-domain.com with garbage added"));
 *  return 0;
 * }
 * * *
 *
 * @param s
 * @return -1 it does not len it does, and s[0 .. i] is the slice of s that is that email address
 */
extern (C) long uri_email_length(const char* s)
{
    return std.uri.emailLength(s.fromStringz);
}

/**
 * function to free the memory of uri_t
 *
 * @param self pointer to uri_t
 */
extern (C) void uri_clean(uri_t* self)
{
    if (self != null)
    {
        if (self.buffer != null)
        {
            free(self.buffer);
        }
        if (self.error != null)
        {
            free(self.error);
        }
        free(self);
    }
}