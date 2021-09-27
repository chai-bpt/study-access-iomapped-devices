#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <asm/io.h>

#define DAY 0x07
#define MONTH 0x08
#define YEAR 0x09

#define ADDRESS_REG 0x70
#define DATA_REG 0x71

static unsigned char get_rtc(unsigned char addr)
{
	outb(addr, ADDRESS_REG);
	return inb(DATA_REG);
}

static int __init rtc_init(void)
{
	pr_info("\nrtc module loaded\n");
	pr_info("\nday = %x\n",get_rtc(DAY));
	pr_info("\nmonth = %x\n",get_rtc(MONTH));
	pr_info("\nyear = %x\n",get_rtc(YEAR));
	return(0);
}

static void __exit rtc_exit(void)
{
	pr_info("\nrtc module unloaded\n");
}

module_init(rtc_init);
module_exit(rtc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("chai.bpt@gmail.com");
MODULE_DESCRIPTION("STUDY:port mapped address space");
