hwaddr-rand
===========

Linux kernel module which generates random MAC-addresses for all attached network adapters on load.

INSTALL
---

    make clean all
    sudo make install

USAGE
---
Make sure to add `hwaddr_rand` to either `/etc/modules` or to `/etc/modules-load.d/hwaddr_rand.conf`, 
depending on your GNU/Linux OS environment variation.

That will make the module load and randomize the MAC addresses during the next system boot.

You can run

    sudo modprobe hwaddr_rand

To load the module without rebooting your system.

Keep in mind that all your current network connections will be intervened by this action.

UNINSTALL
---

    sudo make uninstall clean

ACHTUNG
---
Does hurt all your active internet connections, daemons, network managers, etc.
So better load it only at boot time and use things like `macchanger` to spoof MAC addresses of your newly-attached USB dongles.

This is a very fresh module and it hasn't been tested much, so please don't blame me if it leaks your real MAC address and you go to jail.
I need help testing and improving this toy, so please feel free to contribute.

