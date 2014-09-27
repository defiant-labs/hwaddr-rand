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

TIPS
---

1) Attempt to boost the power of your adapter by doing this as su:

    ifconfig wlan0 down
    iw reg set BO
    ifconfig wlan0 up
    iwconfig wlan0 channel 13
    iwconfig wlan0 txpower 30

2) Change your regulatory domain permanently by setting `REGDOMAIN=BO` in `/etc/default/crda`

ACHTUNG!
---
Does hurt all your active internet connections, daemons, network managers, etc.
Better load it only at boot time and use things like `macchanger` to spoof MACs of your newly-attached USB WLAN adapters.

This is a very fresh module and hasn't been tested much, so please don't blame me if it leaks your real MAC address and you go to jail.
I need help testing and improving this toy, so please feel free to contribute.

2.4GHz is the same frequency range as kitchen microwave ovens. 
It resonates with water molecules (that's how the food's getting cooked) and 
*supposedly* may cause cancer if exposed to a strong power for a long time. By increasing the output 
power of something you sit in front of or wear in your pocket the whole day you *may* damage your health.

Consider that changing regdomains, MAC addresses and boosting the power may be illegal in your region.
Refer to CRDA regdomain database to learn more.

This module has been developed for personal use and I do not bear any responsibility for what others may do with it.

