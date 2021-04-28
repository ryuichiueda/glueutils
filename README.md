# glueutils

system commands for controlling redirection and exit status

## Install

Run `make install` then add `~/.glue/bin` to PATH.

## commands

### juz

serially connect the processes of the command in a pipeline

```bash
$ echo 1 | juz 10 awk '{print $1*2}' # connect 10 awks in a pipeline
1024
```

"Juz" means Juzu（数珠）, which is a bracelet for buddists. It is composed of wooden balls chained a string.

### rep

repeat the command 

```
$ rep 3 echo hoge
hoge
hoge
hoge
```

### flip12

switch stdout and stderr

```bash
$ flip12 echo abc | rev
abc
$ flip12 echo abc 2>&1 | rev
cba
```

### con12

merge stderr into stdout and output

```
$ con12 strace seq 100
...
fstat(1, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
write(1, "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14"..., 2921
2
3
4
...
```

### con12safe

merge stderr into stdout and output safely with it's internal buffer and mutex

```bash
$ con12safe strace seq 100
...
mmap(NULL, 6758560, PROT_READ, MAP_PRIVATE, 4, 0) = 0x7f0ed9267000
close(4)                                = 0
fstat(1, {st_mode=S_IFIFO|0600, st_size=0, ...}) = 0
1                                                <- never mixed into errors
2
3
...
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

