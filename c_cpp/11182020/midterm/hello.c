#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LISCENSE("GPL");
MODULE_AUTHOR("An Nguyen");
MODULE_DESCRIPTION("Hello World Linux Kernel Module");

static int n = 5;
MODULE_PARM_DESC(n, "Given number");

static int result = 0;
MODULE_PARM_DESC(result, "Result if the given number is prime");

static int isPrime(int n)
{
  int result = 1;
  int i = 2;

  for(;i<=n/2; i++)
  {
    if(n%i==0) return result = 0;
  }

  if(n==1) return result = 2;

  return result;
}

static int __init hello_init(void)
{
  printk(KERN_INFO "Hello World\n");
  printk(KERN_INFO "Check prime number\n");

  result = isPrime(n);

  if(result==1)
  {
    printk(KERN_INFO "%d is a prime number\n", n);
  }
  else if(result==2)
  {
    printk(KERN_INFO "%d is neither prime nor composite\n", n);
  }
  else
  {
    printk(KERN_INFO "%d is not a prime number\n", n);
  }

  return 0;
}

static void __exit hello_exit(void)
{
  printk(KERN_INFO "Goodbye\n");
}

module_init(hello_init);
module_exit(hello_exit);
