.name       "Batman"
.comment    "This city needs me"

live:
	and %4, %4, r1
	and %4, %4, r1
pas:	and %4, %4, r1
pool:
	and %4, %4, r1
loop:
        ld %:live, r1
live:
	and %4, %4, r1
live:
        live %0
        ld %0, r2
        zjmp %:loop
