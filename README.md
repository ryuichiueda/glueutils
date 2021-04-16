# glueutils

system commands for controlling redirection and exit status


## commands

### switch12

switch stdout and stderr

```bash
$ ./switch12 echo abc | rev
abc
$ ./switch12 echo abc 2>&1 | rev
cba
```

### log2

write the standard output to a file

```
$ log2 hoge ls 'aaaa'
$ cat hoge
ls: cannot access 'aaaa': No such file or directory
```

### ignerr

ignore the exit status

```
$ ignerr ls aaaa
ls: cannot access 'aaaa': No such file or directory
$ echo $?
0
```
