#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/string.h>
// #include <linux/skbuff.h>
// #include <linux/types.h>

#include <linux/netdevice.h>


static int __init init(void)
{
	struct net_device *dev;

	dev = first_net_device(&init_net);
	while (dev) {
	    printk(KERN_INFO "found [%s]\n", dev->name);
	    dev = next_net_device(dev);
	}

	return 0;
}

static void __exit fini(void)
{
	printk(KERN_INFO "[CCD] Successfully unloaded module.\n");
}

module_init(init);
module_exit(fini);
