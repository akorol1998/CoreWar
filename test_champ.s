   
      
	  		
 .comment 			 "This city needs me me"
.name    	"Batman"
 


loop:





        sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop
