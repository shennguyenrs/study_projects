# catwc
> My combine command from cat and wc
## SYNOPSIS
catwc [OPTION]... [FILE(S)]...
## DESCRIPTION
Concatenate FILE(s) and count words, lines.
Two features can be processed in concurrent by using fork and threads.

```
-h, --help      display help menu

-c, --count-only
                display count words and line only.

-f, --fork      using fork to run features in concurrent.

-p, --pthread   using threads to run features in concurrent.

-P, --threads-pool
                using threads pool to run features in concurrent.

-g, --get-max-threads
                get hardware max threads.

    --max-thread
                change the maximum thread worker in pool. 
                The new value must be smaller than hardware limit.

    --max-line
                change maximum display lines. 
                By default maximum display line is 5.
```
## EXAMPLES
```
catwc file1 file2
                Display the content of file1, its words count and lines count, then do the same with file2.

catwc -c file   Display only the words count and lines count of file.

catwc -f file   Display the content of file, its words count and line count using fork.
```
