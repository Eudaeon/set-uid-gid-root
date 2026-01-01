# Set UID and GID to `root`

<div align="center">

[![GitHub stars](https://img.shields.io/github/stars/Eudaeon/set-uid-gid-root?style=for-the-badge)](https://github.com/Eudaeon/set-uid-gid-root/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/Eudaeon/set-uid-gid-root?style=for-the-badge)](https://github.com/Eudaeon/set-uid-gid-root/network)
[![GitHub issues](https://img.shields.io/github/issues/Eudaeon/set-uid-gid-root?style=for-the-badge)](https://github.com/Eudaeon/set-uid-gid-root/issues)
[![GitHub license](https://img.shields.io/github/license/Eudaeon/set-uid-gid-root?style=for-the-badge)](LICENSE)

**A small utility to ensure full UID and GID escalation to `root` before spawning a shell.**

</div>

## 📖 Overview

When obtaining RCE as `root`, a common way to obtain an interactive shell is by:

1. Copying `/bin/sh`.
2. Setting the SUID bit.
3. Executing the shell with the `-p` flag.

While this works, it only sets the EUID to 0, but not the RUID. This small utility ensures that both the UID and GID are properly set to `root` before spawning a shell.

## 📦 Setup

### Compilation

For maximum portability across different environments, compile the binary statically:

```bash
gcc set_uid_gid.c -o set_uid_gid -static
```

## 🔧 Usage

To enable the privilege escalation, a user with existing `root` access must set the SUID bit on the generated binary:

```bash
chmod 4777 ./set_uid_gid
```

Then, any user executing the binary will spawn into a shell with full `root` UID and GID:

```bash
./set_uid_gid
```

---

<div align="center">

**⭐ Star this repo if you find it helpful!**

Made with ❤️ by [Eudaeon](https://github.com/Eudaeon)

</div>
