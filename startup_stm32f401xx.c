/***********************************************************************/
/***********************************************************************/
/***************************** Startup Code ****************************/
/***************************** Version:1.00 ****************************/
/***********************************************************************/
/***********************************************************************/
#define NULL (*void)(0)

/************************************/
/*needed variabls from linker script*/
/************************************/
extern int _estack;
extern int _sdata_FLASH;
extern int _sdata;
extern int _edata;
extern int _sbss_RAM;
extern int _ebss_RAM;
extern void main();

/**************************************************************************************************/
/*setting the ISR vector table prototypes with some chanes to avoid impleminting every one of them*/
/**************************************************************************************************/
void __attribute__((weak, )) Reset_Handler(void);
void __attribute__((weak, )) Default_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) NMI_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) HardFault_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) MemManage_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) BusFault_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) UsageFault_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) SVCall_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) Debug_Monitor_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) PendSV_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) Systick_Handler(void);
/*****************************************************************************************/
/************************************ external interrupts ********************************/
/*****************************************************************************************/
void __attribute__((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TAMP_STAMP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream6_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) ADC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_UP_TIM10_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI17_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI18_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream7_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_FS_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream6_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream7_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART6_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C3_EV_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C3_ER_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) FPU_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI4_IRQHandler(void);

typedef void (*const PF_Handler)(void); // PF abbereviation of pointer to function

// To save the comming elements in the ((.isr section))
//"used" => to tell the compiler that not all the elements will be used
__attribute__((section(".isr_vector"), used))

// making the array which will store all the elements of the isr section
// this addresses are stored  according to the data sheet order
PF_Handler vector_Table[] =
    {
        (PF_Handler)&_estack, //=> put the stack address to be initialized
        Reset_Handler,
        NMI_Handler,
        HardFault_Handler,
        MemManage_Handler,
        BusFault_Handler,
        UsageFault_Handler,
        0, // Reserved
        0,
        0,
        0,
        SVCall_Handler,
        Debug_Monitor_Handler,
        0,
        PendSV_Handler,
        Systick_Handler,
        WWDG_IRQHandler,
        PVD_IRQHandler,
        TAMP_STAMP_IRQHandler,
        RTC_WKUP_IRQHandler,
        FLASH_IRQHandler,
        RCC_IRQHandler,
        EXTI0_IRQHandler,
        EXTI1_IRQHandler,
        EXTI2_IRQHandler,
        EXTI3_IRQHandler,
        EXTI4_IRQHandler,
        DMA1_Stream0_IRQHandler,
        DMA1_Stream1_IRQHandler,
        DMA1_Stream2_IRQHandler,
        DMA1_Stream3_IRQHandler,
        DMA1_Stream4_IRQHandler,
        DMA1_Stream5_IRQHandler,
        DMA1_Stream6_IRQHandler,
        ADC_IRQHandler,
        0,
        0,
        0,
        0,
        EXTI9_5_IRQHandler,
        TIM1_BRK_TIM9_IRQHandler,
        TIM1_UP_TIM10_IRQHandler,
        TIM1_TRG_COM_TIM11_IRQHandler,
        TIM1_CC_IRQHandler,
        TIM2_IRQHandler,
        TIM3_IRQHandler,
        TIM4_IRQHandler,
        I2C1_EV_IRQHandler,
        I2C1_ER_IRQHandler,
        I2C2_EV_IRQHandler,
        I2C2_ER_IRQHandler,
        SPI1_IRQHandler,
        SPI2_IRQHandler,
        USART1_IRQHandler,
        USART2_IRQHandler,
        0,
        EXTI15_10_IRQHandler,
        EXTI17_IRQHandler,
        EXTI18_IRQHandler,
        0,
        0,
        0,
        0,
        DMA1_Stream7_IRQHandler,
        0,
        SDIO_IRQHandler,
        TIM5_IRQHandler,
        SPI3_IRQHandler,
        0,
        0,
        0,
        0,
        DMA2_Stream0_IRQHandler,
        DMA2_Stream1_IRQHandler,
        DMA2_Stream2_IRQHandler,
        DMA2_Stream3_IRQHandler,
        DMA2_Stream4_IRQHandler,
        0,
        0,
        0,
        0,
        0,
        0,
        OTG_FS_IRQHandler,
        DMA2_Stream5_IRQHandler,
        DMA2_Stream6_IRQHandler,
        DMA2_Stream7_IRQHandler,
        USART6_IRQHandler,
        I2C3_EV_IRQHandler,
        I2C3_ER_IRQHandler,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        FPU_IRQHandler,
        SPI4_IRQHandler,
}

//=>    __attribute__((section(".init"),used))  => to put the comming function in the init section
//=>  this is the  most important section in the startup code
void __attribute__((section(".init"), used)) Reset_Handler(void)
{
    /*declare the pointers which will be used to carry the addresses of the start and end of the memory sections*/
    unsigned int *memory_source_Address = NULL;
    unsigned int *memory_destination_Address = NULL;
    unsigned int section_size = 0;
    /*storing the addresses which we got from the linker script into the pointers*/
    memory_source_Address = (int *)&_sdata_FLASH;
    memory_destination_Address = (int *)&_sdata;
    /*calculate the data section size to loop on it*/
    section_size = (&_edata) - (&_sdata);

    int counter = 0;

    // copying the data section from flash to the ram
    for (counter = 0; counter < section_size; counter++)
    {
        /*copying from source to distination*/
        *memory_destination_Address++ = *memory_source_Address++;
    }

    // storing the bss section in the ram
    memory_destination_Address = (int *)&_sbss_RAM;

    /*calculate the bss section size to loop on it*/
    section_size = (&_ebss_RAM) - (&_sbss_RAM);

    /*looping on the bss section and assining every 4byets with zero*/
    for (counter = 0; counter < section_size; counter++)
    {
        memory_destination_Address++ = 0;
    }

    // calling main function
    main();
    while (1)
    {
    }
}

/*implementation of the function which will be called instade of any other isr function in case not found in any other file*/
/*storing this implementation in the init section*/
void __attribute__((section(".init"), used)) Default_Handler(void)
{
    while (1)
    {
    }
}
//what