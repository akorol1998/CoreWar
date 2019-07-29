.name       "Batman"
.comment    "This city needs me"

pak: and r2, %4, r1
	ld %5, r15
	ldi %3, %:loop, r15

loop:
        sti r1, %:live, %1
live:
        live %0
        ld %3, r2
        zjmp %:loop
