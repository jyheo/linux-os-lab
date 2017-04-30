#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>

static int __init hs365_init(void)
{
  printk(KERN_INFO "hs365 registered\n");
  return 0;
}

static void __exit hs365_exit(void)
{
  printk(KERN_INFO "hs365 unregistered\n");
}

module_init(hs365_init);
module_exit(hs365_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hansung");
MODULE_DESCRIPTION("Hansung 365");

