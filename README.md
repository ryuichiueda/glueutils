# glueutils

system commands for controlling redirection and exit status


## commands

### switch12

switch stdout and stderr

```bash
$ switch12 echo abc | rev
abc
$ switch12 echo abc 2>&1 | rev
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

### ign1, ign2, ign12

discard stdout or/and stderr

```
$ ign1 ls /etc/passwd
(no output)
$ ign2 ls aaaaaa
(no output)
$ ign12 ls /etc/passwd aaaaaa
(no output)
```

