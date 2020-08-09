#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

int valueETX, arr_valueETX[4];
char *nameETX;
int cb_valueETX;

module_param(valueETX, int, S_IRUSR|S_IWUSR);
module_param(nameETX, charp, S_IRUSR|S_IWUSR);
module_param_array(arr_valueETX, int, NULL, S_IRUSR|S_IWUSR);


//-------------- module param_cb()                        //
int notify_param(const char *val, const struct kernel_param *kp)
{
  int res = param_set_int(val, kp);
  if(res == 0)
    {
      printk(KERN_INFO "Call back function called...\n");
      printk(KERN_INFO "New value of cb_valueETX = %d\n", cb_valueETX);
      return 0;
    }
  return -1;
  
}

const struct kernel_param_ops my_param_ops = {
  .set = &notify_param,
  .get = &param_get_int
};

module_param_cb(cb_valueETX, &my_param_ops, &cb_valueETX, S_IRUSR|S_IWUSR);

  
//Module init function
static int __init basicmod_init(void)
{
  printk(KERN_INFO "Init - %s\n", __func__);
  int i;
  printk(KERN_INFO "ValueETX = %d\n", valueETX);
  printk(KERN_INFO "cb_valueETX = %d\n", cb_valueETX);
  printk(KERN_INFO "NameETX = %s\n", nameETX);
  for(i =0 ; i < (sizeof arr_valueETX / sizeof (int)); i++)
    {
      printk(KERN_INFO "Arr_value[%d] = %d\n", i, arr_valueETX[i]);
    }
  
  return 0;
}


//Module exit function
static void __exit basicmod_exit(void)
{
  printk( KERN_INFO "Exit - %s\n", __func__);
  return 0;
}

MODULE_LICENSE("GPL");

module_init(basicmod_init);
module_exit(basicmod_exit);
