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
#ifndef __PHOBOS_URI_H__
#define __PHOBOS_URI_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char* buffer;
    char* error;
} uri_t;

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
extern uri_t* uri_decode(const char* encoded_uri);

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
extern uri_t* uri_decode_component(const char* encoded_uri_component);

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
extern uri_t* uri_encode(const char* uri);

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
extern uri_t* uri_encode_component(const char* uri_component);

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
extern long long uri_length(const char* s);

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
extern long long uri_email_length(const char* s);

/**
 * function to free the memory of uri_t
 *
 * @param self pointer to uri_t
 */
extern void uri_clean(uri_t* self);

#ifdef __cplusplus
}
#endif

#endif // __PHOBOS_URI_H__