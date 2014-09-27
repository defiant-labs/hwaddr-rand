#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/string.h>
#include <linux/sched.h>
#include <linux/netdevice.h>

// List of manufacturers
#include "oui_list.h"


static int __init init(void)
{
    struct net_device *dev;
#ifdef OUI_LIST_H
    unsigned char *oui;
    long unsigned int rand;
#endif

    pr_info("\nHello. My name is hwaddr_rand and I am going to randomize \n"
        "MAC addresses of all your devices so badly that even the \n"
        "manufacturers won't recognize them when I'm done.\n\n"
        "Let's take a look at what you got...\n");

    read_lock(&dev_base_lock);
    for_each_netdev(&init_net, dev) {
        pr_info("  I found interface %s with MAC address %02x:%02x:%02x:%02x:%02x:%02x\n"
                , dev->name
                , dev->dev_addr[0]
                , dev->dev_addr[1]
                , dev->dev_addr[2]
                , dev->dev_addr[3]
                , dev->dev_addr[4]
                , dev->dev_addr[5]
            );

        if(!strcmp(dev->name, "lo")) {
            pr_info("    [This is a loopback device, I'm not touching that]\n");
        } else {
            pr_info("    [Overwriting the hwaddr of interface %s] ...\n", dev->name);

#ifndef OUI_LIST_H
            pr_info("    [Generating a fully random MAC address for %s] ...\n", dev->name);

            get_random_bytes(dev->dev_addr, 6);
            dev->dev_addr[0] &= 0xfe;    /* clear multicast bit */
            dev->dev_addr[0] |= 0x02;    /* set local assignment bit (IEEE802) */
#else
            pr_info("    [Generating a vendor-based MAC address for %s] ...\n", dev->name);

            // oui = oui_list[55];
            get_random_bytes(&rand, sizeof(rand));
            oui = oui_list[rand % (sizeof(oui_list) / sizeof(oui_list[0]))];

            get_random_bytes(dev->dev_addr, 6);
            dev->dev_addr[0] = oui[0];
            dev->dev_addr[1] = oui[1];
            dev->dev_addr[2] = oui[2];
#endif

            pr_info("    [Done, the new MAC address for %s is %02x:%02x:%02x:%02x:%02x:%02x]\n"
                , dev->name
                , dev->dev_addr[0]
                , dev->dev_addr[1]
                , dev->dev_addr[2]
                , dev->dev_addr[3]
                , dev->dev_addr[4]
                , dev->dev_addr[5]
            );
        }
    }
    read_unlock(&dev_base_lock);
    
    return 0;
}

static void __exit fini(void)
{
    pr_info("\nBye! Call me...\n");
}


module_init(init);
module_exit(fini);

MODULE_DESCRIPTION("MAC address randomizer");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.7.1");
MODULE_AUTHOR("Defiant Labs (https://github.com/defiant-labs)");
