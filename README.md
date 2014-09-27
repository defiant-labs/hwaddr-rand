hwaddr-rand
===========

Linux kernel module for generating random MAC-addresses for all attached network adapters upon load.

INSTALL
---

    make clean all
    sudo make install

USAGE
---
Run

    sudo modprobe hwaddr_rand

or include `hwaddr_rand` inside one of the `modprobe.d`'s .conf files to load on boot.

ACHTUNG
---
Does hurt all your active internet connections, daemons, network managers, etc. So better load it only at boot time and use things like `macchanger` to spoof MAC addresses of your newly-attached USB dongles.

This is a very fresh module and it hasn't been tested much, so please don't blame me if it leaks your real MAC address.
I need help testing and improving this toy, so please feel free to contribute.

