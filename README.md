# glueutils

system commands for controlling redirection and exit status

## Install

Run `make install` then add `~/.glue/bin` to PATH.

## commands

### juz

serially connect the processes of the command in a pipeline

```bash
echo 1 | juz 10 awk '{print $1*2}' # connect 10 awks in a pipeline
1024
```

### flip12

switch stdout and stderr

```bash
$ flip12 echo abc | rev
abc
$ flip12 echo abc 2>&1 | rev
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

