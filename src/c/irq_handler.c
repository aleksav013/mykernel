#include<source/irq_handler.h>
#include<source/stdio.h>
#include<asm.h>

void irq0_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 0.\n");
    printf("Divide-by-zero Error\n");
}

void irq1_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 1.\n");
    printf("Debug\n");
}

void irq2_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 2.\n");
    printf("Non-maskable Interrupt\n");
}

void irq3_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 3.\n");
    printf("Breakpoint\n");
}

void irq4_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 4.\n");
    printf("Overflow\n");
}

void irq5_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 5.\n");
    printf("Bound Range Exceeded\n");
}

void irq6_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 6.\n");
    printf("Invalid Opcode\n");
}

void irq7_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 7.\n");
    printf("Device Not Available\n");
}

void irq8_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 8.\n");
    printf("Double Fault\n");
}

void irq9_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 9.\n");
    printf("Coprocessor Segment Overrun\n");
}

void irq10_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 10.\n");
    printf("Invalid TSS\n");
}

void irq11_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 11.\n");
    printf("Segment Not Present\n");
}

void irq12_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 12.\n");
    printf("Stack-Segment Fault\n");
}

void irq13_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 13.\n");
    printf("General Protection Fault\n");
}

void irq14_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 14.\n");
    printf("Page Fault\n");
}

void irq15_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 15.\n");
    printf("Reserved\n");
}

void irq16_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 16.\n");
    printf("x87 Floating-Point Exception\n");
}

void irq17_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 17.\n");
    printf("Alignment Check\n");
}

void irq18_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 18.\n");
    printf("Machine Check\n");
}

void irq19_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 19.\n");
    printf("SIMD Floating-Point ExceptionM/#XF\n");
}

void irq20_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 20.\n");
    printf("Virtualization Exception\n");
}

void irq21_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 21.\n");
    printf("Reserved\n");
}

void irq22_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 22.\n");
    printf("Reserved\n");
}

void irq23_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 23.\n");
    printf("Reserved\n");
}

void irq24_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 24.\n");
    printf("Reserved\n");
}

void irq25_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 25.\n");
    printf("Reserved\n");
}

void irq26_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 26.\n");
    printf("Reserved\n");
}

void irq27_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 27.\n");
    printf("Reserved\n");
}

void irq28_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 28.\n");
    printf("Reserved\n");
}

void irq29_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 29.\n");
    printf("Reserved\n");
}

void irq30_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 30.\n");
    printf("Security Exception\n");
}

void irq31_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 31.\n");
    printf("Reserved\n");
}
void irq34_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 34.\n");
}

void irq35_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 35.\n");
}

void irq36_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 36.\n");
}

void irq37_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 37.\n");
}

void irq38_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 38.\n");
}

void irq39_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
}

void irq40_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 40.\n");
}

void irq41_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 41.\n");
}

void irq42_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 42.\n");
}

void irq43_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 43.\n");
}

void irq44_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 44.\n");
}

void irq45_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 45.\n");
}

void irq46_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 46.\n");
}

void irq47_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 47.\n");
}

void irq48_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 48.\n");
}

void irq49_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 49.\n");
}

void irq50_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 50.\n");
}

void irq51_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 51.\n");
}

void irq52_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 52.\n");
}

void irq53_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 53.\n");
}

void irq54_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 54.\n");
}

void irq55_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 55.\n");
}

void irq56_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 56.\n");
}

void irq57_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 57.\n");
}

void irq58_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 58.\n");
}

void irq59_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 59.\n");
}

void irq60_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 60.\n");
}

void irq61_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 61.\n");
}

void irq62_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 62.\n");
}

void irq63_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 63.\n");
}

void irq64_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 64.\n");
}

void irq65_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 65.\n");
}

void irq66_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 66.\n");
}

void irq67_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 67.\n");
}

void irq68_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 68.\n");
}

void irq69_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 69.\n");
}

void irq70_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 70.\n");
}

void irq71_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 71.\n");
}

void irq72_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 72.\n");
}

void irq73_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 73.\n");
}

void irq74_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 74.\n");
}

void irq75_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 75.\n");
}

void irq76_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 76.\n");
}

void irq77_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 77.\n");
}

void irq78_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 78.\n");
}

void irq79_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 79.\n");
}

void irq80_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 80.\n");
}

void irq81_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 81.\n");
}

void irq82_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 82.\n");
}

void irq83_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 83.\n");
}

void irq84_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 84.\n");
}

void irq85_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 85.\n");
}

void irq86_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 86.\n");
}

void irq87_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 87.\n");
}

void irq88_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 88.\n");
}

void irq89_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 89.\n");
}

void irq90_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 90.\n");
}

void irq91_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 91.\n");
}

void irq92_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 92.\n");
}

void irq93_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 93.\n");
}

void irq94_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 94.\n");
}

void irq95_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 95.\n");
}

void irq96_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 96.\n");
}

void irq97_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 97.\n");
}

void irq98_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 98.\n");
}

void irq99_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 99.\n");
}

void irq100_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 100.\n");
}

void irq101_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 101.\n");
}

void irq102_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 102.\n");
}

void irq103_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 103.\n");
}

void irq104_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 104.\n");
}

void irq105_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 105.\n");
}

void irq106_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 106.\n");
}

void irq107_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 107.\n");
}

void irq108_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 108.\n");
}

void irq109_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 109.\n");
}

void irq110_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 110.\n");
}

void irq111_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 111.\n");
}

void irq112_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 112.\n");
}

void irq113_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 113.\n");
}

void irq114_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 114.\n");
}

void irq115_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 115.\n");
}

void irq116_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 116.\n");
}

void irq117_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 117.\n");
}

void irq118_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 118.\n");
}

void irq119_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 119.\n");
}

void irq120_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 120.\n");
}

void irq121_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 121.\n");
}

void irq122_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 122.\n");
}

void irq123_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 123.\n");
}

void irq124_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 124.\n");
}

void irq125_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 125.\n");
}

void irq126_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 126.\n");
}

void irq127_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 127.\n");
}

void irq128_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 128.\n");
}

void irq129_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 129.\n");
}

void irq130_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 130.\n");
}

void irq131_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 131.\n");
}

void irq132_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 132.\n");
}

void irq133_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 133.\n");
}

void irq134_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 134.\n");
}

void irq135_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 135.\n");
}

void irq136_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 136.\n");
}

void irq137_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 137.\n");
}

void irq138_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 138.\n");
}

void irq139_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 139.\n");
}

void irq140_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 140.\n");
}

void irq141_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 141.\n");
}

void irq142_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 142.\n");
}

void irq143_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 143.\n");
}

void irq144_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 144.\n");
}

void irq145_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 145.\n");
}

void irq146_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 146.\n");
}

void irq147_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 147.\n");
}

void irq148_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 148.\n");
}

void irq149_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 149.\n");
}

void irq150_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 150.\n");
}

void irq151_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 151.\n");
}

void irq152_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 152.\n");
}

void irq153_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 153.\n");
}

void irq154_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 154.\n");
}

void irq155_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 155.\n");
}

void irq156_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 156.\n");
}

void irq157_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 157.\n");
}

void irq158_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 158.\n");
}

void irq159_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 159.\n");
}

void irq160_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 160.\n");
}

void irq161_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 161.\n");
}

void irq162_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 162.\n");
}

void irq163_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 163.\n");
}

void irq164_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 164.\n");
}

void irq165_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 165.\n");
}

void irq166_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 166.\n");
}

void irq167_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 167.\n");
}

void irq168_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 168.\n");
}

void irq169_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 169.\n");
}

void irq170_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 170.\n");
}

void irq171_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 171.\n");
}

void irq172_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 172.\n");
}

void irq173_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 173.\n");
}

void irq174_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 174.\n");
}

void irq175_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 175.\n");
}

void irq176_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 176.\n");
}

void irq177_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 177.\n");
}

void irq178_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 178.\n");
}

void irq179_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 179.\n");
}

void irq180_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 180.\n");
}

void irq181_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 181.\n");
}

void irq182_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 182.\n");
}

void irq183_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 183.\n");
}

void irq184_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 184.\n");
}

void irq185_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 185.\n");
}

void irq186_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 186.\n");
}

void irq187_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 187.\n");
}

void irq188_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 188.\n");
}

void irq189_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 189.\n");
}

void irq190_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 190.\n");
}

void irq191_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 191.\n");
}

void irq192_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 192.\n");
}

void irq193_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 193.\n");
}

void irq194_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 194.\n");
}

void irq195_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 195.\n");
}

void irq196_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 196.\n");
}

void irq197_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 197.\n");
}

void irq198_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 198.\n");
}

void irq199_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 199.\n");
}

void irq200_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 200.\n");
}

void irq201_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 201.\n");
}

void irq202_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 202.\n");
}

void irq203_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 203.\n");
}

void irq204_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 204.\n");
}

void irq205_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 205.\n");
}

void irq206_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 206.\n");
}

void irq207_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 207.\n");
}

void irq208_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 208.\n");
}

void irq209_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 209.\n");
}

void irq210_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 210.\n");
}

void irq211_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 211.\n");
}

void irq212_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 212.\n");
}

void irq213_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 213.\n");
}

void irq214_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 214.\n");
}

void irq215_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 215.\n");
}

void irq216_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 216.\n");
}

void irq217_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 217.\n");
}

void irq218_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 218.\n");
}

void irq219_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 219.\n");
}

void irq220_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 220.\n");
}

void irq221_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 221.\n");
}

void irq222_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 222.\n");
}

void irq223_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 223.\n");
}

void irq224_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 224.\n");
}

void irq225_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 225.\n");
}

void irq226_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 226.\n");
}

void irq227_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 227.\n");
}

void irq228_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 228.\n");
}

void irq229_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 229.\n");
}

void irq230_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 230.\n");
}

void irq231_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 231.\n");
}

void irq232_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 232.\n");
}

void irq233_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 233.\n");
}

void irq234_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 234.\n");
}

void irq235_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 235.\n");
}

void irq236_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 236.\n");
}

void irq237_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 237.\n");
}

void irq238_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 238.\n");
}

void irq239_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 239.\n");
}

void irq240_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 240.\n");
}

void irq241_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 241.\n");
}

void irq242_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 242.\n");
}

void irq243_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 243.\n");
}

void irq244_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 244.\n");
}

void irq245_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 245.\n");
}

void irq246_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 246.\n");
}

void irq247_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 247.\n");
}

void irq248_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 248.\n");
}

void irq249_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 249.\n");
}

void irq250_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 250.\n");
}

void irq251_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 251.\n");
}

void irq252_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 252.\n");
}

void irq253_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 253.\n");
}

void irq254_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 254.\n");
}

void irq255_handler(void)
{
    ioport_out(PIC1_COMMAND_PORT, 0x20);
    printf("Interrupt 255.\n");
}
