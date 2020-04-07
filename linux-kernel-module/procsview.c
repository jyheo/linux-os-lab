#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

/* tested in kernel 4.19 */

static int __init init_procsview(void)
{
  struct task_struct *p;

  for_each_process(p) { /* macro defined in linux/sched/signal.h */
    printk( KERN_INFO "*** %s [%d] parent %s\n",
		p->comm, p->pid, p->parent->comm );
  }

  return 0;

}

static void __exit exit_procsview(void)
{
  return;
}

module_init(init_procsview);
module_exit(exit_procsview);

MODULE_LICENSE("GPL");

