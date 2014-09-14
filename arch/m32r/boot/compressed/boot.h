/*
                  
  
                                                  
                        
                               
                  
  
                                                  
                        
                               
           
                                             
            
                                                    
                    
                               
  
                               
  
                                                  
                        
                               
           
                                             
                            
                                                    
                    
                               
  
                                  
  
                                                  
                        
                               
           
                                             
                              
                                                    
             
                               
  
 */
#ifdef __ASSEMBLY__
#define __val(x)	x
#else
#define __val(x)	(x)
#endif

#define DECOMPRESS_OFFSET_BASE	__val(0x00900000)
#define BOOT_RELOC_SIZE		__val(0x00001000)

#define KERNEL_EXEC_ADDR	__val(CONFIG_MEMORY_START)
#define KERNEL_DECOMPRESS_ADDR	__val(CONFIG_MEMORY_START + \
				      DECOMPRESS_OFFSET_BASE + BOOT_RELOC_SIZE)
#define KERNEL_ENTRY		__val(CONFIG_MEMORY_START + 0x1000)

#define BOOT_EXEC_ADDR		__val(CONFIG_MEMORY_START)
#define BOOT_RELOC_ADDR		__val(CONFIG_MEMORY_START + DECOMPRESS_OFFSET_BASE)
