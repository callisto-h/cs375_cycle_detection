Hello!

build the executable with `make`.

All tests are generated at runtime by the `do_tests()` function.
It accepts:

A size argument, to determine the linked list size to build
A string argument, to determine which of the algorithms to run
A bool argument, to determine if there is a cycle or not
An index argument, to determine where the cycle connects.

It outputs to std out, so feel free to pipe to a file.

Do not run the linear (with map) function on a list of size greater
than 10 million nodes!

:)