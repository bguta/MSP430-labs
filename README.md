# Install
Arch-Linux

install mspgcc
```console
foo@bar:~$ yay -S mspgcc-ti
```
add to path
```console
foo@bar:~$ export PATH="/opt/ti/mspgcc/bin:$PATH"
```

install mspdebug so that programs can be uploaded
```console
foo@bar:~$ yay -S mspdebug
```

# upload program
```console
foo@bar:~$ mspdebug rf2500
```
then run
```
prog /path/to/main.elf
run
```

