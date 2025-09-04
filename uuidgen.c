/*
 * uuidgen.c
 * Generate a UUID
 * By J. Stuart McMurray
 * Created 20250804
 * Last Modified 20250804
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <uuid.h>

/* chkerr prints a message and terminates the program if status isn't
 * uuid_s_ok.  fname is the name of the function which set the status. */
void
chkerr(const char *fname, uint32_t status)
{
#define ERRX(n, msg) errx(n, "%s: %s", fname, msg)
        switch (status) {
                case uuid_s_ok:                  return;
                case uuid_s_bad_version:         ERRX(11, "bad version");
                case uuid_s_invalid_string_uuid: ERRX(12, "bad UUID");
                case uuid_s_no_memory:           ERRX(13, "no memory");
                default: err(14, "%s: unknown error %u", fname, status);
        }
}

/* uuidgen generates a single UUID. */
int
main(void)
{
        char     *str;
        uint32_t  status;
        uuid_t    uuid;

        if (-1 == pledge("stdio", ""))
                err(10, "pledge");

        /* Generate a UUID. */
        bzero(&uuid, sizeof(uuid));
        status = 0;
        uuid_create(&uuid, &status);
        chkerr("uuid_create", status);

        /* Format it. */
        str = NULL;
        uuid_to_string(&uuid, &str, &status);
        chkerr("uuid_to_string", status);

        /* Print it. */
        printf("%s\n", str);
        free(str); str = NULL;

        return 0;
}
