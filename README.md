`uuidgen` for OpenBSD
=====================
Generates a single UUIDv4.  Really just a simple wrapper around 
[`uuid_create(3)`](https://man.openbsd.org/uuid_create#uuid_create) and
[`uuid_to_string(3)`](https://man.openbsd.org/uuid_create#uuid_to_string).

Quickstart
----------
1.  Grab this source.
    ```sh
    git clone https://github.com/magisterquis/uuidgen-openbsd.git && cd uuidgen-openbsd
    ```
2.  Build it.
    ```sh
    make
    ```
3.  Generate a UUID.
    ```sh
    ./uuidgen
    ```
