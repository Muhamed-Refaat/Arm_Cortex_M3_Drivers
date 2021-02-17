
#include "StdTypes.h"
#include "Utils.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_Config.h"





/* 							9 Arguments 			*/
void DMA_voidChannelInit(DMA_Channel_type channel ,DMA_ChannelPriorityLevl_type periority, DMA_PrephMemorySize_type prephsize , DMA_PrephMemorySize_type memsize, DMA_PrephMemoryIncMode_type prephinc, DMA_PrephMemoryIncMode_type MemInc, DMA_CircularMode_type  Circular)
{


	switch(channel)
	{
	case DMA_CHANNEL1 :
		DMA -> CCR1 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR1,12);    CLR_BIT(DMA ->CCR1,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR1,12);    CLR_BIT(DMA ->CCR1,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR1,12);    SET_BIT(DMA ->CCR1,13);  }
		else 							          {      SET_BIT(DMA ->CCR1,12);    SET_BIT(DMA ->CCR1,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR1,8);     CLR_BIT(DMA ->CCR1,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR1,8);     CLR_BIT(DMA ->CCR1,9);   }
		else  							          {      CLR_BIT(DMA ->CCR1,8);     SET_BIT(DMA ->CCR1,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR1,10);    CLR_BIT(DMA ->CCR1,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR1,10);    CLR_BIT(DMA ->CCR1,11);  }
		else  							          {      CLR_BIT(DMA ->CCR1,10);    SET_BIT(DMA ->CCR1,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR1,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR1,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR1,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR1,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR1,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR1,5);							     }
		break;
	case DMA_CHANNEL2 :
		DMA -> CCR2 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR2,12);    CLR_BIT(DMA ->CCR2,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR2,12);    CLR_BIT(DMA ->CCR2,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR2,12);    SET_BIT(DMA ->CCR2,13);  }
		else 							          {      SET_BIT(DMA ->CCR2,12);    SET_BIT(DMA ->CCR2,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR2,8);     CLR_BIT(DMA ->CCR2,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR2,8);     CLR_BIT(DMA ->CCR2,9);   }
		else  							          {      CLR_BIT(DMA ->CCR2,8);     SET_BIT(DMA ->CCR2,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR2,10);    CLR_BIT(DMA ->CCR2,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR2,10);    CLR_BIT(DMA ->CCR2,11);  }
		else  							          {      CLR_BIT(DMA ->CCR2,10);    SET_BIT(DMA ->CCR2,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR2,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR2,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR2,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR2,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR2,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR2,5);							     }
		break;
	case DMA_CHANNEL3 :
		DMA -> CCR3 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR3,12);    CLR_BIT(DMA ->CCR3,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR3,12);    CLR_BIT(DMA ->CCR3,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR3,12);    SET_BIT(DMA ->CCR3,13);  }
		else 							          {      SET_BIT(DMA ->CCR3,12);    SET_BIT(DMA ->CCR3,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR3,8);     CLR_BIT(DMA ->CCR3,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR3,8);     CLR_BIT(DMA ->CCR3,9);   }
		else  							          {      CLR_BIT(DMA ->CCR3,8);     SET_BIT(DMA ->CCR3,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR3,10);    CLR_BIT(DMA ->CCR3,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR3,10);    CLR_BIT(DMA ->CCR3,11);  }
		else  							          {      CLR_BIT(DMA ->CCR3,10);    SET_BIT(DMA ->CCR3,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR3,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR3,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR3,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR3,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR3,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR3,5);							     }
		break;
	case DMA_CHANNEL4 :
		DMA -> CCR4 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR4,12);    CLR_BIT(DMA ->CCR4,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR4,12);    CLR_BIT(DMA ->CCR4,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR4,12);    SET_BIT(DMA ->CCR4,13);  }
		else 							          {      SET_BIT(DMA ->CCR4,12);    SET_BIT(DMA ->CCR4,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR4,8);     CLR_BIT(DMA ->CCR4,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR4,8);     CLR_BIT(DMA ->CCR4,9);   }
		else  							          {      CLR_BIT(DMA ->CCR4,8);     SET_BIT(DMA ->CCR4,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR4,10);    CLR_BIT(DMA ->CCR4,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR4,10);    CLR_BIT(DMA ->CCR4,11);  }
		else  							          {      CLR_BIT(DMA ->CCR4,10);    SET_BIT(DMA ->CCR4,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR4,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR4,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR4,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR4,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR4,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR4,5);							     }
		break;
	case DMA_CHANNEL5 :
		DMA -> CCR5 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR5,12);    CLR_BIT(DMA ->CCR5,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR5,12);    CLR_BIT(DMA ->CCR5,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR5,12);    SET_BIT(DMA ->CCR5,13);  }
		else 							          {      SET_BIT(DMA ->CCR5,12);    SET_BIT(DMA ->CCR5,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR5,8);     CLR_BIT(DMA ->CCR5,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR5,8);     CLR_BIT(DMA ->CCR5,9);   }
		else  							          {      CLR_BIT(DMA ->CCR5,8);     SET_BIT(DMA ->CCR5,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR5,10);    CLR_BIT(DMA ->CCR5,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR5,10);    CLR_BIT(DMA ->CCR5,11);  }
		else  							          {      CLR_BIT(DMA ->CCR5,10);    SET_BIT(DMA ->CCR5,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR5,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR5,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR5,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR5,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR5,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR5,5);							     }

		break;
	case DMA_CHANNEL6 :
		DMA -> CCR6 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR6,12);    CLR_BIT(DMA ->CCR6,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR6,12);    CLR_BIT(DMA ->CCR6,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR6,12);    SET_BIT(DMA ->CCR6,13);  }
		else 							          {      SET_BIT(DMA ->CCR6,12);    SET_BIT(DMA ->CCR6,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR6,8);     CLR_BIT(DMA ->CCR6,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR6,8);     CLR_BIT(DMA ->CCR6,9);   }
		else  							          {      CLR_BIT(DMA ->CCR6,8);     SET_BIT(DMA ->CCR6,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR6,10);    CLR_BIT(DMA ->CCR6,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR6,10);    CLR_BIT(DMA ->CCR6,11);  }
		else  							          {      CLR_BIT(DMA ->CCR6,10);    SET_BIT(DMA ->CCR6,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR6,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR6,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR6,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR6,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR6,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR6,5);							     }
		break;
	case DMA_CHANNEL7 :
		DMA -> CCR7 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR7,12);    CLR_BIT(DMA ->CCR7,13);  }
		else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR7,12);    CLR_BIT(DMA ->CCR7,13);  }
		else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR7,12);    SET_BIT(DMA ->CCR7,13);  }
		else 							          {      SET_BIT(DMA ->CCR7,12);    SET_BIT(DMA ->CCR7,13);  }
	/*		 Adjust port sizes for prehiral and memory 				 */
		if(prephsize==DMA_8BITS)                  {      CLR_BIT(DMA ->CCR7,8);     CLR_BIT(DMA ->CCR7,9);   }
		else if (prephsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR7,8);     CLR_BIT(DMA ->CCR7,9);   }
		else  							          {      CLR_BIT(DMA ->CCR7,8);     SET_BIT(DMA ->CCR7,9);   }

		if(memsize==DMA_8BITS)                    {      CLR_BIT(DMA ->CCR7,10);    CLR_BIT(DMA ->CCR7,11);  }
		else if (memsize==DMA_16BITS)	          {      SET_BIT(DMA ->CCR7,10);    CLR_BIT(DMA ->CCR7,11);  }
		else  							          {      CLR_BIT(DMA ->CCR7,10);    SET_BIT(DMA ->CCR7,11);  }
	/*		Incremented address  Or fixed address transfer 		*/
		if(prephinc==DMA_INCREMENT_ENABLE)        {		 SET_BIT(DMA ->CCR7,6);							     }
		else							          {		 CLR_BIT(DMA ->CCR7,6);							     }

		if(MemInc==DMA_INCREMENT_ENABLE)          {		 SET_BIT(DMA ->CCR7,7);							     }
		else							          {		 CLR_BIT(DMA ->CCR7,7);							     }
    /*	      Circular mode 									*/
		if(Circular == DMA_CIRCULAR_ENABLE )      {		 SET_BIT(DMA ->CCR7,5);							     }
		else							          {		 CLR_BIT(DMA ->CCR7,5);							     }
		break;

	default : /* Error */  ;

	}

}


void DMA_voidSetSourceDestinationAddresses(DMA_Channel_type channel, DMA_SetDirection_type direction,u32* Ref_u32_SourceAddress,u32*  Ref_u32_DestinationAddress ,u16 Copy_u16_NumberOfItems)
{
	switch(channel)
	{
	case DMA_CHANNEL1 :
		DMA -> CCR1 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR1 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR1 , 4);
			/* Source address   */
			DMA-> CMAR1 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CPAR stores memory address now*/
			DMA-> CPAR1 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR1 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR1 , 4);
		   /* Source address   */
		   DMA-> CMAR1 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR1 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR1 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR1 , 4);
			/* Source address   */
			DMA-> CPAR1 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR1 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR1 , 14);
			CLR_BIT(DMA->CCR1 , 4);
			DMA-> CPAR1 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR1 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR1 = (u16)Copy_u16_NumberOfItems;
		break;
	case DMA_CHANNEL2 :
		DMA -> CCR2 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR2 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR2 , 4);
			/* Source address  CPAR stores memory address now */
			DMA-> CMAR2 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  */
			DMA-> CPAR2 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR2 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR2 , 4);
		   /* Source address   */
		   DMA-> CMAR2 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR2 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR2 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR2 , 4);
			/* Source address   */
			DMA-> CPAR2 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR2 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR2 , 14);
			CLR_BIT(DMA->CCR2 , 4);
			DMA-> CPAR2 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR2 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR2 = (u16)Copy_u16_NumberOfItems;
		break;
	case DMA_CHANNEL3 :
		DMA -> CCR3 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR3 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR3 , 4);
			/* Source address  CPAR stores memory address now */
			DMA-> CMAR3 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  */
			DMA-> CPAR3 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR3 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR3 , 4);
		   /* Source address   */
		   DMA-> CMAR3 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR3 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR3 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR3 , 4);
			/* Source address   */
			DMA-> CPAR3 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR3 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR3 , 14);
			CLR_BIT(DMA->CCR3 , 4);
			DMA-> CPAR3 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR3 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR3 = (u16)Copy_u16_NumberOfItems;
		break;
	case DMA_CHANNEL4 :
		DMA -> CCR4 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR4 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR4 , 4);
			/* Source address  CPAR stores memory address now */
			DMA-> CMAR4 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  */
			DMA-> CPAR4 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR4 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR4 , 4);
		   /* Source address   */
		   DMA-> CMAR4 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR4 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR4 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR4 , 4);
			/* Source address   */
			DMA-> CPAR4 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR4 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR4 , 14);
			CLR_BIT(DMA->CCR4 , 4);
			DMA-> CPAR4 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR4 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR4 = (u16)Copy_u16_NumberOfItems;
		break;
	case DMA_CHANNEL5 :
		DMA -> CCR5 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR5 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR5 , 4);
			/* Source address  CPAR stores memory address now */
			DMA-> CMAR5 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  */
			DMA-> CPAR5 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR5 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR5 , 4);
		   /* Source address   */
		   DMA-> CMAR5 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR5 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR5 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR5 , 4);
			/* Source address   */
			DMA-> CPAR5 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR5 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR5 , 14);
			CLR_BIT(DMA->CCR5 , 4);
			DMA-> CPAR5 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR5 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR5 = (u16)Copy_u16_NumberOfItems;
		break;
	case DMA_CHANNEL6 :
		DMA -> CCR6 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR6 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR6 , 4);
			/* Source address  CPAR stores memory address now */
			DMA-> CMAR6 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  */
			DMA-> CPAR6 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR6 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR6 , 4);
		   /* Source address   */
		   DMA-> CMAR6 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR6 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR6 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR6 , 4);
			/* Source address   */
			DMA-> CPAR6 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR6 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR6 , 14);
			CLR_BIT(DMA->CCR6 , 4);
			DMA-> CPAR6 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR6 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR6 = (u16)Copy_u16_NumberOfItems;
		break;
	case DMA_CHANNEL7 :
		DMA -> CCR7 &= (~(1<<0));                     /*   Disable Channel without changing other configurations    */
		if(direction==DMA_MEMORY_TO_MEMORY)
		{
		    /*Memory To memory*/
			SET_BIT(DMA->CCR7 , 14);
			/* Read from memory*/
			SET_BIT(DMA->CCR7 , 4);
			/* Source address  CPAR stores memory address now */
			DMA-> CMAR7 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  */
			DMA-> CPAR7 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_MEMORY_TO_PREPHERIAL)
		{ /////////////////////////////////////////////////////////
			/*Memory To memory disabled */
		   CLR_BIT(DMA->CCR7 , 14);
		   /*  Read from memory  */
		   SET_BIT(DMA->CCR7 , 4);
		   /* Source address   */
		   DMA-> CMAR7 = (u32)Ref_u32_SourceAddress ;
		   	/* Destination address  */
		   DMA-> CPAR7 = (u32)Ref_u32_DestinationAddress ;
		///////////////////////////////////////////////////////////
		}
		else if(direction==DMA_PREPHERIAL_TO_PREPHERIAL)
		{
			CLR_BIT(DMA->CCR7 , 14);
			/*  Read from Prepherial   */
			CLR_BIT(DMA->CCR7 , 4);
			/* Source address   */
			DMA-> CPAR7 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
		    DMA-> CMAR7 = (u32)Ref_u32_DestinationAddress ;

		}
		else if(direction==DMA_PREPHERIAL_TO_MEMORY)
		{
			CLR_BIT(DMA->CCR7 , 14);
			CLR_BIT(DMA->CCR7 , 4);
			DMA-> CPAR7 = (u32)Ref_u32_SourceAddress ;
			/* Destination address  CMAR  is now a preherial address  */
			DMA-> CMAR7 = (u32)Ref_u32_DestinationAddress ;


		}
		DMA -> CNDTR7 = (u16)Copy_u16_NumberOfItems;
		break;
	default : ;
	}

}

void DMA_voidChannelEnable(DMA_Channel_type channel)
{

	switch(channel)
	{
	case DMA_CHANNEL1 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0x000000F;
		SET_BIT(DMA -> CCR1,0);
		break;
	case DMA_CHANNEL2 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0x00000F0;
		SET_BIT(DMA -> CCR2,0);
		break;
	case DMA_CHANNEL3 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0x0000F00;
		SET_BIT(DMA -> CCR3,0);
		break;

	case DMA_CHANNEL4 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0x000F000;
		SET_BIT(DMA -> CCR4,0);
		break;
	case DMA_CHANNEL5 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0x00F0000;
		SET_BIT(DMA -> CCR5,0);
		break;
	case DMA_CHANNEL6 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0x0F00000;
		SET_BIT(DMA -> CCR6,0);
		break;
	case DMA_CHANNEL7 :
	/*			Clear ALL interrupts				*/
		DMA -> IFCR |= (u32)0xF000000;
		SET_BIT(DMA -> CCR7,0);
		break;
	default: ;
	}
}


void DMA_voidChannelReconfigurePeriority(DMA_Channel_type channel,DMA_ChannelPriorityLevl_type periority)
{

	switch(channel)
		{
		case DMA_CHANNEL1 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR1,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR1,12);    CLR_BIT(DMA ->CCR1,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR1,12);    CLR_BIT(DMA ->CCR1,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR1,12);    SET_BIT(DMA ->CCR1,13);  }
			else 							          {      SET_BIT(DMA ->CCR1,12);    SET_BIT(DMA ->CCR1,13);  }
			break;

		case DMA_CHANNEL2 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR2,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR2,12);    CLR_BIT(DMA ->CCR2,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR2,12);    CLR_BIT(DMA ->CCR2,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR2,12);    SET_BIT(DMA ->CCR2,13);  }
			else 							          {      SET_BIT(DMA ->CCR2,12);    SET_BIT(DMA ->CCR2,13);  }
			break;
		case DMA_CHANNEL3 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR3,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR3,12);    CLR_BIT(DMA ->CCR3,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR3,12);    CLR_BIT(DMA ->CCR3,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR3,12);    SET_BIT(DMA ->CCR3,13);  }
			else 							          {      SET_BIT(DMA ->CCR3,12);    SET_BIT(DMA ->CCR3,13);  }
			break;
		case DMA_CHANNEL4 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR4,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR4,12);    CLR_BIT(DMA ->CCR4,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR4,12);    CLR_BIT(DMA ->CCR4,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR4,12);    SET_BIT(DMA ->CCR4,13);  }
			else 							          {      SET_BIT(DMA ->CCR4,12);    SET_BIT(DMA ->CCR4,13);  }
			break;
		case DMA_CHANNEL5 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR5,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR5,12);    CLR_BIT(DMA ->CCR5,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR5,12);    CLR_BIT(DMA ->CCR5,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR5,12);    SET_BIT(DMA ->CCR5,13);  }
			else 							          {      SET_BIT(DMA ->CCR5,12);    SET_BIT(DMA ->CCR5,13);  }
			break;
		case DMA_CHANNEL6 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR6,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR6,12);    CLR_BIT(DMA ->CCR6,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR6,12);    CLR_BIT(DMA ->CCR6,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR6,12);    SET_BIT(DMA ->CCR6,13);  }
			else 							          {      SET_BIT(DMA ->CCR6,12);    SET_BIT(DMA ->CCR6,13);  }
			break;
		case DMA_CHANNEL7 :
		/*   Disable Channel  before any changing in configurations  */
			CLR_BIT(DMA -> CCR7,0);
			if(periority == DMA_LOW )                 {  	 CLR_BIT(DMA ->CCR7,12);    CLR_BIT(DMA ->CCR7,13);  }
			else if (periority == DMA_MEDIUM)         {      SET_BIT(DMA ->CCR7,12);    CLR_BIT(DMA ->CCR7,13);  }
			else if (periority == DMA_HIGH)           {      CLR_BIT(DMA ->CCR7,12);    SET_BIT(DMA ->CCR7,13);  }
			else 							          {      SET_BIT(DMA ->CCR7,12);    SET_BIT(DMA ->CCR7,13);  }
			break;
		default :;

		}
}


void DMA_voidChannelDisable(DMA_Channel_type channel)
{
	switch(channel)
		{
		case DMA_CHANNEL1 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0x000000F;
			CLR_BIT(DMA -> CCR1,0);
			break;
		case DMA_CHANNEL2 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0x00000F0;
			CLR_BIT(DMA -> CCR2,0);
			break;
		case DMA_CHANNEL3 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0x0000F00;
			CLR_BIT(DMA -> CCR3,0);
			break;

		case DMA_CHANNEL4 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0x000F000;
			CLR_BIT(DMA -> CCR4,0);
			break;
		case DMA_CHANNEL5 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0x00F0000;
			CLR_BIT(DMA -> CCR5,0);
			break;
		case DMA_CHANNEL6 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0x0F00000;
			CLR_BIT(DMA -> CCR6,0);
			break;
		case DMA_CHANNEL7 :
		/*			Clear ALL interrupts				*/
			DMA -> IFCR |= (u32)0xF000000;
			CLR_BIT(DMA -> CCR7,0);
			break;
		default :;
		}
}


void DMA_voidInit(void)
{

}



/******************************** Interrupt Handlers  ********************************************/

static void(*DMA_PfCallBack[DMA_TOTAL_CHANNELS])(void) ={NULL};

void DMA_voidSetCallBack(DMA_Channel_type channel , void(*pf)(void))
{
		/**			Set global pointer to IQR	**/
	switch(channel)
		{
		case DMA_CHANNEL1 :
			if(pf !=NULL)
			{
			DMA_PfCallBack[DMA_CHANNEL1]= pf ;
			break;
			}
		case DMA_CHANNEL2 :
			DMA_PfCallBack[DMA_CHANNEL2]= pf ;
			break;
		case DMA_CHANNEL3 :
			DMA_PfCallBack[DMA_CHANNEL3]= pf ;
			break;
		case DMA_CHANNEL4 :
			DMA_PfCallBack[DMA_CHANNEL4]= pf ;
			break;
		case DMA_CHANNEL5 :
			DMA_PfCallBack[DMA_CHANNEL5]= pf ;
			break;
		case DMA_CHANNEL6 :
			DMA_PfCallBack[DMA_CHANNEL6]= pf ;
			break;
		case DMA_CHANNEL7 :
			DMA_PfCallBack[DMA_CHANNEL7]= pf ;
			break;
		default :;
		}
}

void DMA_voidHTIFEnable(DMA_Channel_type channel)
{
	switch(channel)
	{
	case DMA_CHANNEL1 :
	SET_BIT(DMA->CCR1,2);
		break;
	case DMA_CHANNEL2 :
	SET_BIT(DMA->CCR2,2);
		break;
	case DMA_CHANNEL3 :
	SET_BIT(DMA->CCR3,2);
		break;
	case DMA_CHANNEL4 :
	SET_BIT(DMA->CCR4,2);
		break;
	case DMA_CHANNEL5 :
	SET_BIT(DMA->CCR5,2);
		break;
	case DMA_CHANNEL6 :
	SET_BIT(DMA->CCR6,2);
		break;
	case DMA_CHANNEL7 :
	SET_BIT(DMA->CCR7,2);
		break;
	default :;
	}
}

void DMA_voidHTIFDisable(DMA_Channel_type channel)
{
	switch(channel)
		{
		case DMA_CHANNEL1 :
		CLR_BIT(DMA->CCR1,2);
			break;
		case DMA_CHANNEL2 :
		CLR_BIT(DMA->CCR2,2);
			break;
		case DMA_CHANNEL3 :
		CLR_BIT(DMA->CCR3,2);
			break;
		case DMA_CHANNEL4 :
		CLR_BIT(DMA->CCR4,2);
			break;
		case DMA_CHANNEL5 :
		CLR_BIT(DMA->CCR5,2);
			break;
		case DMA_CHANNEL6 :
		CLR_BIT(DMA->CCR6,2);
			break;
		case DMA_CHANNEL7 :
		CLR_BIT(DMA->CCR7,2);
			break;
		default :;
		}
}

void DMA_voidTCIFEnable(DMA_Channel_type channel)
{
	switch(channel)
		{
		case DMA_CHANNEL1 :
		SET_BIT(DMA->CCR1,1);
			break;
		case DMA_CHANNEL2 :
		SET_BIT(DMA->CCR2,1);
			break;
		case DMA_CHANNEL3 :
		SET_BIT(DMA->CCR3,1);
			break;
		case DMA_CHANNEL4 :
		SET_BIT(DMA->CCR4,1);
			break;
		case DMA_CHANNEL5 :
		SET_BIT(DMA->CCR5,1);
			break;
		case DMA_CHANNEL6 :
		SET_BIT(DMA->CCR6,1);
			break;
		case DMA_CHANNEL7 :
		SET_BIT(DMA->CCR7,1);
			break;
		default : ;
		}
}

void DMA_voidTCIFDisable(DMA_Channel_type channel)
{
	switch(channel)
	{
	case DMA_CHANNEL1 :
	CLR_BIT(DMA->CCR1,1);
		break;
	case DMA_CHANNEL2 :
	CLR_BIT(DMA->CCR2,1);
		break;
	case DMA_CHANNEL3 :
	CLR_BIT(DMA->CCR3,1);
		break;
	case DMA_CHANNEL4 :
	CLR_BIT(DMA->CCR4,1);
		break;
	case DMA_CHANNEL5 :
	CLR_BIT(DMA->CCR5,1);
		break;
	case DMA_CHANNEL6 :
	CLR_BIT(DMA->CCR6,1);
		break;
	case DMA_CHANNEL7 :
	CLR_BIT(DMA->CCR7,1);
		break;
	default :;
	}
}

void DMA_voidTEIFEnable(DMA_Channel_type channel)
{
	switch(channel)
	{
	case DMA_CHANNEL1 :
	SET_BIT(DMA->CCR1,3);
		break;
	case DMA_CHANNEL2 :
	SET_BIT(DMA->CCR2,3);
		break;
	case DMA_CHANNEL3 :
	SET_BIT(DMA->CCR3,3);
		break;
	case DMA_CHANNEL4 :
	SET_BIT(DMA->CCR4,3);
		break;
	case DMA_CHANNEL5 :
	SET_BIT(DMA->CCR5,3);
		break;
	case DMA_CHANNEL6 :
	SET_BIT(DMA->CCR6,3);
		break;
	case DMA_CHANNEL7 :
	SET_BIT(DMA->CCR7,3);
		break;
	default :;
	}
}

void DMA_voidTEIFDisable(DMA_Channel_type channel)
{
	switch(channel)
		{
		case DMA_CHANNEL1 :
		CLR_BIT(DMA->CCR1,3);
			break;
		case DMA_CHANNEL2 :
		CLR_BIT(DMA->CCR2,3);
			break;
		case DMA_CHANNEL3 :
		CLR_BIT(DMA->CCR3,3);
			break;
		case DMA_CHANNEL4 :
		CLR_BIT(DMA->CCR4,3);
			break;
		case DMA_CHANNEL5 :
		CLR_BIT(DMA->CCR5,3);
			break;
		case DMA_CHANNEL6 :
		CLR_BIT(DMA->CCR6,3);
			break;
		case DMA_CHANNEL7 :
		CLR_BIT(DMA->CCR7,3);
			break;
		default :;
		}
}
/////////////////////////////////////////////////////////////////////////
///////////////////////////IRQ///////////////////////////////////////////

void DMA1_Channel1_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,1))
	{
		/*Remove PIF TCIF*/
		SET_BIT(DMA->IFCR,1);
	}
	if(GET_BIT(DMA->ISR,2))
	{
		/*Remove PIF  HT */
		SET_BIT(DMA->IFCR,2);
	}
	if(GET_BIT(DMA->ISR,3))
	{
		/*Remove PIF  TE*/
		SET_BIT(DMA->IFCR,3);
	}
	/*	Clear CGIF*/
	DMA_PfCallBack[DMA_CHANNEL1]();
		SET_BIT(DMA->IFCR,0);


}

void DMA1_Channel2_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,5))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,5);
	}
	if(GET_BIT(DMA->ISR,6))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,6);
	}
	if(GET_BIT(DMA->ISR,7))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,7);
	}
	/*	Clear CGIF*/
	SET_BIT(DMA->IFCR,4);
	DMA_PfCallBack[DMA_CHANNEL2]();

}
void DMA1_Channel3_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,9))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,9);
	}
	if(GET_BIT(DMA->ISR,10))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,10);
	}
	if(GET_BIT(DMA->ISR,11))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,11);
	}
	/*	Clear CGIF*/
		SET_BIT(DMA->IFCR,8);
	DMA_PfCallBack[DMA_CHANNEL3]();

}

void DMA1_Channel4_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,13))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,13);
	}
	if(GET_BIT(DMA->ISR,14))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,14);
	}
	if(GET_BIT(DMA->ISR,15))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,15);
	}
	/*	Clear CGIF*/
	SET_BIT(DMA->IFCR,12);
	DMA_PfCallBack[DMA_CHANNEL4]();

}

void DMA1_Channel5_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,17))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,17);
	}
	if(GET_BIT(DMA->ISR,18))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,18);
	}
	if(GET_BIT(DMA->ISR,19))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,19);
	}
	/*	Clear CGIF*/
	SET_BIT(DMA->IFCR,16);
	DMA_PfCallBack[DMA_CHANNEL5]();

}

void DMA1_Channel6_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,21))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,21);
	}
	if(GET_BIT(DMA->ISR,22))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,22);
	}
	if(GET_BIT(DMA->ISR,23))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,23);
	}
	/*	Clear CGIF*/
	SET_BIT(DMA->IFCR,20);
	DMA_PfCallBack[DMA_CHANNEL6]();

}

void DMA1_Channel7_IRQHandler(void)
{
	if(GET_BIT(DMA->ISR,25))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,25);
	}
	if(GET_BIT(DMA->ISR,26))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,26);
	}
	if(GET_BIT(DMA->ISR,27))
	{
		/*Remove PIF*/
		SET_BIT(DMA->IFCR,27);
	}
	/*	Clear CGIF*/
	SET_BIT(DMA->IFCR,24);
	DMA_PfCallBack[DMA_CHANNEL7]();

}
