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
