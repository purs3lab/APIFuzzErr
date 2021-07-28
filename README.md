# APIFuzzErr
Fuzzing for improper API error handle detection

Our high-level idea is to find improper error handling bugs using dynamic analysis (i.e., Fuzzing).
An error-handling bug occurs when a program fails to handle all possible errors of external functions (i.e., library functions).

For example:

> char *l = getenv("PATH");
strcat(buf, l);

In the above case, we should check the return value of `getenv` because it can return NULL.

Why not use static analysis:
Obvious reasons: False positives, function pointers, etc.

### Our approach:

Phase 1: Instrumenting external library.
First, given a library X, for each function, find its error handling cases.
Second, use compile-time instrumentation to instrument X to drive the execution of each function to its error handling case on demand.
This will give us X_1.

Phase 2: Fuzz the target program.
Given a program P that uses X, fuzz P by using X_1 instead of X.
While fuzzing, make certain functions in X_1 return error or go to error handling case.
Now see how P behaves. Ideally, P should not crash. If it crashes, then we know that P is not using a function in X properly.

Considering the above case, our instrumentation to libc will make `getenv` return NULL, making the program do NULL ptr dereference and hence crash.

### Closely related Work:

[https://www.usenix.org/system/files/sec20-jiang.pdf](https://www.usenix.org/system/files/sec20-jiang.pdf)
