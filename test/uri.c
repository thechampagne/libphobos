#include <stdio.h>
#include <phobos/uri/uri.h>

int main()
{
 uri_t* uri = uri_encode("foo bar");
 if (uri->error != NULL)
 {
     printf("Something went wrong: %s", uri->error);
     uri_clean(uri);
     return 1;
 }
 printf("%s", uri->buffer);
 uri_clean(uri);
 return 0;
}