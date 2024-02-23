void setClockScale(VOLTS __x)
{
  uint8_t __tmp = _BV(CLKPCE); /*[1]*/
  __asm__ __volatile__ (
    "in __tmp_reg__,__SREG__" "\n\t"
    "cli" "\n\t"
    "sts %1, %0" "\n\t"
    "sts %1, %2" "\n\t"
    "out __SREG__, __tmp_reg__"
    : /* no outputs */
    : "d" (__tmp),
    "M" (_SFR_MEM_ADDR(CLKPR)),
    "d" (__x)
    : "r0"
  ); /*[2]*/
}
//hi
  #if defined(ENABLE_3V3FIX)
      // Stop serial if running
    #if !defined(enable_serial) && defined(ENABLE_UPDATER)
      ClockedSerial.end();
    #endif
      // Set clock speed        
      clock = CS_16MHZ;
      setClockScale(newVoltage); /*[2]*/
      // Restart serial
    #if !defined(enable_serial) && defined(ENABLE_UPDATER)
      ClockedSerial.begin(UPD_BAUD);
    #endif
  //#else
    //  clock = CS_16MHZ;
  //#endif
//not needed 
