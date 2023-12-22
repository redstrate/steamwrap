# steamwrap

Used for [Astra](https://git.sr.ht/~redstrate/astra) to initialize and communicate with the Steam API.

Due to restrictions on how the Steamworks SDK is distributed, I have to build it locally. Astra downloads a binary version of steamwrap from a distribution server during Flatpak build alongside the redistributable.

## Building

Remember that newer glibc/++ won't work when it's inside the Steam Linux Runtime, so I recommend using distrobox to build steamwrap:

```shell
$ distrobox create --name test --init --image debian:10 --additional-packages "systemd libpam-systemd" # Debian 10 is the base of Steam Linux Runtime 2.0
$ distrobox enter test
$ mkdir build
$ cd build
$ cmake -DSTEAMWORKS_LIBRARIES=<location of steam sdk>/redistributable_bin/linux64/libsteam_api.so -DSTEAMWORKS_INCLUDE_DIR=<location of steam sdk>/public/ ..
$ make
```
