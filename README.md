# Set UID and GID to `root`  

A simple program to set the UID and GID to `root` and then spawn a shell.  

## Rationale  

When obtaining RCE as `root`, a common way to escalate privileges to an interactive shell is by:  

1. Copying `/bin/sh`  
2. Setting the SUID bit  
3. Executing the shell with the `-p` flag  

While this works, it only sets the EUID to `0`, but not the RUID. This binary ensures that both the UID and GID are properly set to `root`.  

## Compilation  

To compile the binary statically, use:  

```sh
gcc set_uid_gid.c -o set_uid_gid -static
```

## Usage  

After compiling, make `root` set the SUID bit on the generated binary to allow privilege escalation:  

```sh
chmod 4777 set_uid_gid
```

Then, execute the binary to spawn a `root` shell.  
