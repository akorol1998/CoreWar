.name       "Batman"
.comment    "This city needs me"

pak: and -4, %4, r1
	ldi %3, %:loop, r15

loop:
        sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop
